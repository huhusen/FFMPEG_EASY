//
// Created by uma on 2023/6/28.
//

#ifndef FFMPEG_EASY_READER_H
#define FFMPEG_EASY_READER_H

#include "InputFormatContext.h"

enum class MediaType {
    VIDEO,
    AUDIO
};

class Reader {
public:
    static Ptr<Reader> create(const char *url);

    int find(AVDictionary **options = nullptr);

    int find(MediaType type);

    int read(AVPacket *packet);


    AVFormatContext *ctx() {
        return inputFormatContext->ctx();
    }

private:
    Ptr<InputFormatContext> inputFormatContext;

};


#endif //FFMPEG_EASY_READER_H
