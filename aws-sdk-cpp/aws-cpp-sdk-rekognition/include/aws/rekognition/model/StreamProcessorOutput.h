/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/rekognition/Rekognition_EXPORTS.h>
#include <aws/rekognition/model/KinesisDataStream.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace Rekognition
{
namespace Model
{

  /**
   * <p>Information about the Amazon Kinesis Data Streams stream to which a Amazon
   * Rekognition Video stream processor streams the results of a video analysis. For
   * more information, see CreateStreamProcessor in the Amazon Rekognition Developer
   * Guide.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/rekognition-2016-06-27/StreamProcessorOutput">AWS
   * API Reference</a></p>
   */
  class AWS_REKOGNITION_API StreamProcessorOutput
  {
  public:
    StreamProcessorOutput();
    StreamProcessorOutput(Aws::Utils::Json::JsonView jsonValue);
    StreamProcessorOutput& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The Amazon Kinesis Data Streams stream to which the Amazon Rekognition stream
     * processor streams the analysis results.</p>
     */
    inline const KinesisDataStream& GetKinesisDataStream() const{ return m_kinesisDataStream; }

    /**
     * <p>The Amazon Kinesis Data Streams stream to which the Amazon Rekognition stream
     * processor streams the analysis results.</p>
     */
    inline bool KinesisDataStreamHasBeenSet() const { return m_kinesisDataStreamHasBeenSet; }

    /**
     * <p>The Amazon Kinesis Data Streams stream to which the Amazon Rekognition stream
     * processor streams the analysis results.</p>
     */
    inline void SetKinesisDataStream(const KinesisDataStream& value) { m_kinesisDataStreamHasBeenSet = true; m_kinesisDataStream = value; }

    /**
     * <p>The Amazon Kinesis Data Streams stream to which the Amazon Rekognition stream
     * processor streams the analysis results.</p>
     */
    inline void SetKinesisDataStream(KinesisDataStream&& value) { m_kinesisDataStreamHasBeenSet = true; m_kinesisDataStream = std::move(value); }

    /**
     * <p>The Amazon Kinesis Data Streams stream to which the Amazon Rekognition stream
     * processor streams the analysis results.</p>
     */
    inline StreamProcessorOutput& WithKinesisDataStream(const KinesisDataStream& value) { SetKinesisDataStream(value); return *this;}

    /**
     * <p>The Amazon Kinesis Data Streams stream to which the Amazon Rekognition stream
     * processor streams the analysis results.</p>
     */
    inline StreamProcessorOutput& WithKinesisDataStream(KinesisDataStream&& value) { SetKinesisDataStream(std::move(value)); return *this;}

  private:

    KinesisDataStream m_kinesisDataStream;
    bool m_kinesisDataStreamHasBeenSet;
  };

} // namespace Model
} // namespace Rekognition
} // namespace Aws
