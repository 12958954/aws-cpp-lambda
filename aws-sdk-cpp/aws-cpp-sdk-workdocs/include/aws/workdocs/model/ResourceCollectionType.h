﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/workdocs/WorkDocs_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace WorkDocs
{
namespace Model
{
  enum class ResourceCollectionType
  {
    NOT_SET,
    SHARED_WITH_ME
  };

namespace ResourceCollectionTypeMapper
{
AWS_WORKDOCS_API ResourceCollectionType GetResourceCollectionTypeForName(const Aws::String& name);

AWS_WORKDOCS_API Aws::String GetNameForResourceCollectionType(ResourceCollectionType value);
} // namespace ResourceCollectionTypeMapper
} // namespace Model
} // namespace WorkDocs
} // namespace Aws
