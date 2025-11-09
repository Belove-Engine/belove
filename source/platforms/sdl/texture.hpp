#pragma once
#include "window.hpp"


struct s_texture {
    SDL_Texture* tex = nullptr;
    int width = 0;
    int height = 0;
};

s_texture load_image(const char* path);
void unload_texture(s_texture& tex);