#pragma once

#include <aws/core/auth/AWSCredentialsProvider.h>
#include <aws/core/Aws.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/platform/Environment.h>
#include <aws/core/utils/Array.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/logging/ConsoleLogSystem.h>
#include <aws/core/utils/logging/LogLevel.h>
#include <aws/core/utils/logging/LogMacros.h>
#include <aws/core/utils/memory/stl/SimpleStringStream.h>
#include <aws/core/utils/Outcome.h>
/*
// DynamoDB required SDK
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/GetItemRequest.h>
#include <aws/dynamodb/model/QueryRequest.h>*/

#include <aws/lambda-runtime/runtime.h>

//#include <aws/s3/S3Client.h>
//#include <aws/s3/model/GetObjectRequest.h>
// S3 requierd SDK

using namespace aws::lambda_runtime;
using namespace Aws::Utils::Json;
using namespace Aws;

#include <iostream>
#include <cstring>
#include <ctime>
#include <sstream>

using namespace std;

char const TAG[] = "LAMBDA_ALLOC";
