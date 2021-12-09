﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/finspace-data/model/CreateChangesetResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::FinSpaceData::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

CreateChangesetResult::CreateChangesetResult()
{
}

CreateChangesetResult::CreateChangesetResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

CreateChangesetResult& CreateChangesetResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("changeset"))
  {
    m_changeset = jsonValue.GetObject("changeset");

  }



  return *this;
}
