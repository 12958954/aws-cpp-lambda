﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/alexaforbusiness/model/SearchRoomsResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::AlexaForBusiness::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

SearchRoomsResult::SearchRoomsResult() : 
    m_totalCount(0)
{
}

SearchRoomsResult::SearchRoomsResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_totalCount(0)
{
  *this = result;
}

SearchRoomsResult& SearchRoomsResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("Rooms"))
  {
    Array<JsonView> roomsJsonList = jsonValue.GetArray("Rooms");
    for(unsigned roomsIndex = 0; roomsIndex < roomsJsonList.GetLength(); ++roomsIndex)
    {
      m_rooms.push_back(roomsJsonList[roomsIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("NextToken"))
  {
    m_nextToken = jsonValue.GetString("NextToken");

  }

  if(jsonValue.ValueExists("TotalCount"))
  {
    m_totalCount = jsonValue.GetInteger("TotalCount");

  }



  return *this;
}
