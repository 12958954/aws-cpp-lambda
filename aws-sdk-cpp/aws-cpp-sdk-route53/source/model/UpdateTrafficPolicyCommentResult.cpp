/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/route53/model/UpdateTrafficPolicyCommentResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::Route53::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

UpdateTrafficPolicyCommentResult::UpdateTrafficPolicyCommentResult()
{
}

UpdateTrafficPolicyCommentResult::UpdateTrafficPolicyCommentResult(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

UpdateTrafficPolicyCommentResult& UpdateTrafficPolicyCommentResult::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode resultNode = xmlDocument.GetRootElement();

  if(!resultNode.IsNull())
  {
    XmlNode trafficPolicyNode = resultNode.FirstChild("TrafficPolicy");
    if(!trafficPolicyNode.IsNull())
    {
      m_trafficPolicy = trafficPolicyNode;
    }
  }

  return *this;
}
