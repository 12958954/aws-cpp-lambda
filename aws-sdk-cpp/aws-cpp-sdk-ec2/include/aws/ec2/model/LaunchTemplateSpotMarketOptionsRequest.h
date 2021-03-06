/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/SpotInstanceType.h>
#include <aws/core/utils/DateTime.h>
#include <aws/ec2/model/InstanceInterruptionBehavior.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace EC2
{
namespace Model
{

  /**
   * <p>The options for Spot Instances.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/ec2-2016-11-15/LaunchTemplateSpotMarketOptionsRequest">AWS
   * API Reference</a></p>
   */
  class AWS_EC2_API LaunchTemplateSpotMarketOptionsRequest
  {
  public:
    LaunchTemplateSpotMarketOptionsRequest();
    LaunchTemplateSpotMarketOptionsRequest(const Aws::Utils::Xml::XmlNode& xmlNode);
    LaunchTemplateSpotMarketOptionsRequest& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;


    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline const Aws::String& GetMaxPrice() const{ return m_maxPrice; }

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline bool MaxPriceHasBeenSet() const { return m_maxPriceHasBeenSet; }

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline void SetMaxPrice(const Aws::String& value) { m_maxPriceHasBeenSet = true; m_maxPrice = value; }

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline void SetMaxPrice(Aws::String&& value) { m_maxPriceHasBeenSet = true; m_maxPrice = std::move(value); }

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline void SetMaxPrice(const char* value) { m_maxPriceHasBeenSet = true; m_maxPrice.assign(value); }

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithMaxPrice(const Aws::String& value) { SetMaxPrice(value); return *this;}

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithMaxPrice(Aws::String&& value) { SetMaxPrice(std::move(value)); return *this;}

    /**
     * <p>The maximum hourly price you're willing to pay for the Spot Instances.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithMaxPrice(const char* value) { SetMaxPrice(value); return *this;}


    /**
     * <p>The Spot Instance request type.</p>
     */
    inline const SpotInstanceType& GetSpotInstanceType() const{ return m_spotInstanceType; }

    /**
     * <p>The Spot Instance request type.</p>
     */
    inline bool SpotInstanceTypeHasBeenSet() const { return m_spotInstanceTypeHasBeenSet; }

    /**
     * <p>The Spot Instance request type.</p>
     */
    inline void SetSpotInstanceType(const SpotInstanceType& value) { m_spotInstanceTypeHasBeenSet = true; m_spotInstanceType = value; }

    /**
     * <p>The Spot Instance request type.</p>
     */
    inline void SetSpotInstanceType(SpotInstanceType&& value) { m_spotInstanceTypeHasBeenSet = true; m_spotInstanceType = std::move(value); }

    /**
     * <p>The Spot Instance request type.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithSpotInstanceType(const SpotInstanceType& value) { SetSpotInstanceType(value); return *this;}

    /**
     * <p>The Spot Instance request type.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithSpotInstanceType(SpotInstanceType&& value) { SetSpotInstanceType(std::move(value)); return *this;}


    /**
     * <p>The required duration for the Spot Instances (also known as Spot blocks), in
     * minutes. This value must be a multiple of 60 (60, 120, 180, 240, 300, or
     * 360).</p>
     */
    inline int GetBlockDurationMinutes() const{ return m_blockDurationMinutes; }

    /**
     * <p>The required duration for the Spot Instances (also known as Spot blocks), in
     * minutes. This value must be a multiple of 60 (60, 120, 180, 240, 300, or
     * 360).</p>
     */
    inline bool BlockDurationMinutesHasBeenSet() const { return m_blockDurationMinutesHasBeenSet; }

    /**
     * <p>The required duration for the Spot Instances (also known as Spot blocks), in
     * minutes. This value must be a multiple of 60 (60, 120, 180, 240, 300, or
     * 360).</p>
     */
    inline void SetBlockDurationMinutes(int value) { m_blockDurationMinutesHasBeenSet = true; m_blockDurationMinutes = value; }

    /**
     * <p>The required duration for the Spot Instances (also known as Spot blocks), in
     * minutes. This value must be a multiple of 60 (60, 120, 180, 240, 300, or
     * 360).</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithBlockDurationMinutes(int value) { SetBlockDurationMinutes(value); return *this;}


    /**
     * <p>The end date of the request. For a one-time request, the request remains
     * active until all instances launch, the request is canceled, or this date is
     * reached. If the request is persistent, it remains active until it is canceled or
     * this date and time is reached. The default end date is 7 days from the current
     * date.</p>
     */
    inline const Aws::Utils::DateTime& GetValidUntil() const{ return m_validUntil; }

    /**
     * <p>The end date of the request. For a one-time request, the request remains
     * active until all instances launch, the request is canceled, or this date is
     * reached. If the request is persistent, it remains active until it is canceled or
     * this date and time is reached. The default end date is 7 days from the current
     * date.</p>
     */
    inline bool ValidUntilHasBeenSet() const { return m_validUntilHasBeenSet; }

    /**
     * <p>The end date of the request. For a one-time request, the request remains
     * active until all instances launch, the request is canceled, or this date is
     * reached. If the request is persistent, it remains active until it is canceled or
     * this date and time is reached. The default end date is 7 days from the current
     * date.</p>
     */
    inline void SetValidUntil(const Aws::Utils::DateTime& value) { m_validUntilHasBeenSet = true; m_validUntil = value; }

    /**
     * <p>The end date of the request. For a one-time request, the request remains
     * active until all instances launch, the request is canceled, or this date is
     * reached. If the request is persistent, it remains active until it is canceled or
     * this date and time is reached. The default end date is 7 days from the current
     * date.</p>
     */
    inline void SetValidUntil(Aws::Utils::DateTime&& value) { m_validUntilHasBeenSet = true; m_validUntil = std::move(value); }

    /**
     * <p>The end date of the request. For a one-time request, the request remains
     * active until all instances launch, the request is canceled, or this date is
     * reached. If the request is persistent, it remains active until it is canceled or
     * this date and time is reached. The default end date is 7 days from the current
     * date.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithValidUntil(const Aws::Utils::DateTime& value) { SetValidUntil(value); return *this;}

    /**
     * <p>The end date of the request. For a one-time request, the request remains
     * active until all instances launch, the request is canceled, or this date is
     * reached. If the request is persistent, it remains active until it is canceled or
     * this date and time is reached. The default end date is 7 days from the current
     * date.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithValidUntil(Aws::Utils::DateTime&& value) { SetValidUntil(std::move(value)); return *this;}


    /**
     * <p>The behavior when a Spot Instance is interrupted. The default is
     * <code>terminate</code>.</p>
     */
    inline const InstanceInterruptionBehavior& GetInstanceInterruptionBehavior() const{ return m_instanceInterruptionBehavior; }

    /**
     * <p>The behavior when a Spot Instance is interrupted. The default is
     * <code>terminate</code>.</p>
     */
    inline bool InstanceInterruptionBehaviorHasBeenSet() const { return m_instanceInterruptionBehaviorHasBeenSet; }

    /**
     * <p>The behavior when a Spot Instance is interrupted. The default is
     * <code>terminate</code>.</p>
     */
    inline void SetInstanceInterruptionBehavior(const InstanceInterruptionBehavior& value) { m_instanceInterruptionBehaviorHasBeenSet = true; m_instanceInterruptionBehavior = value; }

    /**
     * <p>The behavior when a Spot Instance is interrupted. The default is
     * <code>terminate</code>.</p>
     */
    inline void SetInstanceInterruptionBehavior(InstanceInterruptionBehavior&& value) { m_instanceInterruptionBehaviorHasBeenSet = true; m_instanceInterruptionBehavior = std::move(value); }

    /**
     * <p>The behavior when a Spot Instance is interrupted. The default is
     * <code>terminate</code>.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithInstanceInterruptionBehavior(const InstanceInterruptionBehavior& value) { SetInstanceInterruptionBehavior(value); return *this;}

    /**
     * <p>The behavior when a Spot Instance is interrupted. The default is
     * <code>terminate</code>.</p>
     */
    inline LaunchTemplateSpotMarketOptionsRequest& WithInstanceInterruptionBehavior(InstanceInterruptionBehavior&& value) { SetInstanceInterruptionBehavior(std::move(value)); return *this;}

  private:

    Aws::String m_maxPrice;
    bool m_maxPriceHasBeenSet;

    SpotInstanceType m_spotInstanceType;
    bool m_spotInstanceTypeHasBeenSet;

    int m_blockDurationMinutes;
    bool m_blockDurationMinutesHasBeenSet;

    Aws::Utils::DateTime m_validUntil;
    bool m_validUntilHasBeenSet;

    InstanceInterruptionBehavior m_instanceInterruptionBehavior;
    bool m_instanceInterruptionBehaviorHasBeenSet;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
