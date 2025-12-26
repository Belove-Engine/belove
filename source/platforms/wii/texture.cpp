#include "texture.hpp"
#include <grrlib.h>

s_texture load_image(const char *path) {
    s_texture tex;
    tex.tex = GRRLIB_LoadTextureFromFile(path);
    if (!tex.tex) {
        tex.width = 0;
        tex.height = 0;
    }
    return tex;
}

void unload_texture(s_texture& tex) {
    GRRLIB_FreeTexture(tex.tex);
    tex.tex = nullptr;
}