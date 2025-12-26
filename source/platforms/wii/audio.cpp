#include "audio.hpp"
#include <stdlib.h>
#include <cstdio>
#include <malloc.h>

s_audio load_audio(const char *path) {
    s_audio audio;
    
    FILE* file = fopen(path, "rb");
    if (!file) {
        printf("Failed to open audio file: %s\n", path);
        return audio;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    audio.audio = memalign(32, file_size);
    if (!audio.audio) {
        printf("Failed to allocate memory for audio\n");
        fclose(file);
        return audio;
    }
    
    size_t bytes_read = fread(audio.audio, 1, file_size, file);
    fclose(file);
    
    if (bytes_read != file_size) {
        printf("Failed to read audio file completely\n");
        free(audio.audio);
        audio.audio = nullptr;
        return audio;
    }
        
    audio.duration = (float)file_size / 16000.0f;
}

int play_audio(s_audio audio) {
    // set the 2 argument to the inverse of (float)file_size / 16000.0f
    MP3Player_PlayBuffer(audio.audio, (s32)(audio.duration * 16000), nullptr);
    return 0;
}

void pause_audio(s_audio& audio) {
    ASND_Pause(0);
}

void resume_audio(s_audio& audio) {
    ASND_Pause(1);
}

void stop_audio(s_audio& audio) {
    MP3Player_Stop();
}

void free_audio(s_audio& audio) {
    if (audio.audio) {
        free(audio.audio);
        audio.audio = nullptr;
    }
}