/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/redshift/model/CreateAuthenticationProfileResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <utility>

using namespace Aws::Redshift::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils::Logging;
using namespace Aws::Utils;
using namespace Aws;

CreateAuthenticationProfileResult::CreateAuthenticationProfileResult()
{
}

CreateAuthenticationProfileResult::CreateAuthenticationProfileResult(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

CreateAuthenticationProfileResult& CreateAuthenticationProfileResult::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (!rootNode.IsNull() && (rootNode.GetName() != "CreateAuthenticationProfileResult"))
  {
    resultNode = rootNode.FirstChild("CreateAuthenticationProfileResult");
  }

  if(!resultNode.IsNull())
  {
    XmlNode authenticationProfileNameNode = resultNode.FirstChild("AuthenticationProfileName");
    if(!authenticationProfileNameNode.IsNull())
    {
      m_authenticationProfileName = Aws::Utils::Xml::DecodeEscapedXmlText(authenticationProfileNameNode.GetText());
    }
    XmlNode authenticationProfileContentNode = resultNode.FirstChild("AuthenticationProfileContent");
    if(!authenticationProfileContentNode.IsNull())
    {
      m_authenticationProfileContent = Aws::Utils::Xml::DecodeEscapedXmlText(authenticationProfileContentNode.GetText());
    }
  }

  if (!rootNode.IsNull()) {
    XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
    m_responseMetadata = responseMetadataNode;
    AWS_LOGSTREAM_DEBUG("Aws::Redshift::Model::CreateAuthenticationProfileResult", "x-amzn-request-id: " << m_responseMetadata.GetRequestId() );
  }
  return *this;
}
