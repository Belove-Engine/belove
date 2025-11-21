#include "draw.hpp"
#include "texture.hpp"
#include "window.hpp"

namespace Draw {
    void draw_rectangle(int x, int y, int w, int h, s_color color) {
        SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = { x, y, w, h };
        SDL_RenderFillRect(sdl_renderer, &rect);
    }

    void draw_text(s_font font, const char* text, int x, int y, int size, s_color color) {
        SDL_Surface *surface = TTF_RenderUTF8_Blended(font.font, text, {(Uint8)color.r, (Uint8)color.g, (Uint8)color.b, (Uint8)color.a});
        SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);

        SDL_Rect dst = { x, y, surface->w, surface->h };

        SDL_RenderCopy(sdl_renderer, texture, nullptr, &dst);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    void clear(s_color color) {
        SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(sdl_renderer);
    }

    void draw_rect(int x, int y, int w, int h, s_color color) {
        SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = { x, y, w, h };
        SDL_RenderDrawRect(sdl_renderer, &rect);
    }

    void draw_line(int x1, int y1, int x2, int y2, s_color color) {
        SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(sdl_renderer, x1, y1, x2, y2);
    }

    void draw_texture(const s_texture& texture, int x, int y) {
        SDL_Rect dst = { x, y, texture.width, texture.height };
        SDL_RenderCopy(sdl_renderer, texture.tex, nullptr, &dst);
    }

    void draw_texture_ex(const s_texture& texture, int x, int y, int w, int h, s_rect srcrect, float rotation) {
        if (texture.tex == nullptr) return;
        SDL_Rect dst = { x, y, w, h };
        SDL_Rect src = { srcrect.x, srcrect.y, srcrect.w, srcrect.h };
        SDL_Point center = { w / 2, h / 2 };
        SDL_RenderCopyEx(sdl_renderer, texture.tex, &src, &dst, rotation, &center, SDL_FLIP_NONE);
    }
}