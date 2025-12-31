#include "window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
#include <string>
#include "../../utils/log.hpp"

void window(int width, int height, const char* title) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
    IMG_Init(IMG_INIT_PNG);

    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) != (MIX_INIT_MP3 | MIX_INIT_OGG)) {
        Log::log(("Mix_Init failed: " + std::string(Mix_GetError()) + "\n").c_str(), Log::SEVER_FATAL);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        Log::log(("Mix_OpenAudio failed: " + std::string(Mix_GetError()) + "\n").c_str(), Log::SEVER_FATAL);
    }

    if (TTF_Init() < 0) {
        Log::log(("TTF_Init failed: " + std::string(TTF_GetError()) + "\n").c_str(), Log::SEVER_FATAL);
    }

    sdl_window = SDL_CreateWindow(title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        0
    );

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
}

void start_frametimer(int *start) {
    *start = (int)SDL_GetTicks();
}

void end_frametimer(int start, int targetFPS) {
    int frametime = (int)SDL_GetTicks() - start;
    int frameDelay = 1000 / targetFPS;
    if (frameDelay > frametime)
        SDL_Delay(frameDelay - frametime);
}

void close_window() {
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    exit(0);
}