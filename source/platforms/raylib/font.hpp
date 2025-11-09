#pragma once
#include <raylib.h>
struct s_font {
    Font font;
    int size;
};

s_font load_font(const char* path);
void unload_font(s_font font);