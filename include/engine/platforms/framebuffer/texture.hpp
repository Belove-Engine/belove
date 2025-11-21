#pragma once
#include "window.hpp"

struct s_texture {
    unsigned char* tex = nullptr;
    int width = 0;
    int height = 0;
};

s_texture load_image(const char* path);
void unload_texture(s_texture& tex);