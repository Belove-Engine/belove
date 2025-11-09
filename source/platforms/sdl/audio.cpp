#include "audio.hpp"
#include <SDL2/SDL_audio.h>
#include <string>
#include "../../utils/log.hpp"
#include "SDL_stdinc.h"

s_audio load_audio(const char *path) {
    s_audio aud;

    aud.audio = Mix_LoadWAV(path);
    if (!aud.audio) {
        std::string error = Mix_GetError();
        Log::log(std::string("Error while loading audio, error: " + error + "\n").c_str(), Log::SEVER_ERROR);
    }
    int freq, channels;
    Uint16 format;
    if (Mix_QuerySpec(&freq, &format, &channels)) {
        int bytes_per_sample = (SDL_AUDIO_BITSIZE(format) / 8) * channels;
        int bytes_per_second = freq * bytes_per_sample;
        aud.duration = static_cast<double>(aud.audio->alen) / bytes_per_second;
    } else {
        Log::log("Couldn\'t query audio spec. (no duration available)\n", Log::SEVER_WARNING);
    }
    return aud;
}

int play_audio(s_audio audio) {
    audio.channel = Mix_PlayChannel(-1, audio.audio, 0);
    if (audio.channel == -1) {
        std::string error = Mix_GetError();
        Log::log(std::string("Error while playing audio, error: " + error + "\n").c_str(), Log::SEVER_ERROR);
        audio.audio = nullptr;
    }
    return audio.channel;   
}

void pause_audio(s_audio& audio) {
    if (audio.channel != -1) {
        Mix_Pause(audio.channel);
    }
}

void resume_audio(s_audio& audio) {
    if (audio.channel != -1) {
        Mix_Resume(audio.channel);
    }
}

void stop_audio(s_audio& audio) {
    if (audio.channel != -1) {
        Mix_HaltChannel(audio.channel);
    }
}

void free_audio(s_audio& audio) {
    if (audio.audio) {
        Mix_FreeChunk(audio.audio);
        audio.audio = nullptr;
    }
}