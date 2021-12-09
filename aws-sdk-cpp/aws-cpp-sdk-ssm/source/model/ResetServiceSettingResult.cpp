﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ssm/model/ResetServiceSettingResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::SSM::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

ResetServiceSettingResult::ResetServiceSettingResult()
{
}

ResetServiceSettingResult::ResetServiceSettingResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

ResetServiceSettingResult& ResetServiceSettingResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ServiceSetting"))
  {
    m_serviceSetting = jsonValue.GetObject("ServiceSetting");

  }



  return *this;
}
