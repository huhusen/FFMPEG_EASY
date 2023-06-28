//
// Created by uma on 2023/6/28.
//

#include "Reader.h"

Ptr<Reader> Reader::create(const char *url) {
    Ptr<Reader> reader{new Reader};
    reader->inputFormatContext = InputFormatContext::create(url);


    return reader;
}

int Reader::find(AVDictionary **options) {
    return avformat_find_stream_info(this->inputFormatContext->ctx(), options);
}

int Reader::find(MediaType type) {
    AVMediaType ff_type;
    switch (type) {
        case MediaType::VIDEO:
            ff_type = AVMEDIA_TYPE_VIDEO;
            break;
        case MediaType::AUDIO:
            ff_type = AVMEDIA_TYPE_AUDIO;
            break;
        default:
            return -1;
    }
    return av_find_best_stream(this->inputFormatContext->ctx(), ff_type, -1, -1, nullptr, 0);
}

int Reader::read(AVPacket *packet) {
    return av_read_frame(this->ctx(), packet);
}