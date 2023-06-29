//
// Created by ndk on 2023/6/28.
//

#include "Decode.h"

Ptr<Decode> Decode::create(const AVCodec *codec) {
    Ptr<Decode> decode{new Decode};
    decode->avCodecContext = avcodec_alloc_context3(codec);
    return decode;
}

int Decode::open(const AVCodecParameters *params, AVDictionary **options) {
    const AVCodec *codec = avcodec_find_decoder(params->codec_id);
    spdlog::info(avcodec_parameters_to_context(this->avCodecContext, params));
    return avcodec_open2(this->avCodecContext, codec, options);
}

int Decode::write(AVPacket *packet) {
    return avcodec_send_packet(this->avCodecContext, packet);
}

int Decode::read(AVFrame *frame) {
    return avcodec_receive_frame(this->avCodecContext, frame);
}

Decode::~Decode() {
    avcodec_free_context(&this->avCodecContext);
}