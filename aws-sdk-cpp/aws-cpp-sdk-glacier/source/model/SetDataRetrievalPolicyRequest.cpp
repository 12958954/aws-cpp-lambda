﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/glacier/model/SetDataRetrievalPolicyRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Glacier::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

SetDataRetrievalPolicyRequest::SetDataRetrievalPolicyRequest() : 
    m_accountIdHasBeenSet(false),
    m_policyHasBeenSet(false)
{
}

Aws::String SetDataRetrievalPolicyRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_policyHasBeenSet)
  {
   payload.WithObject("Policy", m_policy.Jsonize());

  }

  return payload.View().WriteReadable();
}




