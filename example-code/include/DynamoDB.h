#pragma once

#include "headers.h"

JsonValue DynamoGetItem(Aws::DynamoDB::DynamoDBClient const& dynamoClient, JsonView parameter);
