//
// Created by uma on 2023/6/28.
//

#ifndef FFMPEG_EASY_WRITER_H
#define FFMPEG_EASY_WRITER_H

#include "OutputFormatContext.h"

class Writer {
public:
    static Ptr<Writer> create(const char *fileName);

    int write(AVPacket *packet);

    AVFormatContext *ctx() {
        return outputFormatContext->ctx();
    }

private:
    Ptr<OutputFormatContext> outputFormatContext;
};


#endif //FFMPEG_EASY_WRITER_H
