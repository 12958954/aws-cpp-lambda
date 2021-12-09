﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/mediaconvert/model/HlsAudioOnlyHeader.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace MediaConvert
  {
    namespace Model
    {
      namespace HlsAudioOnlyHeaderMapper
      {

        static const int INCLUDE_HASH = HashingUtils::HashString("INCLUDE");
        static const int EXCLUDE_HASH = HashingUtils::HashString("EXCLUDE");


        HlsAudioOnlyHeader GetHlsAudioOnlyHeaderForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == INCLUDE_HASH)
          {
            return HlsAudioOnlyHeader::INCLUDE;
          }
          else if (hashCode == EXCLUDE_HASH)
          {
            return HlsAudioOnlyHeader::EXCLUDE;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<HlsAudioOnlyHeader>(hashCode);
          }

          return HlsAudioOnlyHeader::NOT_SET;
        }

        Aws::String GetNameForHlsAudioOnlyHeader(HlsAudioOnlyHeader enumValue)
        {
          switch(enumValue)
          {
          case HlsAudioOnlyHeader::INCLUDE:
            return "INCLUDE";
          case HlsAudioOnlyHeader::EXCLUDE:
            return "EXCLUDE";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace HlsAudioOnlyHeaderMapper
    } // namespace Model
  } // namespace MediaConvert
} // namespace Aws
