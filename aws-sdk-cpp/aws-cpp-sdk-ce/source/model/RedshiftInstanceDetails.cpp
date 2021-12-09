﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ce/model/RedshiftInstanceDetails.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace CostExplorer
{
namespace Model
{

RedshiftInstanceDetails::RedshiftInstanceDetails() : 
    m_familyHasBeenSet(false),
    m_nodeTypeHasBeenSet(false),
    m_regionHasBeenSet(false),
    m_currentGeneration(false),
    m_currentGenerationHasBeenSet(false),
    m_sizeFlexEligible(false),
    m_sizeFlexEligibleHasBeenSet(false)
{
}

RedshiftInstanceDetails::RedshiftInstanceDetails(JsonView jsonValue) : 
    m_familyHasBeenSet(false),
    m_nodeTypeHasBeenSet(false),
    m_regionHasBeenSet(false),
    m_currentGeneration(false),
    m_currentGenerationHasBeenSet(false),
    m_sizeFlexEligible(false),
    m_sizeFlexEligibleHasBeenSet(false)
{
  *this = jsonValue;
}

RedshiftInstanceDetails& RedshiftInstanceDetails::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Family"))
  {
    m_family = jsonValue.GetString("Family");

    m_familyHasBeenSet = true;
  }

  if(jsonValue.ValueExists("NodeType"))
  {
    m_nodeType = jsonValue.GetString("NodeType");

    m_nodeTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Region"))
  {
    m_region = jsonValue.GetString("Region");

    m_regionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CurrentGeneration"))
  {
    m_currentGeneration = jsonValue.GetBool("CurrentGeneration");

    m_currentGenerationHasBeenSet = true;
  }

  if(jsonValue.ValueExists("SizeFlexEligible"))
  {
    m_sizeFlexEligible = jsonValue.GetBool("SizeFlexEligible");

    m_sizeFlexEligibleHasBeenSet = true;
  }

  return *this;
}

JsonValue RedshiftInstanceDetails::Jsonize() const
{
  JsonValue payload;

  if(m_familyHasBeenSet)
  {
   payload.WithString("Family", m_family);

  }

  if(m_nodeTypeHasBeenSet)
  {
   payload.WithString("NodeType", m_nodeType);

  }

  if(m_regionHasBeenSet)
  {
   payload.WithString("Region", m_region);

  }

  if(m_currentGenerationHasBeenSet)
  {
   payload.WithBool("CurrentGeneration", m_currentGeneration);

  }

  if(m_sizeFlexEligibleHasBeenSet)
  {
   payload.WithBool("SizeFlexEligible", m_sizeFlexEligible);

  }

  return payload;
}

} // namespace Model
} // namespace CostExplorer
} // namespace Aws
