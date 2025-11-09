#include "font.hpp"
#include <SDL2/SDL_ttf.h>
s_font load_font(const char* path, int base_size) {
    s_font font;
    font.font = TTF_OpenFont(path, base_size);
    font.size = base_size;
    return font;
}
void unload_font(s_font font) {
    TTF_CloseFont(font.font);
    font.font = nullptr;
}