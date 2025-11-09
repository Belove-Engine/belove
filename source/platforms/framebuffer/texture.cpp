#include "texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../include/stb_image.h"

s_texture load_image(const char *path) {
    s_texture tex;
    tex.tex = stbi_load(path, &tex.width, &tex.height, nullptr, 4);
    if (!tex.tex) {
        tex.width = 0;
        tex.height = 0;
    }
    return tex;
}

void unload_texture(s_texture& tex) {
    stbi_image_free(tex.tex);
    tex.tex = nullptr;
}