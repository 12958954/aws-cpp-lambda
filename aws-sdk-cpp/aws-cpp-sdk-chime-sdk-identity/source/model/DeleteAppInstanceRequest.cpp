﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/chime-sdk-identity/model/DeleteAppInstanceRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::ChimeSDKIdentity::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DeleteAppInstanceRequest::DeleteAppInstanceRequest() : 
    m_appInstanceArnHasBeenSet(false)
{
}

Aws::String DeleteAppInstanceRequest::SerializePayload() const
{
  return {};
}




