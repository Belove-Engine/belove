#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

inline SDL_Renderer *sdl_renderer;
inline SDL_Window *sdl_window;

void window(int width, int height, const char* title);

void start_frametimer(int *start);

void end_frametimer(int start, int targetFPS);

void close_window();