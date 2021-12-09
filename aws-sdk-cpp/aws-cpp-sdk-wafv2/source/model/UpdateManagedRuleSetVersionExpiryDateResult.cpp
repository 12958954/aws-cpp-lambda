﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/wafv2/model/UpdateManagedRuleSetVersionExpiryDateResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::WAFV2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

UpdateManagedRuleSetVersionExpiryDateResult::UpdateManagedRuleSetVersionExpiryDateResult()
{
}

UpdateManagedRuleSetVersionExpiryDateResult::UpdateManagedRuleSetVersionExpiryDateResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

UpdateManagedRuleSetVersionExpiryDateResult& UpdateManagedRuleSetVersionExpiryDateResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ExpiringVersion"))
  {
    m_expiringVersion = jsonValue.GetString("ExpiringVersion");

  }

  if(jsonValue.ValueExists("ExpiryTimestamp"))
  {
    m_expiryTimestamp = jsonValue.GetDouble("ExpiryTimestamp");

  }

  if(jsonValue.ValueExists("NextLockToken"))
  {
    m_nextLockToken = jsonValue.GetString("NextLockToken");

  }



  return *this;
}
