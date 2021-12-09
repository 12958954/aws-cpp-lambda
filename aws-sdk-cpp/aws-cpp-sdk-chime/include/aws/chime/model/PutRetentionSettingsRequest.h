﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/chime/Chime_EXPORTS.h>
#include <aws/chime/ChimeRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/chime/model/RetentionSettings.h>
#include <utility>

namespace Aws
{
namespace Chime
{
namespace Model
{

  /**
   */
  class AWS_CHIME_API PutRetentionSettingsRequest : public ChimeRequest
  {
  public:
    PutRetentionSettingsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "PutRetentionSettings"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline const Aws::String& GetAccountId() const{ return m_accountId; }

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline bool AccountIdHasBeenSet() const { return m_accountIdHasBeenSet; }

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline void SetAccountId(const Aws::String& value) { m_accountIdHasBeenSet = true; m_accountId = value; }

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline void SetAccountId(Aws::String&& value) { m_accountIdHasBeenSet = true; m_accountId = std::move(value); }

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline void SetAccountId(const char* value) { m_accountIdHasBeenSet = true; m_accountId.assign(value); }

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline PutRetentionSettingsRequest& WithAccountId(const Aws::String& value) { SetAccountId(value); return *this;}

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline PutRetentionSettingsRequest& WithAccountId(Aws::String&& value) { SetAccountId(std::move(value)); return *this;}

    /**
     * <p>The Amazon Chime account ID.</p>
     */
    inline PutRetentionSettingsRequest& WithAccountId(const char* value) { SetAccountId(value); return *this;}


    /**
     * <p>The retention settings.</p>
     */
    inline const RetentionSettings& GetRetentionSettings() const{ return m_retentionSettings; }

    /**
     * <p>The retention settings.</p>
     */
    inline bool RetentionSettingsHasBeenSet() const { return m_retentionSettingsHasBeenSet; }

    /**
     * <p>The retention settings.</p>
     */
    inline void SetRetentionSettings(const RetentionSettings& value) { m_retentionSettingsHasBeenSet = true; m_retentionSettings = value; }

    /**
     * <p>The retention settings.</p>
     */
    inline void SetRetentionSettings(RetentionSettings&& value) { m_retentionSettingsHasBeenSet = true; m_retentionSettings = std::move(value); }

    /**
     * <p>The retention settings.</p>
     */
    inline PutRetentionSettingsRequest& WithRetentionSettings(const RetentionSettings& value) { SetRetentionSettings(value); return *this;}

    /**
     * <p>The retention settings.</p>
     */
    inline PutRetentionSettingsRequest& WithRetentionSettings(RetentionSettings&& value) { SetRetentionSettings(std::move(value)); return *this;}

  private:

    Aws::String m_accountId;
    bool m_accountIdHasBeenSet;

    RetentionSettings m_retentionSettings;
    bool m_retentionSettingsHasBeenSet;
  };

} // namespace Model
} // namespace Chime
} // namespace Aws