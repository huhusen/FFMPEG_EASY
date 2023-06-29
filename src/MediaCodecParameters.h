//
// Created by ndk on 2023/6/29.
//

#ifndef FFMPEG_EASY_MEDIACODECPARAMETERS_H
#define FFMPEG_EASY_MEDIACODECPARAMETERS_H

#include "common.h"

class MediaCodecParameters {
public:
    static Ptr<MediaCodecParameters> create();
    static Ptr<MediaCodecParameters> create(const AVStream *stream);


    ~MediaCodecParameters();

    AVCodecParameters *ctx() {
        return avCodecParameters;
    }

private:
    AVCodecParameters *avCodecParameters;
};


#endif //FFMPEG_EASY_MEDIACODECPARAMETERS_H
