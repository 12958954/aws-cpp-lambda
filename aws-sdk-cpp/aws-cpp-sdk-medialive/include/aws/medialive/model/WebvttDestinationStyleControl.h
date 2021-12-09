﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/medialive/MediaLive_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace MediaLive
{
namespace Model
{
  enum class WebvttDestinationStyleControl
  {
    NOT_SET,
    NO_STYLE_DATA,
    PASSTHROUGH
  };

namespace WebvttDestinationStyleControlMapper
{
AWS_MEDIALIVE_API WebvttDestinationStyleControl GetWebvttDestinationStyleControlForName(const Aws::String& name);

AWS_MEDIALIVE_API Aws::String GetNameForWebvttDestinationStyleControl(WebvttDestinationStyleControl value);
} // namespace WebvttDestinationStyleControlMapper
} // namespace Model
} // namespace MediaLive
} // namespace Aws
