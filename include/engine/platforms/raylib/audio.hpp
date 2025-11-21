#pragma once
#include <raylib.h>

struct s_audio {
    Music audio;
    float duration;
};

s_audio load_audio(const char* path);
int play_audio(s_audio audio);
void pause_audio(s_audio& audio);
void resume_audio(s_audio& audio);
void stop_audio(s_audio& audio);
void free_audio(s_audio& audio);