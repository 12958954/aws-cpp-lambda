/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/location/LocationService_EXPORTS.h>
#include <aws/location/LocationServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/location/model/PricingPlan.h>
#include <utility>

namespace Aws
{
namespace LocationService
{
namespace Model
{

  /**
   */
  class AWS_LOCATIONSERVICE_API UpdateGeofenceCollectionRequest : public LocationServiceRequest
  {
  public:
    UpdateGeofenceCollectionRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "UpdateGeofenceCollection"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline const Aws::String& GetCollectionName() const{ return m_collectionName; }

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline bool CollectionNameHasBeenSet() const { return m_collectionNameHasBeenSet; }

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline void SetCollectionName(const Aws::String& value) { m_collectionNameHasBeenSet = true; m_collectionName = value; }

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline void SetCollectionName(Aws::String&& value) { m_collectionNameHasBeenSet = true; m_collectionName = std::move(value); }

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline void SetCollectionName(const char* value) { m_collectionNameHasBeenSet = true; m_collectionName.assign(value); }

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithCollectionName(const Aws::String& value) { SetCollectionName(value); return *this;}

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithCollectionName(Aws::String&& value) { SetCollectionName(std::move(value)); return *this;}

    /**
     * <p>The name of the geofence collection to update.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithCollectionName(const char* value) { SetCollectionName(value); return *this;}


    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline const Aws::String& GetDescription() const{ return m_description; }

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline bool DescriptionHasBeenSet() const { return m_descriptionHasBeenSet; }

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline void SetDescription(const Aws::String& value) { m_descriptionHasBeenSet = true; m_description = value; }

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline void SetDescription(Aws::String&& value) { m_descriptionHasBeenSet = true; m_description = std::move(value); }

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline void SetDescription(const char* value) { m_descriptionHasBeenSet = true; m_description.assign(value); }

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithDescription(const Aws::String& value) { SetDescription(value); return *this;}

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithDescription(Aws::String&& value) { SetDescription(std::move(value)); return *this;}

    /**
     * <p>Updates the description for the geofence collection.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithDescription(const char* value) { SetDescription(value); return *this;}


    /**
     * <p>Updates the pricing plan for the geofence collection.</p> <p>For more
     * information about each pricing plan option restrictions, see <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service
     * pricing</a>.</p>
     */
    inline const PricingPlan& GetPricingPlan() const{ return m_pricingPlan; }

    /**
     * <p>Updates the pricing plan for the geofence collection.</p> <p>For more
     * information about each pricing plan option restrictions, see <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service
     * pricing</a>.</p>
     */
    inline bool PricingPlanHasBeenSet() const { return m_pricingPlanHasBeenSet; }

    /**
     * <p>Updates the pricing plan for the geofence collection.</p> <p>For more
     * information about each pricing plan option restrictions, see <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service
     * pricing</a>.</p>
     */
    inline void SetPricingPlan(const PricingPlan& value) { m_pricingPlanHasBeenSet = true; m_pricingPlan = value; }

    /**
     * <p>Updates the pricing plan for the geofence collection.</p> <p>For more
     * information about each pricing plan option restrictions, see <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service
     * pricing</a>.</p>
     */
    inline void SetPricingPlan(PricingPlan&& value) { m_pricingPlanHasBeenSet = true; m_pricingPlan = std::move(value); }

    /**
     * <p>Updates the pricing plan for the geofence collection.</p> <p>For more
     * information about each pricing plan option restrictions, see <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service
     * pricing</a>.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithPricingPlan(const PricingPlan& value) { SetPricingPlan(value); return *this;}

    /**
     * <p>Updates the pricing plan for the geofence collection.</p> <p>For more
     * information about each pricing plan option restrictions, see <a
     * href="https://aws.amazon.com/location/pricing/">Amazon Location Service
     * pricing</a>.</p>
     */
    inline UpdateGeofenceCollectionRequest& WithPricingPlan(PricingPlan&& value) { SetPricingPlan(std::move(value)); return *this;}


    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline const Aws::String& GetPricingPlanDataSource() const{ return m_pricingPlanDataSource; }

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline bool PricingPlanDataSourceHasBeenSet() const { return m_pricingPlanDataSourceHasBeenSet; }

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline void SetPricingPlanDataSource(const Aws::String& value) { m_pricingPlanDataSourceHasBeenSet = true; m_pricingPlanDataSource = value; }

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline void SetPricingPlanDataSource(Aws::String&& value) { m_pricingPlanDataSourceHasBeenSet = true; m_pricingPlanDataSource = std::move(value); }

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline void SetPricingPlanDataSource(const char* value) { m_pricingPlanDataSourceHasBeenSet = true; m_pricingPlanDataSource.assign(value); }

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline UpdateGeofenceCollectionRequest& WithPricingPlanDataSource(const Aws::String& value) { SetPricingPlanDataSource(value); return *this;}

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline UpdateGeofenceCollectionRequest& WithPricingPlanDataSource(Aws::String&& value) { SetPricingPlanDataSource(std::move(value)); return *this;}

    /**
     * <p>Updates the data provider for the geofence collection. </p> <p>A required
     * value for the following pricing plans: <code>MobileAssetTracking</code>|
     * <code>MobileAssetManagement</code> </p> <p>For more information about <a
     * href="https://aws.amazon.com/location/data-providers/">data providers</a> and <a
     * href="https://aws.amazon.com/location/pricing/">pricing plans</a>, see the
     * Amazon Location Service product page.</p>  <p>This can only be updated
     * when updating the <code>PricingPlan</code> in the same request.</p> <p>Amazon
     * Location Service uses <code>PricingPlanDataSource</code> to calculate billing
     * for your geofence collection. Your data won't be shared with the data provider,
     * and will remain in your AWS account and Region unless you move it.</p> 
     */
    inline UpdateGeofenceCollectionRequest& WithPricingPlanDataSource(const char* value) { SetPricingPlanDataSource(value); return *this;}

  private:

    Aws::String m_collectionName;
    bool m_collectionNameHasBeenSet;

    Aws::String m_description;
    bool m_descriptionHasBeenSet;

    PricingPlan m_pricingPlan;
    bool m_pricingPlanHasBeenSet;

    Aws::String m_pricingPlanDataSource;
    bool m_pricingPlanDataSourceHasBeenSet;
  };

} // namespace Model
} // namespace LocationService
} // namespace Aws
