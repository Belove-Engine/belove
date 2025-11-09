#include "draw.hpp"
#include "font.hpp"
#include <raylib.h>

namespace Draw {
    void draw_rectangle(int x, int y, int w, int h, s_color color) {
        DrawRectangle(x, y, w, h, {static_cast<unsigned char>(color.r), static_cast<unsigned char>(color.g), static_cast<unsigned char>(color.b), static_cast<unsigned char>(color.a)});
    }

    void draw_text(s_font font, const char* text, int x, int y, int size, s_color color) {
        DrawTextEx(font.font, text, {static_cast<float>(x), static_cast<float>(y)}, size, 2.0f, {static_cast<unsigned char>(color.r), static_cast<unsigned char>(color.g), static_cast<unsigned char>(color.b), static_cast<unsigned char>(color.a)});
    }

    void clear(s_color color) {
        ClearBackground({static_cast<unsigned char>(color.r), static_cast<unsigned char>(color.g), static_cast<unsigned char>(color.b), static_cast<unsigned char>(color.a)});
    }

    void draw_rect(int x, int y, int w, int h, s_color color) {
        DrawRectangleLines(x, y, w, h, {static_cast<unsigned char>(color.r), static_cast<unsigned char>(color.g), static_cast<unsigned char>(color.b), static_cast<unsigned char>(color.a)});
    }

    void draw_line(int x1, int y1, int x2, int y2, s_color color) {
        DrawLine(x1, y1, x2, y2, {static_cast<unsigned char>(color.r), static_cast<unsigned char>(color.g), static_cast<unsigned char>(color.b), static_cast<unsigned char>(color.a)});
    }

    void draw_texture(const s_texture &texture, int x, int y) {
        DrawTexture(texture.tex, x, y, WHITE);
    }

    void draw_texture_ex(const s_texture& texture, int x, int y, int w, int h, s_rect srcrect, float rotation) {
        DrawTexturePro(
            texture.tex,
            {static_cast<float>(srcrect.x), static_cast<float>(srcrect.y), static_cast<float>(srcrect.w), static_cast<float>(srcrect.h)},
            {static_cast<float>(x), static_cast<float>(y), static_cast<float>(texture.width), static_cast<float>(texture.height)},
            {static_cast<float>(x), static_cast<float>(y)},
            rotation,
            WHITE
        );    
    }
}