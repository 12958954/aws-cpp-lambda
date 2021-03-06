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
  enum class H265SlowPal
  {
    NOT_SET,
    DISABLED,
    ENABLED
  };

namespace H265SlowPalMapper
{
AWS_MEDIACONVERT_API H265SlowPal GetH265SlowPalForName(const Aws::String& name);

AWS_MEDIACONVERT_API Aws::String GetNameForH265SlowPal(H265SlowPal value);
} // namespace H265SlowPalMapper
} // namespace Model
} // namespace MediaConvert
} // namespace Aws
