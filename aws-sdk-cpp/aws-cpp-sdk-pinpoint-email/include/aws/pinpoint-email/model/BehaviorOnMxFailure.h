/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint-email/PinpointEmail_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace PinpointEmail
{
namespace Model
{
  enum class BehaviorOnMxFailure
  {
    NOT_SET,
    USE_DEFAULT_VALUE,
    REJECT_MESSAGE
  };

namespace BehaviorOnMxFailureMapper
{
AWS_PINPOINTEMAIL_API BehaviorOnMxFailure GetBehaviorOnMxFailureForName(const Aws::String& name);

AWS_PINPOINTEMAIL_API Aws::String GetNameForBehaviorOnMxFailure(BehaviorOnMxFailure value);
} // namespace BehaviorOnMxFailureMapper
} // namespace Model
} // namespace PinpointEmail
} // namespace Aws
