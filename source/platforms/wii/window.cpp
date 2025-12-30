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
    // there is no limit to fps on wii, so do nothing
    // ntsc 60hz
    // pal 50hz
}

void end_frametimer(int start, int targetFPS) {

}

void close_window() {
    win_width = 0;
    win_height = 0;
    GRRLIB_Exit();
}