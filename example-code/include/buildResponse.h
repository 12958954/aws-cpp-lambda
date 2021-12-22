#pragma once

#include "headers.h"

Aws::String buildResponse(int statusCode, JsonValue body);
Aws::String buildResponse(int statusCode, JsonView body);
Aws::String buildResponse(int statusCode, string body);
