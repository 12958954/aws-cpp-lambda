/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ssm/SSM_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace SSM
{
namespace Model
{
  enum class AssociationExecutionTargetsFilterKey
  {
    NOT_SET,
    Status,
    ResourceId,
    ResourceType
  };

namespace AssociationExecutionTargetsFilterKeyMapper
{
AWS_SSM_API AssociationExecutionTargetsFilterKey GetAssociationExecutionTargetsFilterKeyForName(const Aws::String& name);

AWS_SSM_API Aws::String GetNameForAssociationExecutionTargetsFilterKey(AssociationExecutionTargetsFilterKey value);
} // namespace AssociationExecutionTargetsFilterKeyMapper
} // namespace Model
} // namespace SSM
} // namespace Aws
