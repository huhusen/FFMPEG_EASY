#include <iostream>
#include "Reader.h"
#include "Writer.h"
#include "spdlog/spdlog.h"
#include "MediaPacket.h"
#include "Decode.h"
#include "MediaCodecParameters.h"
#include "MediaFrame.h"

int main() {
    auto reader = Reader::create("input.mp4");
    if (!reader) {
        spdlog::throw_spdlog_ex("Input couldn't open ");
    }
    reader->find();
    int video_index = reader->find(MediaType::VIDEO);
    int audio_index = reader->find(MediaType::AUDIO);

    auto decode = Decode::create();

    auto videoParameter = MediaCodecParameters::create(reader->ctx()->streams[video_index]);
    spdlog::info(decode->open(videoParameter->ctx()));

    spdlog::info("video_index:{}", video_index);
    spdlog::info("audio_index:{}", audio_index);
    const char *filename = "output.mp4";
    auto writer = Writer::create(filename);

    AVStream *video = avformat_new_stream(writer->ctx(), nullptr);
    AVStream *audio = avformat_new_stream(writer->ctx(), nullptr);

    std::cout << avcodec_parameters_copy(video->codecpar, reader->ctx()->streams[video_index]->codecpar) << std::endl;
    std::cout << avcodec_parameters_copy(audio->codecpar, reader->ctx()->streams[audio_index]->codecpar) << std::endl;

    std::cout << avio_open(&writer->ctx()->pb, filename, AVIO_FLAG_WRITE) << std::endl;

    std::cout << avformat_write_header(writer->ctx(), nullptr) << std::endl;

    auto packet = MediaPacket::create();
    auto frame = MediaFrame::create();
    while (reader->read(packet->avPacket()) >= 0) {
        if (packet->avPacket()->stream_index == video_index) {
            spdlog::info("video_index.");
            if (decode->write(packet->avPacket()) >= 0) {
                auto ret = decode->read(frame->avFrame());
                spdlog::info(ret);
                if (ret >= 0) {

                }
            }
        } else if (packet->avPacket()->stream_index == audio_index) {
            spdlog::info("audio_index.");
        }
        packet->pack(reader->ctx()->streams[packet->avPacket()->stream_index]->time_base,
                     writer->ctx()->streams[packet->avPacket()->stream_index]->time_base);

        writer->write(packet->avPacket());

        av_packet_unref(packet->avPacket());
    }
    av_write_trailer(writer->ctx());

    return 0;
}
