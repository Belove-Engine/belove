#include "font.hpp"
#include <raylib.h>

s_font load_font(const char* path, int base_size) {
    s_font font;
    font.font = LoadFont(path);
    font.size = base_size;
    return font;
}

void unload_font(s_font font) {
    UnloadFont(font.font);
}