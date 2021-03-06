/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/robomaker/model/DeleteFleetRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::RoboMaker::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DeleteFleetRequest::DeleteFleetRequest() : 
    m_fleetHasBeenSet(false)
{
}

Aws::String DeleteFleetRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_fleetHasBeenSet)
  {
   payload.WithString("fleet", m_fleet);

  }

  return payload.View().WriteReadable();
}




