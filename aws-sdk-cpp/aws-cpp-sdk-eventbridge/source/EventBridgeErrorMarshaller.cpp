﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/client/AWSError.h>
#include <aws/eventbridge/EventBridgeErrorMarshaller.h>
#include <aws/eventbridge/EventBridgeErrors.h>

using namespace Aws::Client;
using namespace Aws::EventBridge;

AWSError<CoreErrors> EventBridgeErrorMarshaller::FindErrorByName(const char* errorName) const
{
  AWSError<CoreErrors> error = EventBridgeErrorMapper::GetErrorForName(errorName);
  if(error.GetErrorType() != CoreErrors::UNKNOWN)
  {
    return error;
  }

  return AWSErrorMarshaller::FindErrorByName(errorName);
}