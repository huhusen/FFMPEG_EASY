//
// Created by uma on 2023/6/28.
//

#ifndef FFMPEG_EASY_COMMON_H
#define FFMPEG_EASY_COMMON_H

#include <cstring>
#include <memory>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>
#include "spdlog/spdlog.h"

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
#include <libswresample/swresample.h>
#include <libswscale/swscale.h>
}

template<typename T>
using Ptr = std::shared_ptr<T>;

#endif //FFMPEG_EASY_COMMON_H
