﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/schemas/model/CreateDiscovererResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Schemas::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

CreateDiscovererResult::CreateDiscovererResult() : 
    m_state(DiscovererState::NOT_SET)
{
}

CreateDiscovererResult::CreateDiscovererResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_state(DiscovererState::NOT_SET)
{
  *this = result;
}

CreateDiscovererResult& CreateDiscovererResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("Description"))
  {
    m_description = jsonValue.GetString("Description");

  }

  if(jsonValue.ValueExists("DiscovererArn"))
  {
    m_discovererArn = jsonValue.GetString("DiscovererArn");

  }

  if(jsonValue.ValueExists("DiscovererId"))
  {
    m_discovererId = jsonValue.GetString("DiscovererId");

  }

  if(jsonValue.ValueExists("SourceArn"))
  {
    m_sourceArn = jsonValue.GetString("SourceArn");

  }

  if(jsonValue.ValueExists("State"))
  {
    m_state = DiscovererStateMapper::GetDiscovererStateForName(jsonValue.GetString("State"));

  }

  if(jsonValue.ValueExists("tags"))
  {
    Aws::Map<Aws::String, JsonView> tagsJsonMap = jsonValue.GetObject("tags").GetAllObjects();
    for(auto& tagsItem : tagsJsonMap)
    {
      m_tags[tagsItem.first] = tagsItem.second.AsString();
    }
  }



  return *this;
}
