﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iotsitewise/model/GetAssetPropertyValueHistoryRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::IoTSiteWise::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws::Http;

GetAssetPropertyValueHistoryRequest::GetAssetPropertyValueHistoryRequest() : 
    m_assetIdHasBeenSet(false),
    m_propertyIdHasBeenSet(false),
    m_propertyAliasHasBeenSet(false),
    m_startDateHasBeenSet(false),
    m_endDateHasBeenSet(false),
    m_qualitiesHasBeenSet(false),
    m_timeOrdering(TimeOrdering::NOT_SET),
    m_timeOrderingHasBeenSet(false),
    m_nextTokenHasBeenSet(false),
    m_maxResults(0),
    m_maxResultsHasBeenSet(false)
{
}

Aws::String GetAssetPropertyValueHistoryRequest::SerializePayload() const
{
  return {};
}

void GetAssetPropertyValueHistoryRequest::AddQueryStringParameters(URI& uri) const
{
    Aws::StringStream ss;
    if(m_assetIdHasBeenSet)
    {
      ss << m_assetId;
      uri.AddQueryStringParameter("assetId", ss.str());
      ss.str("");
    }

    if(m_propertyIdHasBeenSet)
    {
      ss << m_propertyId;
      uri.AddQueryStringParameter("propertyId", ss.str());
      ss.str("");
    }

    if(m_propertyAliasHasBeenSet)
    {
      ss << m_propertyAlias;
      uri.AddQueryStringParameter("propertyAlias", ss.str());
      ss.str("");
    }

    if(m_startDateHasBeenSet)
    {
      ss << m_startDate.ToGmtString(DateFormat::ISO_8601);
      uri.AddQueryStringParameter("startDate", ss.str());
      ss.str("");
    }

    if(m_endDateHasBeenSet)
    {
      ss << m_endDate.ToGmtString(DateFormat::ISO_8601);
      uri.AddQueryStringParameter("endDate", ss.str());
      ss.str("");
    }

    if(m_qualitiesHasBeenSet)
    {
      for(const auto& item : m_qualities)
      {
        ss << QualityMapper::GetNameForQuality(item);
        uri.AddQueryStringParameter("qualities", ss.str());
        ss.str("");
      }
    }

    if(m_timeOrderingHasBeenSet)
    {
      ss << TimeOrderingMapper::GetNameForTimeOrdering(m_timeOrdering);
      uri.AddQueryStringParameter("timeOrdering", ss.str());
      ss.str("");
    }

    if(m_nextTokenHasBeenSet)
    {
      ss << m_nextToken;
      uri.AddQueryStringParameter("nextToken", ss.str());
      ss.str("");
    }

    if(m_maxResultsHasBeenSet)
    {
      ss << m_maxResults;
      uri.AddQueryStringParameter("maxResults", ss.str());
      ss.str("");
    }

}



