﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ec2/model/S3ObjectTag.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

S3ObjectTag::S3ObjectTag() : 
    m_keyHasBeenSet(false),
    m_valueHasBeenSet(false)
{
}

S3ObjectTag::S3ObjectTag(const XmlNode& xmlNode) : 
    m_keyHasBeenSet(false),
    m_valueHasBeenSet(false)
{
  *this = xmlNode;
}

S3ObjectTag& S3ObjectTag::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode keyNode = resultNode.FirstChild("Key");
    if(!keyNode.IsNull())
    {
      m_key = Aws::Utils::Xml::DecodeEscapedXmlText(keyNode.GetText());
      m_keyHasBeenSet = true;
    }
    XmlNode valueNode = resultNode.FirstChild("Value");
    if(!valueNode.IsNull())
    {
      m_value = Aws::Utils::Xml::DecodeEscapedXmlText(valueNode.GetText());
      m_valueHasBeenSet = true;
    }
  }

  return *this;
}

void S3ObjectTag::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_keyHasBeenSet)
  {
      oStream << location << index << locationValue << ".Key=" << StringUtils::URLEncode(m_key.c_str()) << "&";
  }

  if(m_valueHasBeenSet)
  {
      oStream << location << index << locationValue << ".Value=" << StringUtils::URLEncode(m_value.c_str()) << "&";
  }

}

void S3ObjectTag::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_keyHasBeenSet)
  {
      oStream << location << ".Key=" << StringUtils::URLEncode(m_key.c_str()) << "&";
  }
  if(m_valueHasBeenSet)
  {
      oStream << location << ".Value=" << StringUtils::URLEncode(m_value.c_str()) << "&";
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
