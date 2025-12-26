#include "draw.hpp"
#include "texture.hpp"
#include "window.hpp"
#include <cstddef>

namespace Draw {
    void draw_rectangle(int x, int y, int w, int h, s_color color) {
        u32 rgba_color = (color.r << 24) | (color.g << 16) | (color.b << 8) | (color.a);
        GRRLIB_Rectangle(x, y, w, h, rgba_color, true);
    }

    void draw_text(s_font font, const char* text, int x, int y, int size, s_color color) {
        GRRLIB_PrintfTTF(x, y, font.font, text, size, (color.r << 24) | (color.g << 16) | (color.b << 8) | (color.a));
    }

    void clear(s_color color) {
        GRRLIB_FillScreen((color.r << 24) | (color.g << 16) | (color.b << 8) | (color.a));
    }

    void draw_rect(int x, int y, int w, int h, s_color color) {
        u32 rgba_color = (color.r << 24) | (color.g << 16) | (color.b << 8) | (color.a);
        GRRLIB_Rectangle(x, y, w, h, rgba_color, false);
    }

    void draw_line(int x1, int y1, int x2, int y2, s_color color) {
        u32 rgba_color = (color.r << 24) | (color.g << 16) | (color.b << 8) | (color.a);
        GRRLIB_Line(x1, y1, x2, y2, rgba_color);
    }

    void draw_texture(const s_texture& texture, int x, int y) {
        GRRLIB_DrawImg(x, y, texture.tex, 0.0f, 1.0f, 1.0f, 0xFFFFFFFF);
    }

    void draw_texture_ex(const s_texture& texture, int x, int y, int w, int h, s_rect srcrect, float rotation) {
        GRRLIB_DrawImg(x, y, texture.tex, rotation, (float)w / (float)srcrect.w, (float)h / (float)srcrect.h, 0xFFFFFFFF);
    }
}