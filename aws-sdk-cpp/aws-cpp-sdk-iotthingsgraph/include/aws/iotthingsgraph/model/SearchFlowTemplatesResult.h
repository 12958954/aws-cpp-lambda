/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iotthingsgraph/IoTThingsGraph_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/iotthingsgraph/model/FlowTemplateSummary.h>
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
namespace IoTThingsGraph
{
namespace Model
{
  class AWS_IOTTHINGSGRAPH_API SearchFlowTemplatesResult
  {
  public:
    SearchFlowTemplatesResult();
    SearchFlowTemplatesResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    SearchFlowTemplatesResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline const Aws::Vector<FlowTemplateSummary>& GetSummaries() const{ return m_summaries; }

    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline void SetSummaries(const Aws::Vector<FlowTemplateSummary>& value) { m_summaries = value; }

    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline void SetSummaries(Aws::Vector<FlowTemplateSummary>&& value) { m_summaries = std::move(value); }

    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline SearchFlowTemplatesResult& WithSummaries(const Aws::Vector<FlowTemplateSummary>& value) { SetSummaries(value); return *this;}

    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline SearchFlowTemplatesResult& WithSummaries(Aws::Vector<FlowTemplateSummary>&& value) { SetSummaries(std::move(value)); return *this;}

    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline SearchFlowTemplatesResult& AddSummaries(const FlowTemplateSummary& value) { m_summaries.push_back(value); return *this; }

    /**
     * <p>An array of objects that contain summary information about each workflow in
     * the result set.</p>
     */
    inline SearchFlowTemplatesResult& AddSummaries(FlowTemplateSummary&& value) { m_summaries.push_back(std::move(value)); return *this; }


    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline SearchFlowTemplatesResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline SearchFlowTemplatesResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The string to specify as <code>nextToken</code> when you request the next
     * page of results.</p>
     */
    inline SearchFlowTemplatesResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<FlowTemplateSummary> m_summaries;

    Aws::String m_nextToken;
  };

} // namespace Model
} // namespace IoTThingsGraph
} // namespace Aws
