﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/marketplacecommerceanalytics/MarketplaceCommerceAnalytics_EXPORTS.h>
#include <aws/core/Region.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{

namespace MarketplaceCommerceAnalytics
{
namespace MarketplaceCommerceAnalyticsEndpoint
{
AWS_MARKETPLACECOMMERCEANALYTICS_API Aws::String ForRegion(const Aws::String& regionName, bool useDualStack = false);
} // namespace MarketplaceCommerceAnalyticsEndpoint
} // namespace MarketplaceCommerceAnalytics
} // namespace Aws
