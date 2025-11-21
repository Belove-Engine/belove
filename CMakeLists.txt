cmake_minimum_required(VERSION 3.12)

project(BeloveEngine VERSION 0.1 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX /usr)
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)

add_library(BeloveEngine STATIC
    source/engine.cpp
    source/utils/random.cpp
    source/platforms/sdl/draw.cpp
    source/platforms/sdl/input.cpp
    source/platforms/sdl/window.cpp
    source/platforms/sdl/texture.cpp
    source/platforms/sdl/font.cpp
    source/platforms/sdl/audio.cpp
)

target_compile_options(BeloveEngine PRIVATE
    -MMD
    -MF ${CMAKE_CURRENT_BINARY_DIR}/BeloveEngine_$<TARGET_FILE_BASE_NAME:BeloveEngine>.d
)

target_include_directories(BeloveEngine PUBLIC
    include/engine
    include/engine/utils
    include/engine/platforms/sdl
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
)

target_link_libraries(BeloveEngine PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)

# set(APP_NAME "${PROJECT_NAME}_app")
# add_executable(${APP_NAME} source/main.cpp)
# target_link_libraries(${APP_NAME} PRIVATE BeloveEngine)

configure_file(
    ${CMAKE_SOURCE_DIR}/BeloveEngine.pc.in
    ${CMAKE_BINARY_DIR}/BeloveEngine.pc
    @ONLY
)

install(FILES ${CMAKE_BINARY_DIR}/BeloveEngine.pc
    DESTINATION lib/pkgconfig
)

install(TARGETS BeloveEngine
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(FILES include/BeloveEngine.hpp
    DESTINATION include
)
