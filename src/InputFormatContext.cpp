//
// Created by uma on 2023/6/28.
//

#include "InputFormatContext.h"

Ptr<InputFormatContext> InputFormatContext::create() {
    Ptr<InputFormatContext> ifx{new InputFormatContext};
    ifx->fmtCtx = avformat_alloc_context();
    return ifx;
}

Ptr<InputFormatContext> InputFormatContext::create(const char *url) {
    return create(url, nullptr, nullptr);
}

Ptr<InputFormatContext> InputFormatContext::create(const char *url, AVInputFormat *format, AVDictionary **options) {
    Ptr<InputFormatContext> ifx{new InputFormatContext};
    avformat_open_input(&ifx->fmtCtx, url, format, options);
    return ifx;
}

InputFormatContext::~InputFormatContext() noexcept {
    avformat_close_input(&this->fmtCtx);
}