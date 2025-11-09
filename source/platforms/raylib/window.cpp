#include "window.hpp"
#include <raylib.h>

void window(int width, int height, const char* title) {
    InitWindow(width, height, title);
    InitAudioDevice();
    SetTargetFPS(60);
}


// raylib will handle fps with SetTargetFPS
void start_frametimer(int *start) {};
void end_frametimer(int start, int targetFPS) {};

void close_window() {
    CloseWindow();
}