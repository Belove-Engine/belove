#include "window.hpp"
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>
#include <mp3player.h>

int win_width = 0;
int win_height = 0;

void window(int width, int height, const char* title) {
    GRRLIB_Init();
    
    ASND_Init();
	MP3Player_Init();

    // not that will matter, but meh
    win_width = width;
    win_height = height;
}

void start_frametimer(int *start) {
    // TODO: implement frame timer for wii
    //*start = (int)SDL_GetTicks();
}

void end_frametimer(int start, int targetFPS) {
    // int frametime = (int)SDL_GetTicks() - start;
    // int frameDelay = 1000 / targetFPS;
    // if (frameDelay > frametime)
    //     SDL_Delay(frameDelay - frametime);
}

void close_window() {
    win_width = 0;
    win_height = 0;
    GRRLIB_Exit();
}