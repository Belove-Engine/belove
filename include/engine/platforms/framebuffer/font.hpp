#pragma once
struct s_font {
    void *font;
    int size;
};

s_font load_font(const char* path, int base_size);
void unload_font(s_font font);