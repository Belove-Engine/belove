// why the fuck raylib doesn't return error codes??? :sob:
#include "audio.hpp"
#include <raylib.h>

s_audio load_audio(const char *path) {
    s_audio aud;

    aud.audio = LoadMusicStream(path);
    aud.duration = GetMusicTimeLength(aud.audio);
    return aud;
}

int play_audio(s_audio audio) {
    PlayMusicStream(audio.audio);
    return 0;
}

void pause_audio(s_audio& audio) {
    PauseMusicStream(audio.audio);
}

void resume_audio(s_audio& audio) {
    ResumeMusicStream(audio.audio);
}

void stop_audio(s_audio& audio) {
    StopMusicStream(audio.audio);
}

void free_audio(s_audio& audio) {
    UnloadMusicStream(audio.audio);
}