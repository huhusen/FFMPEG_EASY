//
// Created by uma on 2023/6/28.
//

#include "OutputFormatContext.h"

Ptr<OutputFormatContext> OutputFormatContext::create() {
    Ptr<OutputFormatContext> ofx{new OutputFormatContext};
    ofx->fmtCtx = avformat_alloc_context();
    return ofx;
}

Ptr<OutputFormatContext> OutputFormatContext::create(const char *filename) {
    return create(nullptr, nullptr, filename);
}

Ptr<OutputFormatContext>
OutputFormatContext::create(const AVOutputFormat *outputFormat, const char *format_name, const char *filename) {
    Ptr<OutputFormatContext> ofx{new OutputFormatContext};

    avformat_alloc_output_context2(&ofx->fmtCtx, outputFormat, format_name, filename);
    return ofx;
}

OutputFormatContext::~OutputFormatContext() {
    avformat_close_input(&this->fmtCtx);
}
