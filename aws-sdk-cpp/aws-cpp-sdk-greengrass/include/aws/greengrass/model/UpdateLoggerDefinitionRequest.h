﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/greengrass/Greengrass_EXPORTS.h>
#include <aws/greengrass/GreengrassRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Greengrass
{
namespace Model
{

  /**
   */
  class AWS_GREENGRASS_API UpdateLoggerDefinitionRequest : public GreengrassRequest
  {
  public:
    UpdateLoggerDefinitionRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "UpdateLoggerDefinition"; }

    Aws::String SerializePayload() const override;


    /**
     * The ID of the logger definition.
     */
    inline const Aws::String& GetLoggerDefinitionId() const{ return m_loggerDefinitionId; }

    /**
     * The ID of the logger definition.
     */
    inline bool LoggerDefinitionIdHasBeenSet() const { return m_loggerDefinitionIdHasBeenSet; }

    /**
     * The ID of the logger definition.
     */
    inline void SetLoggerDefinitionId(const Aws::String& value) { m_loggerDefinitionIdHasBeenSet = true; m_loggerDefinitionId = value; }

    /**
     * The ID of the logger definition.
     */
    inline void SetLoggerDefinitionId(Aws::String&& value) { m_loggerDefinitionIdHasBeenSet = true; m_loggerDefinitionId = std::move(value); }

    /**
     * The ID of the logger definition.
     */
    inline void SetLoggerDefinitionId(const char* value) { m_loggerDefinitionIdHasBeenSet = true; m_loggerDefinitionId.assign(value); }

    /**
     * The ID of the logger definition.
     */
    inline UpdateLoggerDefinitionRequest& WithLoggerDefinitionId(const Aws::String& value) { SetLoggerDefinitionId(value); return *this;}

    /**
     * The ID of the logger definition.
     */
    inline UpdateLoggerDefinitionRequest& WithLoggerDefinitionId(Aws::String&& value) { SetLoggerDefinitionId(std::move(value)); return *this;}

    /**
     * The ID of the logger definition.
     */
    inline UpdateLoggerDefinitionRequest& WithLoggerDefinitionId(const char* value) { SetLoggerDefinitionId(value); return *this;}


    /**
     * The name of the definition.
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * The name of the definition.
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * The name of the definition.
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * The name of the definition.
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * The name of the definition.
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * The name of the definition.
     */
    inline UpdateLoggerDefinitionRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * The name of the definition.
     */
    inline UpdateLoggerDefinitionRequest& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * The name of the definition.
     */
    inline UpdateLoggerDefinitionRequest& WithName(const char* value) { SetName(value); return *this;}

  private:

    Aws::String m_loggerDefinitionId;
    bool m_loggerDefinitionIdHasBeenSet;

    Aws::String m_name;
    bool m_nameHasBeenSet;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws
