#include "draw.hpp"
#include "texture.hpp"
#include "window.hpp"
#include <cstddef>
#include <grrlib.h>
#include <cmath>
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
            GRRLIB_texImg *tex = (GRRLIB_texImg*)texture.tex;
            
            float centerX = x + w / 2.0f;
            float centerY = y + h / 2.0f;
            
            float halfW = w / 2.0f;
            float halfH = h / 2.0f;
            
            float rad = rotation * M_PI / 180.0f;
            float cosR = cosf(rad);
            float sinR = sinf(rad);
            
            guVector quad[4];
            
            float x1 = -halfW;
            float y1 = -halfH;
            quad[0].x = centerX + (x1 * cosR - y1 * sinR);
            quad[0].y = centerY + (x1 * sinR + y1 * cosR);
            
            float x2 = halfW;
            float y2 = -halfH;
            quad[1].x = centerX + (x2 * cosR - y2 * sinR);
            quad[1].y = centerY + (x2 * sinR + y2 * cosR);
            
            float x3 = halfW;
            float y3 = halfH;
            quad[2].x = centerX + (x3 * cosR - y3 * sinR);
            quad[2].y = centerY + (x3 * sinR + y3 * cosR);
            
            float x4 = -halfW;
            float y4 = halfH;
            quad[3].x = centerX + (x4 * cosR - y4 * sinR);
            quad[3].y = centerY + (x4 * sinR + y4 * cosR);
            
            quad[0].z = quad[1].z = quad[2].z = quad[3].z = 0.0f;
            
            GRRLIB_DrawImgQuad(quad, tex, 0xFFFFFFFF);
    }
}