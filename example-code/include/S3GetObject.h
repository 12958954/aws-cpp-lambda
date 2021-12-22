#pragma once

#include "headers.h"

void S3GetObject(Aws::S3::S3Client const& client, Aws::String const& bucket, Aws::String const& key, Aws::String& output);
