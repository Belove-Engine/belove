#pragma once 
#include "../../utils/color.hpp"
#include "../../utils/rect.hpp"
#include "font.hpp"
#include "texture.hpp"

namespace Draw {
    void draw_rectangle(int posX, int posY, int width, int height, s_color color);

    void draw_text(s_font font, const char* text, int x, int y, int size, s_color color);

    void clear(s_color color);
    
    void draw_rect(int x, int y, int w, int h, s_color color);
    
    void draw_line(int x1, int y1, int x2, int y2, s_color color);
    
    void draw_texture(const s_texture& texture, int x, int y);

    void draw_texture_ex(const s_texture& texture, int x, int y, int w, int h, s_rect srcrect, float rotation);
}