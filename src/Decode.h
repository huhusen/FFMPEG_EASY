//
// Created by ndk on 2023/6/28.
//

#ifndef FFMPEG_EASY_DECODE_H
#define FFMPEG_EASY_DECODE_H

#include "common.h"


class Decode {
public:
    static Ptr<Decode> create(const AVCodec *codec = nullptr);

    int open(const AVCodecParameters *params, AVDictionary **options = nullptr);

    int write(AVPacket *packet);

    int read(AVFrame *frame);

    ~Decode();

    AVCodecContext *ctx() {
        return avCodecContext;
    }

private:
    AVCodecContext *avCodecContext;
};


#endif //FFMPEG_EASY_DECODE_H
