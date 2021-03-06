/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/alexaforbusiness/model/CreateInstantBooking.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace AlexaForBusiness
{
namespace Model
{

CreateInstantBooking::CreateInstantBooking() : 
    m_durationInMinutes(0),
    m_durationInMinutesHasBeenSet(false),
    m_enabled(false),
    m_enabledHasBeenSet(false)
{
}

CreateInstantBooking::CreateInstantBooking(JsonView jsonValue) : 
    m_durationInMinutes(0),
    m_durationInMinutesHasBeenSet(false),
    m_enabled(false),
    m_enabledHasBeenSet(false)
{
  *this = jsonValue;
}

CreateInstantBooking& CreateInstantBooking::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("DurationInMinutes"))
  {
    m_durationInMinutes = jsonValue.GetInteger("DurationInMinutes");

    m_durationInMinutesHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Enabled"))
  {
    m_enabled = jsonValue.GetBool("Enabled");

    m_enabledHasBeenSet = true;
  }

  return *this;
}

JsonValue CreateInstantBooking::Jsonize() const
{
  JsonValue payload;

  if(m_durationInMinutesHasBeenSet)
  {
   payload.WithInteger("DurationInMinutes", m_durationInMinutes);

  }

  if(m_enabledHasBeenSet)
  {
   payload.WithBool("Enabled", m_enabled);

  }

  return payload;
}

} // namespace Model
} // namespace AlexaForBusiness
} // namespace Aws
