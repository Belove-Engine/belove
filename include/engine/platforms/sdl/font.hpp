#pragma once
#include <SDL2/SDL_ttf.h>
struct s_font {
    TTF_Font *font;
    int size;
};

s_font load_font(const char* path, int base_size);
void unload_font(s_font font);