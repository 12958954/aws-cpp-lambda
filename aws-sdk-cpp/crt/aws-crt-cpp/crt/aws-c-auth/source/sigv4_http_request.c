/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/auth/private/sigv4_http_request.h>

#include <aws/auth/credentials.h>
#include <aws/auth/signable.h>
#include <aws/auth/signing.h>
#include <aws/auth/signing_result.h>
#include <aws/common/condition_variable.h>
#include <aws/common/mutex.h>
#include <aws/common/string.h>
#include <aws/http/request_response.h>
#include <aws/io/uri.h>

#if defined(_MSC_VER)
#    pragma warning(disable : 4204)
#endif /* _MSC_VER */

#define DEFAULT_QUERY_PARAM_COUNT 10

/*
 * Uses the signing result to rebuild the request's URI.  If the signing was not done via
 * query params, then this ends up doing nothing.
 */
static int s_build_request_uri(
    struct aws_allocator *allocator,
    struct aws_http_message *request,
    const struct aws_signing_result *signing_result) {

    /* first let's see if we need to do anything at all */
    struct aws_array_list *result_param_list = NULL;
    aws_signing_result_get_property_list(
        signing_result, g_aws_http_query_params_property_list_name, &result_param_list);
    if (result_param_list == NULL) {
        return AWS_OP_SUCCESS;
    }

    /*
     * There are query params to apply.  Use the following algorithm:
     *
     * (1) Take the old uri and parse it into a URI structure
     * (2) Make a new URI builder and add the old URI's components to it
     * (3) Add the signing query params to the builder
     * (4) Use the builder to make a new URI
     */
    int result = AWS_OP_ERR;
    size_t signed_query_param_count = aws_array_list_length(result_param_list);

    struct aws_uri old_uri;
    AWS_ZERO_STRUCT(old_uri);

    struct aws_uri new_uri;
    AWS_ZERO_STRUCT(new_uri);

    struct aws_uri_builder_options new_uri_builder;
    AWS_ZERO_STRUCT(new_uri_builder);

    struct aws_array_list query_params;
    AWS_ZERO_STRUCT(query_params);

    struct aws_byte_cursor old_path;
    aws_http_message_get_request_path(request, &old_path);

    /* start with the old uri and parse it */
    if (aws_uri_init_parse(&old_uri, allocator, &old_path)) {
        goto done;
    }

    /* pull out the old query params */
    if (aws_array_list_init_dynamic(
            &query_params, allocator, DEFAULT_QUERY_PARAM_COUNT, sizeof(struct aws_uri_param))) {
        goto done;
    }

    if (aws_uri_query_string_params(&old_uri, &query_params)) {
        goto done;
    }

    /* initialize a builder for the new uri matching the old uri */
    new_uri_builder.host_name = old_uri.host_name;
    new_uri_builder.path = old_uri.path;
    new_uri_builder.port = old_uri.port;
    new_uri_builder.scheme = old_uri.scheme;
    new_uri_builder.query_params = &query_params;

    /* and now add any signing query params */
    for (size_t i = 0; i < signed_query_param_count; ++i) {
        struct aws_signing_result_property source_param;
        if (aws_array_list_get_at(result_param_list, &source_param, i)) {
            goto done;
        }

        struct aws_uri_param signed_param;
        signed_param.key = aws_byte_cursor_from_string(source_param.name);
        signed_param.value = aws_byte_cursor_from_string(source_param.value);

        aws_array_list_push_back(&query_params, &signed_param);
    }

    /* create the new uri */
    if (aws_uri_init_from_builder_options(&new_uri, allocator, &new_uri_builder)) {
        goto done;
    }

    /* copy the full string */
    struct aws_byte_cursor new_uri_cursor = aws_byte_cursor_from_buf(&new_uri.uri_str);
    if (aws_http_message_set_request_path(request, new_uri_cursor)) {
        goto done;
    }

    result = AWS_OP_SUCCESS;

done:

    aws_array_list_clean_up(&query_params);

    aws_uri_clean_up(&new_uri);
    aws_uri_clean_up(&old_uri);

    return result;
}

/*
 * Takes a mutable http request and adds all the additional query params and/or headers generated by the
 * signing process.
 */
int aws_apply_signing_result_to_http_request(
    struct aws_http_message *request,
    struct aws_allocator *allocator,
    const struct aws_signing_result *result) {

    /* uri/query params */
    if (s_build_request_uri(allocator, request, result)) {
        return AWS_OP_ERR;
    }

    /* headers */
    size_t signing_header_count = 0;
    struct aws_array_list *result_header_list = NULL;
    aws_signing_result_get_property_list(result, g_aws_http_headers_property_list_name, &result_header_list);
    if (result_header_list != NULL) {
        signing_header_count = aws_array_list_length(result_header_list);
    }

    for (size_t i = 0; i < signing_header_count; ++i) {
        struct aws_signing_result_property source_header;
        AWS_ZERO_STRUCT(source_header);

        if (aws_array_list_get_at(result_header_list, &source_header, i)) {
            return AWS_OP_ERR;
        }

        if (source_header.name == NULL || source_header.value == NULL) {
            return AWS_OP_ERR;
        }

        struct aws_http_header dest_header = {
            .name = aws_byte_cursor_from_string(source_header.name),
            .value = aws_byte_cursor_from_string(source_header.value),
        };
        aws_http_message_add_header(request, dest_header);
    }

    return AWS_OP_SUCCESS;
}

/*
 * This is a simple aws_signable wrapper implementation for the aws_http_message struct
 */
struct aws_signable_http_request_impl {
    struct aws_http_message *request;
    struct aws_array_list headers;
};

static int s_aws_signable_http_request_get_property(
    const struct aws_signable *signable,
    const struct aws_string *name,
    struct aws_byte_cursor *out_value) {

    struct aws_signable_http_request_impl *impl = signable->impl;

    AWS_ZERO_STRUCT(*out_value);

    /*
     * uri and method can be queried directly from the wrapper request
     */
    if (aws_string_eq(name, g_aws_http_uri_property_name)) {
        aws_http_message_get_request_path(impl->request, out_value);
    } else if (aws_string_eq(name, g_aws_http_method_property_name)) {
        aws_http_message_get_request_method(impl->request, out_value);
    } else {
        return AWS_OP_ERR;
    }

    return AWS_OP_SUCCESS;
}

static int s_aws_signable_http_request_get_property_list(
    const struct aws_signable *signable,
    const struct aws_string *name,
    struct aws_array_list **out_list) {

    struct aws_signable_http_request_impl *impl = signable->impl;

    *out_list = NULL;

    if (aws_string_eq(name, g_aws_http_headers_property_list_name)) {
        *out_list = &impl->headers;
    } else {
        return AWS_OP_ERR;
    }

    return AWS_OP_SUCCESS;
}

static int s_aws_signable_http_request_get_payload_stream(
    const struct aws_signable *signable,
    struct aws_input_stream **out_input_stream) {

    struct aws_signable_http_request_impl *impl = signable->impl;
    *out_input_stream = aws_http_message_get_body_stream(impl->request);

    return AWS_OP_SUCCESS;
}

static void s_aws_signable_http_request_destroy(struct aws_signable *signable) {
    if (signable == NULL) {
        return;
    }

    struct aws_signable_http_request_impl *impl = signable->impl;
    if (impl == NULL) {
        return;
    }

    aws_array_list_clean_up(&impl->headers);
    aws_mem_release(signable->allocator, signable);
}

static struct aws_signable_vtable s_signable_http_request_vtable = {
    .get_property = s_aws_signable_http_request_get_property,
    .get_property_list = s_aws_signable_http_request_get_property_list,
    .get_payload_stream = s_aws_signable_http_request_get_payload_stream,
    .destroy = s_aws_signable_http_request_destroy,
};

struct aws_signable *aws_signable_new_http_request(struct aws_allocator *allocator, struct aws_http_message *request) {

    struct aws_signable *signable = NULL;
    struct aws_signable_http_request_impl *impl = NULL;
    aws_mem_acquire_many(
        allocator, 2, &signable, sizeof(struct aws_signable), &impl, sizeof(struct aws_signable_http_request_impl));

    if (signable == NULL || impl == NULL) {
        return NULL;
    }

    AWS_ZERO_STRUCT(*signable);
    AWS_ZERO_STRUCT(*impl);

    signable->allocator = allocator;
    signable->vtable = &s_signable_http_request_vtable;
    signable->impl = impl;

    /*
     * Copy the headers since they're not different types
     */
    size_t header_count = aws_http_message_get_header_count(request);
    if (aws_array_list_init_dynamic(
            &impl->headers, allocator, header_count, sizeof(struct aws_signable_property_list_pair))) {
        goto on_error;
    }

    for (size_t i = 0; i < header_count; ++i) {
        struct aws_http_header header;
        aws_http_message_get_header(request, &header, i);

        struct aws_signable_property_list_pair property = {.name = header.name, .value = header.value};
        aws_array_list_push_back(&impl->headers, &property);
    }

    impl->request = request;

    return signable;

on_error:

    aws_signable_destroy(signable);

    return NULL;
}

/*
 * This is a simple aws_signable wrapper implementation for an s3 chunk
 */
struct aws_signable_chunk_impl {
    struct aws_input_stream *chunk_data;
    struct aws_string *previous_signature;
};

static int s_aws_signable_chunk_get_property(
    const struct aws_signable *signable,
    const struct aws_string *name,
    struct aws_byte_cursor *out_value) {

    struct aws_signable_chunk_impl *impl = signable->impl;

    AWS_ZERO_STRUCT(*out_value);

    /*
     * uri and method can be queried directly from the wrapper request
     */
    if (aws_string_eq(name, g_aws_previous_signature_property_name)) {
        *out_value = aws_byte_cursor_from_string(impl->previous_signature);
    } else {
        return AWS_OP_ERR;
    }

    return AWS_OP_SUCCESS;
}

static int s_aws_signable_chunk_get_property_list(
    const struct aws_signable *signable,
    const struct aws_string *name,
    struct aws_array_list **out_list) {
    (void)signable;
    (void)name;
    (void)out_list;

    return AWS_OP_ERR;
}

static int s_aws_signable_chunk_get_payload_stream(
    const struct aws_signable *signable,
    struct aws_input_stream **out_input_stream) {

    struct aws_signable_chunk_impl *impl = signable->impl;
    *out_input_stream = impl->chunk_data;

    return AWS_OP_SUCCESS;
}

static void s_aws_signable_chunk_destroy(struct aws_signable *signable) {
    if (signable == NULL) {
        return;
    }

    struct aws_signable_chunk_impl *impl = signable->impl;
    if (impl == NULL) {
        return;
    }

    aws_string_destroy(impl->previous_signature);

    aws_mem_release(signable->allocator, signable);
}

static struct aws_signable_vtable s_signable_chunk_vtable = {
    .get_property = s_aws_signable_chunk_get_property,
    .get_property_list = s_aws_signable_chunk_get_property_list,
    .get_payload_stream = s_aws_signable_chunk_get_payload_stream,
    .destroy = s_aws_signable_chunk_destroy,
};

struct aws_signable *aws_signable_new_chunk(
    struct aws_allocator *allocator,
    struct aws_input_stream *chunk_data,
    struct aws_byte_cursor previous_signature) {

    struct aws_signable *signable = NULL;
    struct aws_signable_chunk_impl *impl = NULL;
    aws_mem_acquire_many(
        allocator, 2, &signable, sizeof(struct aws_signable), &impl, sizeof(struct aws_signable_chunk_impl));

    if (signable == NULL || impl == NULL) {
        return NULL;
    }

    AWS_ZERO_STRUCT(*signable);
    AWS_ZERO_STRUCT(*impl);

    signable->allocator = allocator;
    signable->vtable = &s_signable_chunk_vtable;
    signable->impl = impl;

    impl->chunk_data = chunk_data;
    impl->previous_signature = aws_string_new_from_array(allocator, previous_signature.ptr, previous_signature.len);
    if (impl->previous_signature == NULL) {
        goto on_error;
    }

    return signable;

on_error:

    aws_signable_destroy(signable);

    return NULL;
}
