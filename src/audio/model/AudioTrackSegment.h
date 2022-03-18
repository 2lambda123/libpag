/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making libpag available.
//
//  Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifdef FILE_MOVIE

#include "audio/model/AudioSource.h"

namespace pag {
static int TRACK_ID_INVALID = -1;
static const TimeRange TimeRangeInvalid = {-1, -1};

struct TimeMapping {
  TimeRange source = TimeRangeInvalid;
  TimeRange target = TimeRangeInvalid;
};

struct AudioTrackSegment {
  AudioTrackSegment(AudioSource mediaSource, int trackID, const TimeRange& source,
                    const TimeRange& target);

  explicit AudioTrackSegment(const TimeRange& target);

  AudioSource source{};
  int sourceTrackID = TRACK_ID_INVALID;
  TimeMapping timeMapping{};

  // 空
  bool isEmpty() const {
    return timeMapping.source.start == TimeRangeInvalid.start &&
           timeMapping.source.end == TimeRangeInvalid.end;
  }
};
}  // namespace pag

#endif
