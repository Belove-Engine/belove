#pragma once
#include <grrlib.h>

struct s_font {
    GRRLIB_ttfFont *font;
    int size;
};

s_font load_font(const char* path, int base_size);
void unload_font(s_font font);