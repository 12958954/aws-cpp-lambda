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
  enum class AuthenticationScheme
  {
    NOT_SET,
    AKAMAI,
    COMMON
  };

namespace AuthenticationSchemeMapper
{
AWS_MEDIALIVE_API AuthenticationScheme GetAuthenticationSchemeForName(const Aws::String& name);

AWS_MEDIALIVE_API Aws::String GetNameForAuthenticationScheme(AuthenticationScheme value);
} // namespace AuthenticationSchemeMapper
} // namespace Model
} // namespace MediaLive
} // namespace Aws
