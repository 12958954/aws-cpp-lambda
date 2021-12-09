﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/elasticmapreduce/model/SessionMappingSummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace EMR
{
namespace Model
{

SessionMappingSummary::SessionMappingSummary() : 
    m_studioIdHasBeenSet(false),
    m_identityIdHasBeenSet(false),
    m_identityNameHasBeenSet(false),
    m_identityType(IdentityType::NOT_SET),
    m_identityTypeHasBeenSet(false),
    m_sessionPolicyArnHasBeenSet(false),
    m_creationTimeHasBeenSet(false)
{
}

SessionMappingSummary::SessionMappingSummary(JsonView jsonValue) : 
    m_studioIdHasBeenSet(false),
    m_identityIdHasBeenSet(false),
    m_identityNameHasBeenSet(false),
    m_identityType(IdentityType::NOT_SET),
    m_identityTypeHasBeenSet(false),
    m_sessionPolicyArnHasBeenSet(false),
    m_creationTimeHasBeenSet(false)
{
  *this = jsonValue;
}

SessionMappingSummary& SessionMappingSummary::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("StudioId"))
  {
    m_studioId = jsonValue.GetString("StudioId");

    m_studioIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("IdentityId"))
  {
    m_identityId = jsonValue.GetString("IdentityId");

    m_identityIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("IdentityName"))
  {
    m_identityName = jsonValue.GetString("IdentityName");

    m_identityNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("IdentityType"))
  {
    m_identityType = IdentityTypeMapper::GetIdentityTypeForName(jsonValue.GetString("IdentityType"));

    m_identityTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("SessionPolicyArn"))
  {
    m_sessionPolicyArn = jsonValue.GetString("SessionPolicyArn");

    m_sessionPolicyArnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CreationTime"))
  {
    m_creationTime = jsonValue.GetDouble("CreationTime");

    m_creationTimeHasBeenSet = true;
  }

  return *this;
}

JsonValue SessionMappingSummary::Jsonize() const
{
  JsonValue payload;

  if(m_studioIdHasBeenSet)
  {
   payload.WithString("StudioId", m_studioId);

  }

  if(m_identityIdHasBeenSet)
  {
   payload.WithString("IdentityId", m_identityId);

  }

  if(m_identityNameHasBeenSet)
  {
   payload.WithString("IdentityName", m_identityName);

  }

  if(m_identityTypeHasBeenSet)
  {
   payload.WithString("IdentityType", IdentityTypeMapper::GetNameForIdentityType(m_identityType));
  }

  if(m_sessionPolicyArnHasBeenSet)
  {
   payload.WithString("SessionPolicyArn", m_sessionPolicyArn);

  }

  if(m_creationTimeHasBeenSet)
  {
   payload.WithDouble("CreationTime", m_creationTime.SecondsWithMSPrecision());
  }

  return payload;
}

} // namespace Model
} // namespace EMR
} // namespace Aws
