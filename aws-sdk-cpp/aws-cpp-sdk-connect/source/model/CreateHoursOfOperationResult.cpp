﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/connect/model/CreateHoursOfOperationResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Connect::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

CreateHoursOfOperationResult::CreateHoursOfOperationResult()
{
}

CreateHoursOfOperationResult::CreateHoursOfOperationResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

CreateHoursOfOperationResult& CreateHoursOfOperationResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("HoursOfOperationId"))
  {
    m_hoursOfOperationId = jsonValue.GetString("HoursOfOperationId");

  }

  if(jsonValue.ValueExists("HoursOfOperationArn"))
  {
    m_hoursOfOperationArn = jsonValue.GetString("HoursOfOperationArn");

  }



  return *this;
}
