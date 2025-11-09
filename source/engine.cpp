#include "engine.hpp"
#include "platforms/sdl/window.hpp"
#include <raylib.h>

Engine::Engine(int w, int h, const std::string& t)
    : width(w), height(h), title(t), running(false) {}

Engine::~Engine() {
    close_window();
}

bool Engine::init() {
    Input::init();
    window(width, height, title.c_str());
    running = true;
    ready();
    return true;
}

void Engine::handleInput() {
    Input::update();
}

void Engine::run() {
    int frame_start;
    while (running) {
        start_frametimer(&frame_start);

        handleInput();
        update();
// HACK: quick fix for rendering in raylib (start rendering)
#ifdef PLAT_RAYLIB
        BeginDrawing();
#endif
        render();

// HACK: quick fix for rendering in sdl
#ifdef PLAT_SDL
        SDL_RenderPresent(sdl_renderer);
#endif
        end_frametimer(frame_start, 60);
// HACK: quick fix for rendering in raylib (end rendering)
#ifdef PLAT_RAYLIB
        EndDrawing();
#endif

    }
}
