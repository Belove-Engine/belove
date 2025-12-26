#pragma once
#include <grrlib.h>

extern int win_width;
extern int win_height;

void window(int width, int height, const char* title);

void start_frametimer(int *start);

void end_frametimer(int start, int targetFPS);

void close_window();