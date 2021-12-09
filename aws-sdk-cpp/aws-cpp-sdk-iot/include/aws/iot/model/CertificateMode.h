﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iot/IoT_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace IoT
{
namespace Model
{
  enum class CertificateMode
  {
    NOT_SET,
    DEFAULT,
    SNI_ONLY
  };

namespace CertificateModeMapper
{
AWS_IOT_API CertificateMode GetCertificateModeForName(const Aws::String& name);

AWS_IOT_API Aws::String GetNameForCertificateMode(CertificateMode value);
} // namespace CertificateModeMapper
} // namespace Model
} // namespace IoT
} // namespace Aws
