/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iot/model/DescribeAuditMitigationActionsTaskRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::IoT::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DescribeAuditMitigationActionsTaskRequest::DescribeAuditMitigationActionsTaskRequest() : 
    m_taskIdHasBeenSet(false)
{
}

Aws::String DescribeAuditMitigationActionsTaskRequest::SerializePayload() const
{
  return {};
}




