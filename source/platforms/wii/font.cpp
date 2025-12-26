#include "font.hpp"
s_font load_font(const char* path, int base_size) {
    s_font font;
    font.font = GRRLIB_LoadTTFFromFile(path);
    font.size = base_size;
    return font;
}
void unload_font(s_font font) {
    GRRLIB_FreeTTF(font.font);
    font.font = nullptr;
}