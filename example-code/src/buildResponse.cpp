#include "buildResponse.h"

// build the response sent back to API Gateway
Aws::String buildResponse(int statusCode, JsonValue body)
{
  JsonValue re, headers;
  headers.WithString("Content-Type","application/json");
  re.WithObject("headers",headers);
  re.WithInteger("statusCode",statusCode);
  re.WithString("body",body.View().WriteCompact());
  re.WithBool("isBase64Encoded",true);
  return re.View().WriteCompact();
}
Aws::String buildResponse(int statusCode, JsonView body)
{
  JsonValue re, headers;
  headers.WithString("Content-Type","application/json");
  re.WithObject("headers",headers);
  re.WithInteger("statusCode",statusCode);
  re.WithString("body",body.WriteCompact());
  re.WithBool("isBase64Encoded",true);
  return re.View().WriteCompact();
}
Aws::String buildResponse(int statusCode, string body)
{
  JsonValue re, headers;
  headers.WithString("Content-Type","application/json");
  re.WithObject("headers",headers);
  re.WithInteger("statusCode",statusCode);
  re.WithString("body",body);
  re.WithBool("isBase64Encoded",true);
  return re.View().WriteCompact();
}
