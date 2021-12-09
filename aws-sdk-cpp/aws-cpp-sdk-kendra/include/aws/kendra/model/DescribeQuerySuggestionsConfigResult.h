﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/kendra/Kendra_EXPORTS.h>
#include <aws/kendra/model/Mode.h>
#include <aws/kendra/model/QuerySuggestionsStatus.h>
#include <aws/core/utils/DateTime.h>
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
namespace kendra
{
namespace Model
{
  class AWS_KENDRA_API DescribeQuerySuggestionsConfigResult
  {
  public:
    DescribeQuerySuggestionsConfigResult();
    DescribeQuerySuggestionsConfigResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    DescribeQuerySuggestionsConfigResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>Shows whether query suggestions are currently in <code>ENABLED</code> mode or
     * <code>LEARN_ONLY</code> mode.</p> <p>By default, Amazon Kendra enables query
     * suggestions.<code>LEARN_ONLY</code> turns off query suggestions for your users.
     * You can change the mode using the <a
     * href="https://docs.aws.amazon.com/kendra/latest/dg/API_UpdateQuerySuggestionsConfig.html">UpdateQuerySuggestionsConfig</a>
     * operation.</p>
     */
    inline const Mode& GetMode() const{ return m_mode; }

    /**
     * <p>Shows whether query suggestions are currently in <code>ENABLED</code> mode or
     * <code>LEARN_ONLY</code> mode.</p> <p>By default, Amazon Kendra enables query
     * suggestions.<code>LEARN_ONLY</code> turns off query suggestions for your users.
     * You can change the mode using the <a
     * href="https://docs.aws.amazon.com/kendra/latest/dg/API_UpdateQuerySuggestionsConfig.html">UpdateQuerySuggestionsConfig</a>
     * operation.</p>
     */
    inline void SetMode(const Mode& value) { m_mode = value; }

    /**
     * <p>Shows whether query suggestions are currently in <code>ENABLED</code> mode or
     * <code>LEARN_ONLY</code> mode.</p> <p>By default, Amazon Kendra enables query
     * suggestions.<code>LEARN_ONLY</code> turns off query suggestions for your users.
     * You can change the mode using the <a
     * href="https://docs.aws.amazon.com/kendra/latest/dg/API_UpdateQuerySuggestionsConfig.html">UpdateQuerySuggestionsConfig</a>
     * operation.</p>
     */
    inline void SetMode(Mode&& value) { m_mode = std::move(value); }

    /**
     * <p>Shows whether query suggestions are currently in <code>ENABLED</code> mode or
     * <code>LEARN_ONLY</code> mode.</p> <p>By default, Amazon Kendra enables query
     * suggestions.<code>LEARN_ONLY</code> turns off query suggestions for your users.
     * You can change the mode using the <a
     * href="https://docs.aws.amazon.com/kendra/latest/dg/API_UpdateQuerySuggestionsConfig.html">UpdateQuerySuggestionsConfig</a>
     * operation.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithMode(const Mode& value) { SetMode(value); return *this;}

    /**
     * <p>Shows whether query suggestions are currently in <code>ENABLED</code> mode or
     * <code>LEARN_ONLY</code> mode.</p> <p>By default, Amazon Kendra enables query
     * suggestions.<code>LEARN_ONLY</code> turns off query suggestions for your users.
     * You can change the mode using the <a
     * href="https://docs.aws.amazon.com/kendra/latest/dg/API_UpdateQuerySuggestionsConfig.html">UpdateQuerySuggestionsConfig</a>
     * operation.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithMode(Mode&& value) { SetMode(std::move(value)); return *this;}


    /**
     * <p>Shows whether the status of query suggestions settings is currently Active or
     * Updating.</p> <p>Active means the current settings apply and Updating means your
     * changed settings are in the process of applying.</p>
     */
    inline const QuerySuggestionsStatus& GetStatus() const{ return m_status; }

    /**
     * <p>Shows whether the status of query suggestions settings is currently Active or
     * Updating.</p> <p>Active means the current settings apply and Updating means your
     * changed settings are in the process of applying.</p>
     */
    inline void SetStatus(const QuerySuggestionsStatus& value) { m_status = value; }

    /**
     * <p>Shows whether the status of query suggestions settings is currently Active or
     * Updating.</p> <p>Active means the current settings apply and Updating means your
     * changed settings are in the process of applying.</p>
     */
    inline void SetStatus(QuerySuggestionsStatus&& value) { m_status = std::move(value); }

    /**
     * <p>Shows whether the status of query suggestions settings is currently Active or
     * Updating.</p> <p>Active means the current settings apply and Updating means your
     * changed settings are in the process of applying.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithStatus(const QuerySuggestionsStatus& value) { SetStatus(value); return *this;}

    /**
     * <p>Shows whether the status of query suggestions settings is currently Active or
     * Updating.</p> <p>Active means the current settings apply and Updating means your
     * changed settings are in the process of applying.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithStatus(QuerySuggestionsStatus&& value) { SetStatus(std::move(value)); return *this;}


    /**
     * <p>Shows how recent your queries are in your query log time window (in
     * days).</p>
     */
    inline int GetQueryLogLookBackWindowInDays() const{ return m_queryLogLookBackWindowInDays; }

    /**
     * <p>Shows how recent your queries are in your query log time window (in
     * days).</p>
     */
    inline void SetQueryLogLookBackWindowInDays(int value) { m_queryLogLookBackWindowInDays = value; }

    /**
     * <p>Shows how recent your queries are in your query log time window (in
     * days).</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithQueryLogLookBackWindowInDays(int value) { SetQueryLogLookBackWindowInDays(value); return *this;}


    /**
     * <p>Shows whether Amazon Kendra uses all queries or only uses queries that
     * include user information to generate query suggestions.</p>
     */
    inline bool GetIncludeQueriesWithoutUserInformation() const{ return m_includeQueriesWithoutUserInformation; }

    /**
     * <p>Shows whether Amazon Kendra uses all queries or only uses queries that
     * include user information to generate query suggestions.</p>
     */
    inline void SetIncludeQueriesWithoutUserInformation(bool value) { m_includeQueriesWithoutUserInformation = value; }

    /**
     * <p>Shows whether Amazon Kendra uses all queries or only uses queries that
     * include user information to generate query suggestions.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithIncludeQueriesWithoutUserInformation(bool value) { SetIncludeQueriesWithoutUserInformation(value); return *this;}


    /**
     * <p>Shows the minimum number of unique users who must search a query in order for
     * the query to be eligible to suggest to your users.</p>
     */
    inline int GetMinimumNumberOfQueryingUsers() const{ return m_minimumNumberOfQueryingUsers; }

    /**
     * <p>Shows the minimum number of unique users who must search a query in order for
     * the query to be eligible to suggest to your users.</p>
     */
    inline void SetMinimumNumberOfQueryingUsers(int value) { m_minimumNumberOfQueryingUsers = value; }

    /**
     * <p>Shows the minimum number of unique users who must search a query in order for
     * the query to be eligible to suggest to your users.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithMinimumNumberOfQueryingUsers(int value) { SetMinimumNumberOfQueryingUsers(value); return *this;}


    /**
     * <p>Shows the minimum number of times a query must be searched in order for the
     * query to be eligible to suggest to your users.</p>
     */
    inline int GetMinimumQueryCount() const{ return m_minimumQueryCount; }

    /**
     * <p>Shows the minimum number of times a query must be searched in order for the
     * query to be eligible to suggest to your users.</p>
     */
    inline void SetMinimumQueryCount(int value) { m_minimumQueryCount = value; }

    /**
     * <p>Shows the minimum number of times a query must be searched in order for the
     * query to be eligible to suggest to your users.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithMinimumQueryCount(int value) { SetMinimumQueryCount(value); return *this;}


    /**
     * <p>Shows the date-time query suggestions for an index was last updated.</p>
     */
    inline const Aws::Utils::DateTime& GetLastSuggestionsBuildTime() const{ return m_lastSuggestionsBuildTime; }

    /**
     * <p>Shows the date-time query suggestions for an index was last updated.</p>
     */
    inline void SetLastSuggestionsBuildTime(const Aws::Utils::DateTime& value) { m_lastSuggestionsBuildTime = value; }

    /**
     * <p>Shows the date-time query suggestions for an index was last updated.</p>
     */
    inline void SetLastSuggestionsBuildTime(Aws::Utils::DateTime&& value) { m_lastSuggestionsBuildTime = std::move(value); }

    /**
     * <p>Shows the date-time query suggestions for an index was last updated.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithLastSuggestionsBuildTime(const Aws::Utils::DateTime& value) { SetLastSuggestionsBuildTime(value); return *this;}

    /**
     * <p>Shows the date-time query suggestions for an index was last updated.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithLastSuggestionsBuildTime(Aws::Utils::DateTime&& value) { SetLastSuggestionsBuildTime(std::move(value)); return *this;}


    /**
     * <p>Shows the date-time query suggestions for an index was last cleared.</p>
     * <p>After you clear suggestions, Amazon Kendra learns new suggestions based on
     * new queries added to the query log from the time you cleared suggestions. Amazon
     * Kendra only considers re-occurences of a query from the time you cleared
     * suggestions. </p>
     */
    inline const Aws::Utils::DateTime& GetLastClearTime() const{ return m_lastClearTime; }

    /**
     * <p>Shows the date-time query suggestions for an index was last cleared.</p>
     * <p>After you clear suggestions, Amazon Kendra learns new suggestions based on
     * new queries added to the query log from the time you cleared suggestions. Amazon
     * Kendra only considers re-occurences of a query from the time you cleared
     * suggestions. </p>
     */
    inline void SetLastClearTime(const Aws::Utils::DateTime& value) { m_lastClearTime = value; }

    /**
     * <p>Shows the date-time query suggestions for an index was last cleared.</p>
     * <p>After you clear suggestions, Amazon Kendra learns new suggestions based on
     * new queries added to the query log from the time you cleared suggestions. Amazon
     * Kendra only considers re-occurences of a query from the time you cleared
     * suggestions. </p>
     */
    inline void SetLastClearTime(Aws::Utils::DateTime&& value) { m_lastClearTime = std::move(value); }

    /**
     * <p>Shows the date-time query suggestions for an index was last cleared.</p>
     * <p>After you clear suggestions, Amazon Kendra learns new suggestions based on
     * new queries added to the query log from the time you cleared suggestions. Amazon
     * Kendra only considers re-occurences of a query from the time you cleared
     * suggestions. </p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithLastClearTime(const Aws::Utils::DateTime& value) { SetLastClearTime(value); return *this;}

    /**
     * <p>Shows the date-time query suggestions for an index was last cleared.</p>
     * <p>After you clear suggestions, Amazon Kendra learns new suggestions based on
     * new queries added to the query log from the time you cleared suggestions. Amazon
     * Kendra only considers re-occurences of a query from the time you cleared
     * suggestions. </p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithLastClearTime(Aws::Utils::DateTime&& value) { SetLastClearTime(std::move(value)); return *this;}


    /**
     * <p>Shows the current total count of query suggestions for an index.</p> <p>This
     * count can change when you update your query suggestions settings, if you filter
     * out certain queries from suggestions using a block list, and as the query log
     * accumulates more queries for Amazon Kendra to learn from.</p>
     */
    inline int GetTotalSuggestionsCount() const{ return m_totalSuggestionsCount; }

    /**
     * <p>Shows the current total count of query suggestions for an index.</p> <p>This
     * count can change when you update your query suggestions settings, if you filter
     * out certain queries from suggestions using a block list, and as the query log
     * accumulates more queries for Amazon Kendra to learn from.</p>
     */
    inline void SetTotalSuggestionsCount(int value) { m_totalSuggestionsCount = value; }

    /**
     * <p>Shows the current total count of query suggestions for an index.</p> <p>This
     * count can change when you update your query suggestions settings, if you filter
     * out certain queries from suggestions using a block list, and as the query log
     * accumulates more queries for Amazon Kendra to learn from.</p>
     */
    inline DescribeQuerySuggestionsConfigResult& WithTotalSuggestionsCount(int value) { SetTotalSuggestionsCount(value); return *this;}

  private:

    Mode m_mode;

    QuerySuggestionsStatus m_status;

    int m_queryLogLookBackWindowInDays;

    bool m_includeQueriesWithoutUserInformation;

    int m_minimumNumberOfQueryingUsers;

    int m_minimumQueryCount;

    Aws::Utils::DateTime m_lastSuggestionsBuildTime;

    Aws::Utils::DateTime m_lastClearTime;

    int m_totalSuggestionsCount;
  };

} // namespace Model
} // namespace kendra
} // namespace Aws
