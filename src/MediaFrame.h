//
// Created by ndk on 2023/6/29.
//

#ifndef FFMPEG_EASY_MEDIAFRAME_H
#define FFMPEG_EASY_MEDIAFRAME_H

#include "common.h"

class MediaFrame {
public:
    static Ptr<MediaFrame> create();


    ~MediaFrame();

    AVFrame *avFrame() {
        return _avFrame;
    }

private:
    AVFrame *_avFrame;
};


#endif //FFMPEG_EASY_MEDIAFRAME_H
