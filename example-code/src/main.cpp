#include "buildResponse.h"
#include "fileSystem.h"
#include "S3GetObject.h"
#include "DynamoDB.h"

#include <ctime>
#include <chrono>
#include <algorithm>

const string REGION = "us-west-1";

static invocation_response my_handler(invocation_request const& request)
{
  JsonValue payload(request.payload);
  JsonView input = payload.View();
  // Parse the input

  return invocation_response::success(buildResponse(200, input), "application/json");
  // on success, output the input got from API Gateway
}

int main()
{
  using namespace Aws;
  SDKOptions options;
  options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Trace;
  InitAPI(options);
  {
    /*
    Client::ClientConfiguration config;
    config.region = REGION; //Aws::Environment::GetEnv("AWS_REGION");
    config.caFile = "/etc/pki/tls/certs/ca-bundle.crt";
    config.disableExpectHeader = true;
    auto credentialsProvider = Aws::MakeShared<Aws::Auth::EnvironmentAWSCredentialsProvider>(TAG);
    S3::S3Client s3Client(credentialsProvider, config);
    Aws::DynamoDB::DynamoDBClient dynamoDBClient(credentialsProvider, config);
    // this is to set up the SDK for S3 and DynamoDB. Once their clients are set up, pass them to my_handler as parameters.
    */
    auto handler_fn = [](aws::lambda_runtime::invocation_request const& req)
    {
      return my_handler(req);
    };
    run_handler(handler_fn);
  }
  ShutdownAPI(options);
  return 0;
}
