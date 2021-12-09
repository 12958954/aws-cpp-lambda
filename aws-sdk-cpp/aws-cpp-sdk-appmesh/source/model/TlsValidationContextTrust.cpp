﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/appmesh/model/TlsValidationContextTrust.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace AppMesh
{
namespace Model
{

TlsValidationContextTrust::TlsValidationContextTrust() : 
    m_acmHasBeenSet(false),
    m_fileHasBeenSet(false),
    m_sdsHasBeenSet(false)
{
}

TlsValidationContextTrust::TlsValidationContextTrust(JsonView jsonValue) : 
    m_acmHasBeenSet(false),
    m_fileHasBeenSet(false),
    m_sdsHasBeenSet(false)
{
  *this = jsonValue;
}

TlsValidationContextTrust& TlsValidationContextTrust::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("acm"))
  {
    m_acm = jsonValue.GetObject("acm");

    m_acmHasBeenSet = true;
  }

  if(jsonValue.ValueExists("file"))
  {
    m_file = jsonValue.GetObject("file");

    m_fileHasBeenSet = true;
  }

  if(jsonValue.ValueExists("sds"))
  {
    m_sds = jsonValue.GetObject("sds");

    m_sdsHasBeenSet = true;
  }

  return *this;
}

JsonValue TlsValidationContextTrust::Jsonize() const
{
  JsonValue payload;

  if(m_acmHasBeenSet)
  {
   payload.WithObject("acm", m_acm.Jsonize());

  }

  if(m_fileHasBeenSet)
  {
   payload.WithObject("file", m_file.Jsonize());

  }

  if(m_sdsHasBeenSet)
  {
   payload.WithObject("sds", m_sds.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace AppMesh
} // namespace Aws
