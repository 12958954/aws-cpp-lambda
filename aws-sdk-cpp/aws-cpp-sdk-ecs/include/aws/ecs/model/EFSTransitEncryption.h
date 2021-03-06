/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ecs/ECS_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace ECS
{
namespace Model
{
  enum class EFSTransitEncryption
  {
    NOT_SET,
    ENABLED,
    DISABLED
  };

namespace EFSTransitEncryptionMapper
{
AWS_ECS_API EFSTransitEncryption GetEFSTransitEncryptionForName(const Aws::String& name);

AWS_ECS_API Aws::String GetNameForEFSTransitEncryption(EFSTransitEncryption value);
} // namespace EFSTransitEncryptionMapper
} // namespace Model
} // namespace ECS
} // namespace Aws
