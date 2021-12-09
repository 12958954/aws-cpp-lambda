﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/groundstation/model/DeleteMissionProfileRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::GroundStation::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DeleteMissionProfileRequest::DeleteMissionProfileRequest() : 
    m_missionProfileIdHasBeenSet(false)
{
}

Aws::String DeleteMissionProfileRequest::SerializePayload() const
{
  return {};
}




