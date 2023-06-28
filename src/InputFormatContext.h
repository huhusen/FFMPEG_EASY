//
// Created by uma on 2023/6/28.
//

#ifndef FFMPEG_EASY_INPUTFORMATCONTEXT_H
#define FFMPEG_EASY_INPUTFORMATCONTEXT_H

#include "common.h"

class InputFormatContext {
public:

    static Ptr<InputFormatContext> create();

    static Ptr<InputFormatContext> create(const char *url);

    static Ptr<InputFormatContext> create(const char *url, AVInputFormat *format, AVDictionary **options);

    ~InputFormatContext();

    AVFormatContext *ctx() {
        return fmtCtx;
    }

private:
    AVFormatContext *fmtCtx{nullptr};
};


#endif //FFMPEG_EASY_INPUTFORMATCONTEXT_H
