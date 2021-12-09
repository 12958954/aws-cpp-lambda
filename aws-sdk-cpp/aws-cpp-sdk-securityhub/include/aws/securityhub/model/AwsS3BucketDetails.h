﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/securityhub/SecurityHub_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/securityhub/model/AwsS3BucketServerSideEncryptionConfiguration.h>
#include <aws/securityhub/model/AwsS3BucketBucketLifecycleConfigurationDetails.h>
#include <aws/securityhub/model/AwsS3AccountPublicAccessBlockDetails.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace SecurityHub
{
namespace Model
{

  /**
   * <p>The details of an Amazon S3 bucket.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/securityhub-2018-10-26/AwsS3BucketDetails">AWS
   * API Reference</a></p>
   */
  class AWS_SECURITYHUB_API AwsS3BucketDetails
  {
  public:
    AwsS3BucketDetails();
    AwsS3BucketDetails(Aws::Utils::Json::JsonView jsonValue);
    AwsS3BucketDetails& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline const Aws::String& GetOwnerId() const{ return m_ownerId; }

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline bool OwnerIdHasBeenSet() const { return m_ownerIdHasBeenSet; }

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline void SetOwnerId(const Aws::String& value) { m_ownerIdHasBeenSet = true; m_ownerId = value; }

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline void SetOwnerId(Aws::String&& value) { m_ownerIdHasBeenSet = true; m_ownerId = std::move(value); }

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline void SetOwnerId(const char* value) { m_ownerIdHasBeenSet = true; m_ownerId.assign(value); }

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithOwnerId(const Aws::String& value) { SetOwnerId(value); return *this;}

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithOwnerId(Aws::String&& value) { SetOwnerId(std::move(value)); return *this;}

    /**
     * <p>The canonical user ID of the owner of the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithOwnerId(const char* value) { SetOwnerId(value); return *this;}


    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline const Aws::String& GetOwnerName() const{ return m_ownerName; }

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline bool OwnerNameHasBeenSet() const { return m_ownerNameHasBeenSet; }

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline void SetOwnerName(const Aws::String& value) { m_ownerNameHasBeenSet = true; m_ownerName = value; }

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline void SetOwnerName(Aws::String&& value) { m_ownerNameHasBeenSet = true; m_ownerName = std::move(value); }

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline void SetOwnerName(const char* value) { m_ownerNameHasBeenSet = true; m_ownerName.assign(value); }

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithOwnerName(const Aws::String& value) { SetOwnerName(value); return *this;}

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithOwnerName(Aws::String&& value) { SetOwnerName(std::move(value)); return *this;}

    /**
     * <p>The display name of the owner of the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithOwnerName(const char* value) { SetOwnerName(value); return *this;}


    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline const Aws::String& GetCreatedAt() const{ return m_createdAt; }

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline bool CreatedAtHasBeenSet() const { return m_createdAtHasBeenSet; }

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline void SetCreatedAt(const Aws::String& value) { m_createdAtHasBeenSet = true; m_createdAt = value; }

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline void SetCreatedAt(Aws::String&& value) { m_createdAtHasBeenSet = true; m_createdAt = std::move(value); }

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline void SetCreatedAt(const char* value) { m_createdAtHasBeenSet = true; m_createdAt.assign(value); }

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline AwsS3BucketDetails& WithCreatedAt(const Aws::String& value) { SetCreatedAt(value); return *this;}

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline AwsS3BucketDetails& WithCreatedAt(Aws::String&& value) { SetCreatedAt(std::move(value)); return *this;}

    /**
     * <p>Indicates when the S3 bucket was created.</p> <p>Uses the
     * <code>date-time</code> format specified in <a
     * href="https://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 section 5.6,
     * Internet Date/Time Format</a>. The value cannot contain spaces. For example,
     * <code>2020-03-22T13:22:13.933Z</code>.</p>
     */
    inline AwsS3BucketDetails& WithCreatedAt(const char* value) { SetCreatedAt(value); return *this;}


    /**
     * <p>The encryption rules that are applied to the S3 bucket.</p>
     */
    inline const AwsS3BucketServerSideEncryptionConfiguration& GetServerSideEncryptionConfiguration() const{ return m_serverSideEncryptionConfiguration; }

    /**
     * <p>The encryption rules that are applied to the S3 bucket.</p>
     */
    inline bool ServerSideEncryptionConfigurationHasBeenSet() const { return m_serverSideEncryptionConfigurationHasBeenSet; }

    /**
     * <p>The encryption rules that are applied to the S3 bucket.</p>
     */
    inline void SetServerSideEncryptionConfiguration(const AwsS3BucketServerSideEncryptionConfiguration& value) { m_serverSideEncryptionConfigurationHasBeenSet = true; m_serverSideEncryptionConfiguration = value; }

    /**
     * <p>The encryption rules that are applied to the S3 bucket.</p>
     */
    inline void SetServerSideEncryptionConfiguration(AwsS3BucketServerSideEncryptionConfiguration&& value) { m_serverSideEncryptionConfigurationHasBeenSet = true; m_serverSideEncryptionConfiguration = std::move(value); }

    /**
     * <p>The encryption rules that are applied to the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithServerSideEncryptionConfiguration(const AwsS3BucketServerSideEncryptionConfiguration& value) { SetServerSideEncryptionConfiguration(value); return *this;}

    /**
     * <p>The encryption rules that are applied to the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithServerSideEncryptionConfiguration(AwsS3BucketServerSideEncryptionConfiguration&& value) { SetServerSideEncryptionConfiguration(std::move(value)); return *this;}


    /**
     * <p>The lifecycle configuration for objects in the S3 bucket.</p>
     */
    inline const AwsS3BucketBucketLifecycleConfigurationDetails& GetBucketLifecycleConfiguration() const{ return m_bucketLifecycleConfiguration; }

    /**
     * <p>The lifecycle configuration for objects in the S3 bucket.</p>
     */
    inline bool BucketLifecycleConfigurationHasBeenSet() const { return m_bucketLifecycleConfigurationHasBeenSet; }

    /**
     * <p>The lifecycle configuration for objects in the S3 bucket.</p>
     */
    inline void SetBucketLifecycleConfiguration(const AwsS3BucketBucketLifecycleConfigurationDetails& value) { m_bucketLifecycleConfigurationHasBeenSet = true; m_bucketLifecycleConfiguration = value; }

    /**
     * <p>The lifecycle configuration for objects in the S3 bucket.</p>
     */
    inline void SetBucketLifecycleConfiguration(AwsS3BucketBucketLifecycleConfigurationDetails&& value) { m_bucketLifecycleConfigurationHasBeenSet = true; m_bucketLifecycleConfiguration = std::move(value); }

    /**
     * <p>The lifecycle configuration for objects in the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithBucketLifecycleConfiguration(const AwsS3BucketBucketLifecycleConfigurationDetails& value) { SetBucketLifecycleConfiguration(value); return *this;}

    /**
     * <p>The lifecycle configuration for objects in the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithBucketLifecycleConfiguration(AwsS3BucketBucketLifecycleConfigurationDetails&& value) { SetBucketLifecycleConfiguration(std::move(value)); return *this;}


    /**
     * <p>Provides information about the Amazon S3 Public Access Block configuration
     * for the S3 bucket.</p>
     */
    inline const AwsS3AccountPublicAccessBlockDetails& GetPublicAccessBlockConfiguration() const{ return m_publicAccessBlockConfiguration; }

    /**
     * <p>Provides information about the Amazon S3 Public Access Block configuration
     * for the S3 bucket.</p>
     */
    inline bool PublicAccessBlockConfigurationHasBeenSet() const { return m_publicAccessBlockConfigurationHasBeenSet; }

    /**
     * <p>Provides information about the Amazon S3 Public Access Block configuration
     * for the S3 bucket.</p>
     */
    inline void SetPublicAccessBlockConfiguration(const AwsS3AccountPublicAccessBlockDetails& value) { m_publicAccessBlockConfigurationHasBeenSet = true; m_publicAccessBlockConfiguration = value; }

    /**
     * <p>Provides information about the Amazon S3 Public Access Block configuration
     * for the S3 bucket.</p>
     */
    inline void SetPublicAccessBlockConfiguration(AwsS3AccountPublicAccessBlockDetails&& value) { m_publicAccessBlockConfigurationHasBeenSet = true; m_publicAccessBlockConfiguration = std::move(value); }

    /**
     * <p>Provides information about the Amazon S3 Public Access Block configuration
     * for the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithPublicAccessBlockConfiguration(const AwsS3AccountPublicAccessBlockDetails& value) { SetPublicAccessBlockConfiguration(value); return *this;}

    /**
     * <p>Provides information about the Amazon S3 Public Access Block configuration
     * for the S3 bucket.</p>
     */
    inline AwsS3BucketDetails& WithPublicAccessBlockConfiguration(AwsS3AccountPublicAccessBlockDetails&& value) { SetPublicAccessBlockConfiguration(std::move(value)); return *this;}

  private:

    Aws::String m_ownerId;
    bool m_ownerIdHasBeenSet;

    Aws::String m_ownerName;
    bool m_ownerNameHasBeenSet;

    Aws::String m_createdAt;
    bool m_createdAtHasBeenSet;

    AwsS3BucketServerSideEncryptionConfiguration m_serverSideEncryptionConfiguration;
    bool m_serverSideEncryptionConfigurationHasBeenSet;

    AwsS3BucketBucketLifecycleConfigurationDetails m_bucketLifecycleConfiguration;
    bool m_bucketLifecycleConfigurationHasBeenSet;

    AwsS3AccountPublicAccessBlockDetails m_publicAccessBlockConfiguration;
    bool m_publicAccessBlockConfigurationHasBeenSet;
  };

} // namespace Model
} // namespace SecurityHub
} // namespace Aws
