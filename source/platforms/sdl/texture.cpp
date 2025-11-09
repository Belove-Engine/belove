#include "texture.hpp"
#include "../../utils/log.hpp"
#include <string>
s_texture load_image(const char *path) {
    s_texture tex;
    SDL_Surface* surface = IMG_Load(path);
    if (surface != nullptr) {
        Log::log(std::string("Couldn\'t find the image: " + std::string(path) + "\n").c_str(), Log::SEVER_ERROR);
    };

    tex.tex = SDL_CreateTextureFromSurface(sdl_renderer, surface);
    tex.width = surface->w;
    tex.height = surface->h;
    SDL_FreeSurface(surface);

    return tex;
}

void unload_texture(s_texture& tex) {
    if (tex.tex) SDL_DestroyTexture(tex.tex);
    tex.tex = nullptr;
}