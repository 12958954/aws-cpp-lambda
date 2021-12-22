﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/workspaces-web/model/UserSettingsSummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace WorkSpacesWeb
{
namespace Model
{

UserSettingsSummary::UserSettingsSummary() : 
    m_copyAllowed(EnabledType::NOT_SET),
    m_copyAllowedHasBeenSet(false),
    m_downloadAllowed(EnabledType::NOT_SET),
    m_downloadAllowedHasBeenSet(false),
    m_pasteAllowed(EnabledType::NOT_SET),
    m_pasteAllowedHasBeenSet(false),
    m_printAllowed(EnabledType::NOT_SET),
    m_printAllowedHasBeenSet(false),
    m_uploadAllowed(EnabledType::NOT_SET),
    m_uploadAllowedHasBeenSet(false),
    m_userSettingsArnHasBeenSet(false)
{
}

UserSettingsSummary::UserSettingsSummary(JsonView jsonValue) : 
    m_copyAllowed(EnabledType::NOT_SET),
    m_copyAllowedHasBeenSet(false),
    m_downloadAllowed(EnabledType::NOT_SET),
    m_downloadAllowedHasBeenSet(false),
    m_pasteAllowed(EnabledType::NOT_SET),
    m_pasteAllowedHasBeenSet(false),
    m_printAllowed(EnabledType::NOT_SET),
    m_printAllowedHasBeenSet(false),
    m_uploadAllowed(EnabledType::NOT_SET),
    m_uploadAllowedHasBeenSet(false),
    m_userSettingsArnHasBeenSet(false)
{
  *this = jsonValue;
}

UserSettingsSummary& UserSettingsSummary::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("copyAllowed"))
  {
    m_copyAllowed = EnabledTypeMapper::GetEnabledTypeForName(jsonValue.GetString("copyAllowed"));

    m_copyAllowedHasBeenSet = true;
  }

  if(jsonValue.ValueExists("downloadAllowed"))
  {
    m_downloadAllowed = EnabledTypeMapper::GetEnabledTypeForName(jsonValue.GetString("downloadAllowed"));

    m_downloadAllowedHasBeenSet = true;
  }

  if(jsonValue.ValueExists("pasteAllowed"))
  {
    m_pasteAllowed = EnabledTypeMapper::GetEnabledTypeForName(jsonValue.GetString("pasteAllowed"));

    m_pasteAllowedHasBeenSet = true;
  }

  if(jsonValue.ValueExists("printAllowed"))
  {
    m_printAllowed = EnabledTypeMapper::GetEnabledTypeForName(jsonValue.GetString("printAllowed"));

    m_printAllowedHasBeenSet = true;
  }

  if(jsonValue.ValueExists("uploadAllowed"))
  {
    m_uploadAllowed = EnabledTypeMapper::GetEnabledTypeForName(jsonValue.GetString("uploadAllowed"));

    m_uploadAllowedHasBeenSet = true;
  }

  if(jsonValue.ValueExists("userSettingsArn"))
  {
    m_userSettingsArn = jsonValue.GetString("userSettingsArn");

    m_userSettingsArnHasBeenSet = true;
  }

  return *this;
}

JsonValue UserSettingsSummary::Jsonize() const
{
  JsonValue payload;

  if(m_copyAllowedHasBeenSet)
  {
   payload.WithString("copyAllowed", EnabledTypeMapper::GetNameForEnabledType(m_copyAllowed));
  }

  if(m_downloadAllowedHasBeenSet)
  {
   payload.WithString("downloadAllowed", EnabledTypeMapper::GetNameForEnabledType(m_downloadAllowed));
  }

  if(m_pasteAllowedHasBeenSet)
  {
   payload.WithString("pasteAllowed", EnabledTypeMapper::GetNameForEnabledType(m_pasteAllowed));
  }

  if(m_printAllowedHasBeenSet)
  {
   payload.WithString("printAllowed", EnabledTypeMapper::GetNameForEnabledType(m_printAllowed));
  }

  if(m_uploadAllowedHasBeenSet)
  {
   payload.WithString("uploadAllowed", EnabledTypeMapper::GetNameForEnabledType(m_uploadAllowed));
  }

  if(m_userSettingsArnHasBeenSet)
  {
   payload.WithString("userSettingsArn", m_userSettingsArn);

  }

  return payload;
}

} // namespace Model
} // namespace WorkSpacesWeb
} // namespace Aws