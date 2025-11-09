cmake_minimum_required(VERSION 3.12)

project(BeloveEngine VERSION 0.1 LANGUAGES C CXX)

set(PLATFORM "DESKTOP" CACHE STRING "Target platform: DESKTOP DESKTOP_RAYLIB FRAMEBUFFER or PSP")
set_property(CACHE PLATFORM PROPERTY STRINGS DESKTOP DESKTOP_RAYLIB FRAMEBUFFER PSP)


if(PLATFORM STREQUAL "DESKTOP")
    add_compile_definitions(PLAT_SDL)
    add_executable(${PROJECT_NAME}
        source/main.cpp
        source/engine.cpp
        source/utils/random.cpp
        source/platforms/sdl/draw.cpp
        source/platforms/sdl/input.cpp
        source/platforms/sdl/window.cpp
        source/platforms/sdl/texture.cpp
        source/platforms/sdl/font.cpp
        source/platforms/sdl/audio.cpp
    )

    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
    pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
    pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)

    target_include_directories(${PROJECT_NAME} PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS}
        "include/"
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
    )
elseif(PLATFORM STREQUAL "DESKTOP_RAYLIB")
    add_compile_definitions(PLAT_RAYLIB)
    add_executable(${PROJECT_NAME}
        source/main.cpp
        source/engine.cpp
        source/utils/random.cpp
        source/platforms/raylib/draw.cpp
        source/platforms/raylib/input.cpp
        source/platforms/raylib/window.cpp
        source/platforms/raylib/texture.cpp
        source/platforms/raylib/font.cpp
        source/platforms/raylib/audio.cpp
    )

    include(FindPkgConfig)
    pkg_search_module(raylib REQUIRED raylib)

    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
elseif(PLATFORM STREQUAL "FRAMEBUFFER")
    add_compile_definitions(PLAT_FRAMEBUFFER)
    add_executable(${PROJECT_NAME}
        source/main.cpp
        source/engine.cpp
        source/utils/random.cpp
        source/platforms/framebuffer/draw.cpp
        source/platforms/framebuffer/input.cpp
        source/platforms/framebuffer/window.cpp
        source/platforms/framebuffer/texture.cpp
        source/platforms/framebuffer/font.cpp
        source/platforms/framebuffer/audio.cpp
    )
    target_include_directories(${PROJECT_NAME} PRIVATE
        "include/"
    )
elseif(PLATFORM STREQUAL "PSP")
    if(PSP)
        add_compile_definitions(PLAT_SDL)

        add_executable(${PROJECT_NAME}
            source/main.cpp
            source/engine.cpp
            source/utils/random.cpp
            source/platforms/sdl/draw.cpp
            source/platforms/sdl/input.cpp
            source/platforms/sdl/window.cpp
            source/platforms/sdl/texture.cpp
            source/platforms/sdl/font.cpp
            source/platforms/sdl/audio.cpp
        )

        include(FindPkgConfig)
        pkg_search_module(SDL2 REQUIRED sdl2)
        pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
        pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
        pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)

        target_include_directories(${PROJECT_NAME} PRIVATE
            ${SDL2_INCLUDE_DIRS}
            ${SDL2_IMAGE_INCLUDE_DIRS}
            ${SDL2_TTF_INCLUDE_DIRS}
            ${SDL2_MIXER_INCLUDE_DIRS}
            "include/"
        )

        target_link_libraries(${PROJECT_NAME} PRIVATE
            ${SDL2_LIBRARIES}
            ${SDL2_IMAGE_LIBRARIES}
            ${SDL2_TTF_LIBRARIES}
            ${SDL2_MIXER_LIBRARIES}
        )
        create_pbp_file(
            TARGET ${PROJECT_NAME}
            ICON_PATH NULL
            BACKGROUND_PATH NULL
            PREVIEW_PATH NULL
            TITLE ${PROJECT_NAME}
            VERSION 01.00
        )
    else()
        message(FATAL_ERROR "you need to use \"psp-cmake -S . -B build -DPLATFORM=PSP\" to build!")
    endif()
endif()
