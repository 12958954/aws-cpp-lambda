﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/lakeformation/model/RemoveLFTagsFromResourceRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::LakeFormation::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

RemoveLFTagsFromResourceRequest::RemoveLFTagsFromResourceRequest() : 
    m_catalogIdHasBeenSet(false),
    m_resourceHasBeenSet(false),
    m_lFTagsHasBeenSet(false)
{
}

Aws::String RemoveLFTagsFromResourceRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_catalogIdHasBeenSet)
  {
   payload.WithString("CatalogId", m_catalogId);

  }

  if(m_resourceHasBeenSet)
  {
   payload.WithObject("Resource", m_resource.Jsonize());

  }

  if(m_lFTagsHasBeenSet)
  {
   Array<JsonValue> lFTagsJsonList(m_lFTags.size());
   for(unsigned lFTagsIndex = 0; lFTagsIndex < lFTagsJsonList.GetLength(); ++lFTagsIndex)
   {
     lFTagsJsonList[lFTagsIndex].AsObject(m_lFTags[lFTagsIndex].Jsonize());
   }
   payload.WithArray("LFTags", std::move(lFTagsJsonList));

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection RemoveLFTagsFromResourceRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSLakeFormation.RemoveLFTagsFromResource"));
  return headers;

}




