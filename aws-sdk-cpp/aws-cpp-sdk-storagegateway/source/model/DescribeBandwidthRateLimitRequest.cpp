﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/storagegateway/model/DescribeBandwidthRateLimitRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::StorageGateway::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DescribeBandwidthRateLimitRequest::DescribeBandwidthRateLimitRequest() : 
    m_gatewayARNHasBeenSet(false)
{
}

Aws::String DescribeBandwidthRateLimitRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_gatewayARNHasBeenSet)
  {
   payload.WithString("GatewayARN", m_gatewayARN);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection DescribeBandwidthRateLimitRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "StorageGateway_20130630.DescribeBandwidthRateLimit"));
  return headers;

}




