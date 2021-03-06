/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/mobile/model/CreateProjectRequest.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/HashingUtils.h>

#include <utility>

using namespace Aws::Mobile::Model;
using namespace Aws::Utils::Stream;
using namespace Aws::Utils;
using namespace Aws::Http;
using namespace Aws;

CreateProjectRequest::CreateProjectRequest() : 
    m_nameHasBeenSet(false),
    m_regionHasBeenSet(false),
    m_snapshotIdHasBeenSet(false)
{
}


void CreateProjectRequest::AddQueryStringParameters(URI& uri) const
{
    Aws::StringStream ss;
    if(m_nameHasBeenSet)
    {
      ss << m_name;
      uri.AddQueryStringParameter("name", ss.str());
      ss.str("");
    }

    if(m_regionHasBeenSet)
    {
      ss << m_region;
      uri.AddQueryStringParameter("region", ss.str());
      ss.str("");
    }

    if(m_snapshotIdHasBeenSet)
    {
      ss << m_snapshotId;
      uri.AddQueryStringParameter("snapshotId", ss.str());
      ss.str("");
    }

}

