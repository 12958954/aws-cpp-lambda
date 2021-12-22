#include "S3GetObject.h"
#include "fileSystem.h"

void S3GetObject(Aws::S3::S3Client const& client, Aws::String const& bucket, Aws::String const& key, Aws::String& output)
// pass in: S3 SDK Client, bucket name, s3 key, the return value
{
  Aws::S3::Model::GetObjectRequest request;
  request.WithBucket(bucket).WithKey(key);
  // set up the request
  
  Aws::S3::Model::GetObjectOutcome outcome = client.GetObject(request);
  // get the object
  
  if (outcome.IsSuccess())
    {
      auto& s = outcome.GetResult().GetBody();
      // get the body

      // the following outputs the s3 object to the string output
      ofstream outfile(FILEPATH + key,  std::ios::binary); // binary mode!!
      char buffer[1024]; // temporary transfer buffer
      int pcbRead; // number of bytes actually read
      // keep going as long as read was successful and we have data to write
      while(s.read(buffer, sizeof(buffer)))
	{
	  output += buffer;
	}
      return;
    }
  else
    {
      //        AWS_LOGSTREAM_ERROR(TAG, "Failed with error: " << outcome.GetError());
      return ;//outcome.GetError().GetMessage();
    }
}
