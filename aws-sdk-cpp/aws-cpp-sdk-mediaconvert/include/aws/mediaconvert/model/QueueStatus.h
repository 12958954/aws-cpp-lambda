/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/mediaconvert/MediaConvert_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace MediaConvert
{
namespace Model
{
  enum class QueueStatus
  {
    NOT_SET,
    ACTIVE,
    PAUSED
  };

namespace QueueStatusMapper
{
AWS_MEDIACONVERT_API QueueStatus GetQueueStatusForName(const Aws::String& name);

AWS_MEDIACONVERT_API Aws::String GetNameForQueueStatus(QueueStatus value);
} // namespace QueueStatusMapper
} // namespace Model
} // namespace MediaConvert
} // namespace Aws
