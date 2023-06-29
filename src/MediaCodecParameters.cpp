//
// Created by ndk on 2023/6/29.
//

#include "MediaCodecParameters.h"


Ptr<MediaCodecParameters> MediaCodecParameters::create() {
    Ptr<MediaCodecParameters> codecParameters{new MediaCodecParameters};
    codecParameters->avCodecParameters = avcodec_parameters_alloc();
    return codecParameters;
}

Ptr<MediaCodecParameters> MediaCodecParameters::create(const AVStream *stream) {
    auto codecParameters = create();
    avcodec_parameters_copy(codecParameters->ctx(), stream->codecpar);
    return codecParameters;
}

MediaCodecParameters::~MediaCodecParameters() {
    avcodec_parameters_free(&this->avCodecParameters);
}