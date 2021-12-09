﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/eks/model/DeleteFargateProfileRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::EKS::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DeleteFargateProfileRequest::DeleteFargateProfileRequest() : 
    m_clusterNameHasBeenSet(false),
    m_fargateProfileNameHasBeenSet(false)
{
}

Aws::String DeleteFargateProfileRequest::SerializePayload() const
{
  return {};
}




