﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/sesv2/model/GetDedicatedIpResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::SESV2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetDedicatedIpResult::GetDedicatedIpResult()
{
}

GetDedicatedIpResult::GetDedicatedIpResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

GetDedicatedIpResult& GetDedicatedIpResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("DedicatedIp"))
  {
    m_dedicatedIp = jsonValue.GetObject("DedicatedIp");

  }



  return *this;
}
