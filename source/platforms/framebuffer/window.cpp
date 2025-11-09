#include "window.hpp"
#include <cstring>
#include <new>

uint8_t* fb = nullptr;
int win_width = 0;
int win_height = 0;

void window(int width, int height, const char* title) {
    if (fb) {
        delete[] fb;
    }

    // Allocate new framebuffer
    size_t buffer_size = width * height * 4;
    fb = new uint8_t[buffer_size];
    
    if (!fb) {
        return;
    }

    // Initialize framebuffer to zero
    std::memset(fb, 0, buffer_size);
    
    win_width = width;
    win_height = height;
}

void start_frametimer(int *start) {
    //*start = (int)SDL_GetTicks();
}

void end_frametimer(int start, int targetFPS) {
    // int frametime = (int)SDL_GetTicks() - start;
    // int frameDelay = 1000 / targetFPS;
    // if (frameDelay > frametime)
    //     SDL_Delay(frameDelay - frametime);
}

void close_window() {
    if (fb) {
        delete[] fb;
        fb = nullptr;
    }
    win_width = 0;
    win_height = 0;
}