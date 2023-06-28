//
// Created by uma on 2023/6/28.
//

#include "Writer.h"

Ptr<Writer> Writer::create(const char *fileName) {
    Ptr<Writer> writer{new Writer};
    writer->outputFormatContext = OutputFormatContext::create(fileName);
    return writer;
}

int Writer::write(AVPacket *packet) {
    return av_interleaved_write_frame(this->outputFormatContext->ctx(), packet);
}