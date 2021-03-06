/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */
#include <aws/common/string.h>
#include <aws/io/private/pem_utils.h>

#include <aws/testing/aws_test_harness.h>

static int s_check_clean_pem_result(
    struct aws_byte_cursor dirty_pem,
    struct aws_byte_cursor expected_clean_pem,
    struct aws_allocator *allocator) {
    struct aws_byte_buf pem_buf;
    ASSERT_SUCCESS(aws_byte_buf_init_copy_from_cursor(&pem_buf, allocator, dirty_pem));
    ASSERT_SUCCESS(aws_sanitize_pem(&pem_buf, allocator));
    ASSERT_TRUE(aws_byte_cursor_eq_byte_buf(&expected_clean_pem, &pem_buf));
    aws_byte_buf_clean_up(&pem_buf);
    return AWS_OP_SUCCESS;
}

static int s_test_pem_sanitize_comments_around_pem_object_removed(struct aws_allocator *allocator, void *ctx) {
    (void)ctx;
    /* comments around pem object will be removed */
    struct aws_byte_cursor dirty_pem = AWS_BYTE_CUR_INIT_FROM_STRING_LITERAL("# comments\r\n"
                                                                             "-----BEGIN CERTIFICATE-----\n"
                                                                             "CERTIFICATES\n"
                                                                             "-----END CERTIFICATE-----\n"
                                                                             "# another comments\r\n"
                                                                             "-----BEGIN CERTIFICATE-----\n"
                                                                             "CERTIFICATES\n"
                                                                             "-----END CERTIFICATE-----\n"
                                                                             "# final comments\r\n");

    struct aws_byte_cursor expected_clean_pem = AWS_BYTE_CUR_INIT_FROM_STRING_LITERAL("-----BEGIN CERTIFICATE-----\n"
                                                                                      "CERTIFICATES\n"
                                                                                      "-----END CERTIFICATE-----\n"
                                                                                      "-----BEGIN CERTIFICATE-----\n"
                                                                                      "CERTIFICATES\n"
                                                                                      "-----END CERTIFICATE-----\n");

    return s_check_clean_pem_result(dirty_pem, expected_clean_pem, allocator);
}

AWS_TEST_CASE(pem_sanitize_comments_around_pem_object_removed, s_test_pem_sanitize_comments_around_pem_object_removed);

static int s_test_pem_sanitize_empty_file_rejected(struct aws_allocator *allocator, void *ctx) {
    (void)ctx;
    /* We don't allow empty files. */
    struct aws_byte_buf pem;
    ASSERT_SUCCESS(aws_byte_buf_init(&pem, allocator, 512));

    ASSERT_ERROR(AWS_ERROR_INVALID_ARGUMENT, aws_sanitize_pem(&pem, allocator));

    aws_byte_buf_clean_up(&pem);
    return AWS_OP_SUCCESS;
}

AWS_TEST_CASE(pem_sanitize_empty_file_rejected, s_test_pem_sanitize_empty_file_rejected)

AWS_TEST_CASE(pem_sanitize_wrong_format_rejected, s_test_pem_sanitize_wrong_format_rejected)
static int s_test_pem_sanitize_wrong_format_rejected(struct aws_allocator *allocator, void *ctx) {
    (void)ctx;
    /* A file with the wrong format will "sanitize" to an empty PEM file, which we do not accept */

    /* This is not a PEM file, it's a DER encoded binary x.509 certificate */
    const uint8_t not_a_pem_src[] = {
        0x30, 0x82, 0x04, 0xD3, 0x30, 0x82, 0x03, 0xBB, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x18, 0xDA, 0xD1,
        0x9E, 0x26, 0x7D, 0xE8, 0xBB, 0x4A, 0x21, 0x58, 0xCD, 0xCC, 0x6B, 0x3B, 0x4A, 0x30, 0x0D, 0x06, 0x09, 0x2A,
        0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x05, 0x05, 0x00, 0x30, 0x81, 0xCA, 0x31, 0x0B, 0x30, 0x09, 0x06,
        0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13,
        0x0E, 0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67, 0x6E, 0x2C, 0x20, 0x49, 0x6E, 0x63, 0x2E, 0x31, 0x1F, 0x30,
        0x1D, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x16, 0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x54,
        0x72, 0x75, 0x73, 0x74, 0x20, 0x4E, 0x65, 0x74, 0x77, 0x6F, 0x72, 0x6B, 0x31, 0x3A, 0x30, 0x38, 0x06, 0x03,
        0x55, 0x04, 0x0B, 0x13, 0x31, 0x28, 0x63, 0x29, 0x20, 0x32, 0x30, 0x30, 0x36, 0x20, 0x56, 0x65, 0x72, 0x69,
        0x53, 0x69, 0x67, 0x6E, 0x2C, 0x20, 0x49, 0x6E, 0x63, 0x2E, 0x20, 0x2D, 0x20, 0x46, 0x6F, 0x72, 0x20, 0x61,
        0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x7A, 0x65, 0x64, 0x20, 0x75, 0x73, 0x65, 0x20, 0x6F, 0x6E, 0x6C, 0x79,
        0x31, 0x45, 0x30, 0x43, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x3C, 0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67,
        0x6E, 0x20, 0x43, 0x6C, 0x61, 0x73, 0x73, 0x20, 0x33, 0x20, 0x50, 0x75, 0x62, 0x6C, 0x69, 0x63, 0x20, 0x50,
        0x72, 0x69, 0x6D, 0x61, 0x72, 0x79, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69,
        0x6F, 0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x20, 0x2D, 0x20, 0x47, 0x35, 0x30,
        0x1E, 0x17, 0x0D, 0x30, 0x36, 0x31, 0x31, 0x30, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5A, 0x17, 0x0D,
        0x33, 0x36, 0x30, 0x37, 0x31, 0x36, 0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5A, 0x30, 0x81, 0xCA, 0x31, 0x0B,
        0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55,
        0x04, 0x0A, 0x13, 0x0E, 0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67, 0x6E, 0x2C, 0x20, 0x49, 0x6E, 0x63, 0x2E,
        0x31, 0x1F, 0x30, 0x1D, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x16, 0x56, 0x65, 0x72, 0x69, 0x53, 0x69, 0x67,
        0x6E, 0x20, 0x54, 0x72, 0x75, 0x73, 0x74, 0x20, 0x4E, 0x65, 0x74, 0x77, 0x6F, 0x72, 0x6B, 0x31, 0x3A, 0x30,
        0x38, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x31, 0x28, 0x63, 0x29, 0x20, 0x32, 0x30, 0x30, 0x36, 0x20, 0x56,
        0x65, 0x72, 0x69, 0x53, 0x69, 0x67, 0x6E, 0x2C, 0x20, 0x49, 0x6E, 0x63, 0x2E, 0x20, 0x2D, 0x20, 0x46, 0x6F,
        0x72, 0x20, 0x61, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x7A, 0x65, 0x64, 0x20, 0x75, 0x73, 0x65, 0x20, 0x6F,
        0x6E, 0x6C, 0x79, 0x31, 0x45, 0x30, 0x43, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x3C, 0x56, 0x65, 0x72, 0x69,
        0x53, 0x69, 0x67, 0x6E, 0x20, 0x43, 0x6C, 0x61, 0x73, 0x73, 0x20, 0x33, 0x20, 0x50, 0x75, 0x62, 0x6C, 0x69,
        0x63, 0x20, 0x50, 0x72, 0x69, 0x6D, 0x61, 0x72, 0x79, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63,
        0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x20, 0x2D, 0x20,
        0x47, 0x35, 0x30, 0x82, 0x01, 0x22, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01,
        0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0F, 0x00, 0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01, 0x00, 0xAF,
        0x24, 0x08, 0x08, 0x29, 0x7A, 0x35, 0x9E, 0x60, 0x0C, 0xAA, 0xE7, 0x4B, 0x3B, 0x4E, 0xDC, 0x7C, 0xBC, 0x3C,
        0x45, 0x1C, 0xBB, 0x2B, 0xE0, 0xFE, 0x29, 0x02, 0xF9, 0x57, 0x08, 0xA3, 0x64, 0x85, 0x15, 0x27, 0xF5, 0xF1,
        0xAD, 0xC8, 0x31, 0x89, 0x5D, 0x22, 0xE8, 0x2A, 0xAA, 0xA6, 0x42, 0xB3, 0x8F, 0xF8, 0xB9, 0x55, 0xB7, 0xB1,
        0xB7, 0x4B, 0xB3, 0xFE, 0x8F, 0x7E, 0x07, 0x57, 0xEC, 0xEF, 0x43, 0xDB, 0x66, 0x62, 0x15, 0x61, 0xCF, 0x60,
        0x0D, 0xA4, 0xD8, 0xDE, 0xF8, 0xE0, 0xC3, 0x62, 0x08, 0x3D, 0x54, 0x13, 0xEB, 0x49, 0xCA, 0x59, 0x54, 0x85,
        0x26, 0xE5, 0x2B, 0x8F, 0x1B, 0x9F, 0xEB, 0xF5, 0xA1, 0x91, 0xC2, 0x33, 0x49, 0xD8, 0x43, 0x63, 0x6A, 0x52,
        0x4B, 0xD2, 0x8F, 0xE8, 0x70, 0x51, 0x4D, 0xD1, 0x89, 0x69, 0x7B, 0xC7, 0x70, 0xF6, 0xB3, 0xDC, 0x12, 0x74,
        0xDB, 0x7B, 0x5D, 0x4B, 0x56, 0xD3, 0x96, 0xBF, 0x15, 0x77, 0xA1, 0xB0, 0xF4, 0xA2, 0x25, 0xF2, 0xAF, 0x1C,
        0x92, 0x67, 0x18, 0xE5, 0xF4, 0x06, 0x04, 0xEF, 0x90, 0xB9, 0xE4, 0x00, 0xE4, 0xDD, 0x3A, 0xB5, 0x19, 0xFF,
        0x02, 0xBA, 0xF4, 0x3C, 0xEE, 0xE0, 0x8B, 0xEB, 0x37, 0x8B, 0xEC, 0xF4, 0xD7, 0xAC, 0xF2, 0xF6, 0xF0, 0x3D,
        0xAF, 0xDD, 0x75, 0x91, 0x33, 0x19, 0x1D, 0x1C, 0x40, 0xCB, 0x74, 0x24, 0x19, 0x21, 0x93, 0xD9, 0x14, 0xFE,
        0xAC, 0x2A, 0x52, 0xC7, 0x8F, 0xD5, 0x04, 0x49, 0xE4, 0x8D, 0x63, 0x47, 0x88, 0x3C, 0x69, 0x83, 0xCB, 0xFE,
        0x47, 0xBD, 0x2B, 0x7E, 0x4F, 0xC5, 0x95, 0xAE, 0x0E, 0x9D, 0xD4, 0xD1, 0x43, 0xC0, 0x67, 0x73, 0xE3, 0x14,
        0x08, 0x7E, 0xE5, 0x3F, 0x9F, 0x73, 0xB8, 0x33, 0x0A, 0xCF, 0x5D, 0x3F, 0x34, 0x87, 0x96, 0x8A, 0xEE, 0x53,
        0xE8, 0x25, 0x15, 0x02, 0x03, 0x01, 0x00, 0x01, 0xA3, 0x81, 0xB2, 0x30, 0x81, 0xAF, 0x30, 0x0F, 0x06, 0x03,
        0x55, 0x1D, 0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
        0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03, 0x02, 0x01, 0x06, 0x30, 0x6D, 0x06, 0x08, 0x2B, 0x06, 0x01,
        0x05, 0x05, 0x07, 0x01, 0x0C, 0x04, 0x61, 0x30, 0x5F, 0xA1, 0x5D, 0xA0, 0x5B, 0x30, 0x59, 0x30, 0x57, 0x30,
        0x55, 0x16, 0x09, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x2F, 0x67, 0x69, 0x66, 0x30, 0x21, 0x30, 0x1F, 0x30, 0x07,
        0x06, 0x05, 0x2B, 0x0E, 0x03, 0x02, 0x1A, 0x04, 0x14, 0x8F, 0xE5, 0xD3, 0x1A, 0x86, 0xAC, 0x8D, 0x8E, 0x6B,
        0xC3, 0xCF, 0x80, 0x6A, 0xD4, 0x48, 0x18, 0x2C, 0x7B, 0x19, 0x2E, 0x30, 0x25, 0x16, 0x23, 0x68, 0x74, 0x74,
        0x70, 0x3A, 0x2F, 0x2F, 0x6C, 0x6F, 0x67, 0x6F, 0x2E, 0x76, 0x65, 0x72, 0x69, 0x73, 0x69, 0x67, 0x6E, 0x2E,
        0x63, 0x6F, 0x6D, 0x2F, 0x76, 0x73, 0x6C, 0x6F, 0x67, 0x6F, 0x2E, 0x67, 0x69, 0x66, 0x30, 0x1D, 0x06, 0x03,
        0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0x7F, 0xD3, 0x65, 0xA7, 0xC2, 0xDD, 0xEC, 0xBB, 0xF0, 0x30, 0x09,
        0xF3, 0x43, 0x39, 0xFA, 0x02, 0xAF, 0x33, 0x31, 0x33, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
        0x0D, 0x01, 0x01, 0x05, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x93, 0x24, 0x4A, 0x30, 0x5F, 0x62, 0xCF,
        0xD8, 0x1A, 0x98, 0x2F, 0x3D, 0xEA, 0xDC, 0x99, 0x2D, 0xBD, 0x77, 0xF6, 0xA5, 0x79, 0x22, 0x38, 0xEC, 0xC4,
        0xA7, 0xA0, 0x78, 0x12, 0xAD, 0x62, 0x0E, 0x45, 0x70, 0x64, 0xC5, 0xE7, 0x97, 0x66, 0x2D, 0x98, 0x09, 0x7E,
        0x5F, 0xAF, 0xD6, 0xCC, 0x28, 0x65, 0xF2, 0x01, 0xAA, 0x08, 0x1A, 0x47, 0xDE, 0xF9, 0xF9, 0x7C, 0x92, 0x5A,
        0x08, 0x69, 0x20, 0x0D, 0xD9, 0x3E, 0x6D, 0x6E, 0x3C, 0x0D, 0x6E, 0xD8, 0xE6, 0x06, 0x91, 0x40, 0x18, 0xB9,
        0xF8, 0xC1, 0xED, 0xDF, 0xDB, 0x41, 0xAA, 0xE0, 0x96, 0x20, 0xC9, 0xCD, 0x64, 0x15, 0x38, 0x81, 0xC9, 0x94,
        0xEE, 0xA2, 0x84, 0x29, 0x0B, 0x13, 0x6F, 0x8E, 0xDB, 0x0C, 0xDD, 0x25, 0x02, 0xDB, 0xA4, 0x8B, 0x19, 0x44,
        0xD2, 0x41, 0x7A, 0x05, 0x69, 0x4A, 0x58, 0x4F, 0x60, 0xCA, 0x7E, 0x82, 0x6A, 0x0B, 0x02, 0xAA, 0x25, 0x17,
        0x39, 0xB5, 0xDB, 0x7F, 0xE7, 0x84, 0x65, 0x2A, 0x95, 0x8A, 0xBD, 0x86, 0xDE, 0x5E, 0x81, 0x16, 0x83, 0x2D,
        0x10, 0xCC, 0xDE, 0xFD, 0xA8, 0x82, 0x2A, 0x6D, 0x28, 0x1F, 0x0D, 0x0B, 0xC4, 0xE5, 0xE7, 0x1A, 0x26, 0x19,
        0xE1, 0xF4, 0x11, 0x6F, 0x10, 0xB5, 0x95, 0xFC, 0xE7, 0x42, 0x05, 0x32, 0xDB, 0xCE, 0x9D, 0x51, 0x5E, 0x28,
        0xB6, 0x9E, 0x85, 0xD3, 0x5B, 0xEF, 0xA5, 0x7D, 0x45, 0x40, 0x72, 0x8E, 0xB7, 0x0E, 0x6B, 0x0E, 0x06, 0xFB,
        0x33, 0x35, 0x48, 0x71, 0xB8, 0x9D, 0x27, 0x8B, 0xC4, 0x65, 0x5F, 0x0D, 0x86, 0x76, 0x9C, 0x44, 0x7A, 0xF6,
        0x95, 0x5C, 0xF6, 0x5D, 0x32, 0x08, 0x33, 0xA4, 0x54, 0xB6, 0x18, 0x3F, 0x68, 0x5C, 0xF2, 0x42, 0x4A, 0x85,
        0x38, 0x54, 0x83, 0x5F, 0xD1, 0xE8, 0x2C, 0xF2, 0xAC, 0x11, 0xD6, 0xA8, 0xED, 0x63, 0x6A};
    struct aws_byte_cursor not_a_pem_cursor = aws_byte_cursor_from_array(not_a_pem_src, sizeof(not_a_pem_src));
    struct aws_byte_buf not_a_pem;
    ASSERT_SUCCESS(aws_byte_buf_init_copy_from_cursor(&not_a_pem, allocator, not_a_pem_cursor));

    ASSERT_ERROR(AWS_ERROR_INVALID_ARGUMENT, aws_sanitize_pem(&not_a_pem, allocator));

    aws_byte_buf_clean_up(&not_a_pem);
    return AWS_OP_SUCCESS;
}
