cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(hello LANGUAGES CXX)

find_package(aws-lambda-runtime REQUIRED)
find_package(AWSSDK COMPONENTS core dynamodb s3)

include_directories(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
  "src/main.cpp"
  "src/buildResponse.cpp"
  "src/fileSystem.cpp"
  "src/DynamoDB.cpp"
  "src/S3GetObject.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC
  AWS::aws-lambda-runtime ${AWSSDK_LINK_LIBRARIES} )

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

aws_lambda_package_target(${PROJECT_NAME})