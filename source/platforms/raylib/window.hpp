#pragma once
#include <raylib.h>

void window(int width, int height, const char* title);

void start_frametimer(int *start);

void end_frametimer(int start, int targetFPS);

void close_window();