// sets default platform to SDL if none is defined
#ifndef PLAT_RAYLIB
    #ifndef PLAT_FRAMEBUFFER
        #ifndef PLAT_WII
            #define PLAT_SDL
        #endif
    #endif
#endif

#ifdef PLAT_RAYLIB
#include "platforms/raylib/draw.hpp"
#include "platforms/raylib/window.hpp"
#include "platforms/raylib/input.hpp"
#include "platforms/raylib/texture.hpp"
#include "platforms/raylib/font.hpp"
#include "platforms/raylib/audio.hpp"
#endif

#ifdef PLAT_SDL
#include "platforms/sdl/draw.hpp"
#include "platforms/sdl/window.hpp"
#include "platforms/sdl/input.hpp"
#include "platforms/sdl/texture.hpp"
#include "platforms/sdl/font.hpp"
#include "platforms/sdl/audio.hpp"
#endif

#ifdef PLAT_FRAMEBUFFER
#include "platforms/framebuffer/draw.hpp"
#include "platforms/framebuffer/window.hpp"
#include "platforms/framebuffer/input.hpp"
#include "platforms/framebuffer/texture.hpp"
#include "platforms/framebuffer/font.hpp"
#include "platforms/framebuffer/audio.hpp"
#endif

#ifdef PLAT_WII
#include "platforms/wii/draw.hpp"
#include "platforms/wii/window.hpp"
#include "platforms/wii/input.hpp"
#include "platforms/wii/texture.hpp"
#include "platforms/wii/font.hpp"
#include "platforms/wii/audio.hpp"
#endif