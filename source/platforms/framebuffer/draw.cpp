#include "draw.hpp"
#include "texture.hpp"
#include "window.hpp"
#include <cstddef>

namespace Draw {
    void draw_rectangle(int x, int y, int w, int h, s_color color) {
        for (int width = 0; width < w; width++) {
            for (int height = 0; height < h; height++) {
                int px = x + width;
                int py = y + height;
                if (px >= 0 && px < win_width && py >= 0 && py < win_height) {
                    int index = (py * win_width + px) * 4;
                    fb[index] = color.r;
                    fb[index + 1] = color.g;
                    fb[index + 2] = color.b;
                    fb[index + 3] = color.a;
                }
            }        
        }
    }

    void draw_text(s_font font, const char* text, int x, int y, int size, s_color color) {
    }

    void clear(s_color color) {
        for (int i = 0; i < win_width * win_height; i++) {
            fb[i * 4] = color.r;
            fb[i * 4 + 1] = color.g;
            fb[i * 4 + 2] = color.b;
            fb[i * 4 + 3] = color.a;
        }
    }

    void draw_rect(int x, int y, int w, int h, s_color color) {
        draw_line(x, y, x + w, y, color);
        draw_line(x, y + h, x + w, y + h, color);
        draw_line(x, y, x, y + h, color);
        draw_line(x + w, y, x + w, y + h, color);
    }

    void draw_line(int x1, int y1, int x2, int y2, s_color color) {
        for (int x = x1; x <= x2; x++) {
            fb[(y1 * win_width + x) * 4] = color.r;
            fb[(y1 * win_width + x) * 4 + 1] = color.g;
            fb[(y1 * win_width + x) * 4 + 2] = color.b;
            fb[(y1 * win_width + x) * 4 + 3] = color.a;
        }
    }

    void draw_texture(const s_texture& texture, int x, int y) {
        if (texture.tex == nullptr) return;
        for (int tex_y = 0; tex_y < texture.height; tex_y++) {
            for (int tex_x = 0; tex_x < texture.width; tex_x++) {
                int fb_x = x + tex_x;
                int fb_y = y + tex_y;
                if (fb_x >= 0 && fb_x < win_width && fb_y >= 0 && fb_y < win_height) {
                    size_t tex_index = (tex_y * texture.width + tex_x) * 4;
                    size_t fb_index = (fb_y * win_width + fb_x) * 4;
                    float alpha = texture.tex[tex_index + 3] / 255.0f;
                    if (alpha == 0.0f) continue;

                    if (alpha < 1.0f) {
                        fb[fb_index] = static_cast<uint8_t>(texture.tex[tex_index] * alpha + fb[fb_index] * (1 - alpha));
                        fb[fb_index + 1] = static_cast<uint8_t>(texture.tex[tex_index + 1] * alpha + fb[fb_index + 1] * (1 - alpha));
                        fb[fb_index + 2] = static_cast<uint8_t>(texture.tex[tex_index + 2] * alpha + fb[fb_index + 2] * (1 - alpha));
                        fb[fb_index + 3] = static_cast<uint8_t>(texture.tex[tex_index + 3] * alpha + fb[fb_index + 3] * (1 - alpha));
                    } else {
                        fb[fb_index] = texture.tex[tex_index];
                        fb[fb_index + 1] = texture.tex[tex_index + 1];
                        fb[fb_index + 2] = texture.tex[tex_index + 2];
                        fb[fb_index + 3] = texture.tex[tex_index + 3];
                    }
                }
            }
        }
    }

    void draw_texture_ex(const s_texture& texture, int x, int y, int w, int h, s_rect srcrect, float rotation) {
        for (int tex_y = 0; tex_y < srcrect.h; tex_y++) {
            for (int tex_x = 0; tex_x < srcrect.w; tex_x++) {
                int fb_x = x + (tex_x * w) / srcrect.w;
                int fb_y = y + (tex_y * h) / srcrect.h;
                if (fb_x >= 0 && fb_x < win_width && fb_y >= 0 && fb_y < win_height) {
                    size_t tex_index = ((srcrect.y + tex_y) * texture.width + (srcrect.x + tex_x)) * 4;
                    size_t fb_index = (fb_y * win_width + fb_x) * 4;
                    float alpha = texture.tex[tex_index + 3] / 255.0f;

                    if (alpha == 0.0f) continue;

                    if (alpha < 1.0f) {
                        fb[fb_index] = static_cast<uint8_t>(texture.tex[tex_index] * alpha + fb[fb_index] * (1 - alpha));
                        fb[fb_index + 1] = static_cast<uint8_t>(texture.tex[tex_index + 1] * alpha + fb[fb_index + 1] * (1 - alpha));
                        fb[fb_index + 2] = static_cast<uint8_t>(texture.tex[tex_index + 2] * alpha + fb[fb_index + 2] * (1 - alpha));
                        fb[fb_index + 3] = static_cast<uint8_t>(texture.tex[tex_index + 3] * alpha + fb[fb_index + 3] * (1 - alpha));
                    } else {
                        fb[fb_index] = texture.tex[tex_index];
                        fb[fb_index + 1] = texture.tex[tex_index + 1];
                        fb[fb_index + 2] = texture.tex[tex_index + 2];
                        fb[fb_index + 3] = texture.tex[tex_index + 3];
                        
                    }
                }
            }
        }
    }
}