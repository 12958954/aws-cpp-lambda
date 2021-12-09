﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/transcribe/TranscribeService_EXPORTS.h>
#include <aws/transcribe/model/CategoryProperties.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace TranscribeService
{
namespace Model
{
  class AWS_TRANSCRIBESERVICE_API GetCallAnalyticsCategoryResult
  {
  public:
    GetCallAnalyticsCategoryResult();
    GetCallAnalyticsCategoryResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    GetCallAnalyticsCategoryResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>The rules you've defined for a category.</p>
     */
    inline const CategoryProperties& GetCategoryProperties() const{ return m_categoryProperties; }

    /**
     * <p>The rules you've defined for a category.</p>
     */
    inline void SetCategoryProperties(const CategoryProperties& value) { m_categoryProperties = value; }

    /**
     * <p>The rules you've defined for a category.</p>
     */
    inline void SetCategoryProperties(CategoryProperties&& value) { m_categoryProperties = std::move(value); }

    /**
     * <p>The rules you've defined for a category.</p>
     */
    inline GetCallAnalyticsCategoryResult& WithCategoryProperties(const CategoryProperties& value) { SetCategoryProperties(value); return *this;}

    /**
     * <p>The rules you've defined for a category.</p>
     */
    inline GetCallAnalyticsCategoryResult& WithCategoryProperties(CategoryProperties&& value) { SetCategoryProperties(std::move(value)); return *this;}

  private:

    CategoryProperties m_categoryProperties;
  };

} // namespace Model
} // namespace TranscribeService
} // namespace Aws