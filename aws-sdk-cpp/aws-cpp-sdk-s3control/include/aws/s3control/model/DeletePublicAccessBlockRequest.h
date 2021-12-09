﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3control/S3Control_EXPORTS.h>
#include <aws/s3control/S3ControlRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace S3Control
{
namespace Model
{

  /**
   */
  class AWS_S3CONTROL_API DeletePublicAccessBlockRequest : public S3ControlRequest
  {
  public:
    DeletePublicAccessBlockRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DeletePublicAccessBlock"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline const Aws::String& GetAccountId() const{ return m_accountId; }

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline bool AccountIdHasBeenSet() const { return m_accountIdHasBeenSet; }

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline void SetAccountId(const Aws::String& value) { m_accountIdHasBeenSet = true; m_accountId = value; }

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline void SetAccountId(Aws::String&& value) { m_accountIdHasBeenSet = true; m_accountId = std::move(value); }

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline void SetAccountId(const char* value) { m_accountIdHasBeenSet = true; m_accountId.assign(value); }

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline DeletePublicAccessBlockRequest& WithAccountId(const Aws::String& value) { SetAccountId(value); return *this;}

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline DeletePublicAccessBlockRequest& WithAccountId(Aws::String&& value) { SetAccountId(std::move(value)); return *this;}

    /**
     * <p>The account ID for the account whose <code>PublicAccessBlock</code>
     * configuration you want to remove.</p>
     */
    inline DeletePublicAccessBlockRequest& WithAccountId(const char* value) { SetAccountId(value); return *this;}

  private:

    Aws::String m_accountId;
    bool m_accountIdHasBeenSet;
  };

} // namespace Model
} // namespace S3Control
} // namespace Aws
