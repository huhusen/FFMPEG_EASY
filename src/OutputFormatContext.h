//
// Created by uma on 2023/6/28.
//

#ifndef FFMPEG_EASY_OUTPUTFORMATCONTEXT_H
#define FFMPEG_EASY_OUTPUTFORMATCONTEXT_H

#include "common.h"

class OutputFormatContext {
public:
    static Ptr<OutputFormatContext> create();

    static Ptr<OutputFormatContext> create(const char *filename);

    static Ptr<OutputFormatContext>
    create(const AVOutputFormat *outputFormat, const char *format_name, const char *filename);

    ~OutputFormatContext();

    AVFormatContext *ctx() {
        return fmtCtx;
    }

private:
    AVFormatContext *fmtCtx{nullptr};
};


#endif //FFMPEG_EASY_OUTPUTFORMATCONTEXT_H
