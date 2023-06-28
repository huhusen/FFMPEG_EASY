//
// Created by uma on 2023/6/28.
//

#ifndef FFMPEG_EASY_MEDIAPACKET_H
#define FFMPEG_EASY_MEDIAPACKET_H

#include "common.h"

class MediaPacket {
public:
    static Ptr<MediaPacket> create();

    ~MediaPacket();

    void pack(const AVRational &src, const AVRational &dest);

    AVPacket *avPacket() {
        return _avPacket;
    }

private:
    AVPacket *_avPacket = {nullptr};
};


#endif //FFMPEG_EASY_MEDIAPACKET_H
