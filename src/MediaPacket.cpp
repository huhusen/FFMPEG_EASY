//
// Created by uma on 2023/6/28.
//

#include "MediaPacket.h"

Ptr<MediaPacket> MediaPacket::create() {
    Ptr<MediaPacket> mediaPacket{new MediaPacket};
    mediaPacket->_avPacket = av_packet_alloc();
    return mediaPacket;
}

void MediaPacket::pack(const AVRational &src, const AVRational &dest) {
    av_packet_rescale_ts(this->_avPacket, src, dest);
}


MediaPacket::~MediaPacket() {
    av_packet_free(&this->_avPacket);
}