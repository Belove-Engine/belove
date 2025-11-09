#include "texture.hpp"

s_texture load_image(const char *path) {
    s_texture tex;
    tex.tex = LoadTexture(path);
    tex.width = tex.tex.width;
    tex.height = tex.tex.height;

    return tex;
}

void unload_texture(s_texture& tex) {
    UnloadTexture(tex.tex);
}