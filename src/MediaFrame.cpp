//
// Created by ndk on 2023/6/29.
//

#include "MediaFrame.h"

Ptr<MediaFrame> MediaFrame::create() {
    Ptr<MediaFrame> mediaFrame{new MediaFrame};
    mediaFrame->_avFrame = av_frame_alloc();
    return mediaFrame;
}

MediaFrame::~MediaFrame() {
    av_frame_free(&_avFrame);
}