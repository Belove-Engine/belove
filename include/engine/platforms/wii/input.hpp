#pragma once
#include <vector>
#include "window.hpp"
#include <wiiuse/wpad.h>

// TODO: add support for more than one controller
extern ir_t ir1;

enum key {
    key_UNKNOWN = 0,

    key_A, key_B, key_C, key_D, key_E, key_F, key_G, key_H, key_I, key_J,
    key_K, key_L, key_M, key_N, key_O, key_P, key_Q, key_R, key_S, key_T,
    key_U, key_V, key_W, key_X, key_Y, key_Z,

    key_0, key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8, key_9,

    key_F1, key_F2, key_F3, key_F4, key_F5, key_F6,
    key_F7, key_F8, key_F9, key_F10, key_F11, key_F12,

    key_ENTER, key_ESCAPE, key_SPACE, key_TAB, key_BACKSPACE,
    key_LEFT_SHIFT, key_RIGHT_SHIFT,
    key_LEFT_CTRL, key_RIGHT_CTRL,
    key_LEFT_ALT, key_RIGHT_ALT,

    key_UP, key_DOWN, key_LEFT, key_RIGHT,

    key_INSERT, key_DELETE, key_HOME, key_END,
    key_PAGE_UP, key_PAGE_DOWN,

    key_EQUAL, key_MINUS
};

enum controller_button {
    BUTTON_A = 0,
    BUTTON_B,
    BUTTON_X,
    BUTTON_Y,
    BUTTON_BACK,
    BUTTON_GUIDE,
    BUTTON_START,
    BUTTON_LEFTSTICK,
    BUTTON_RIGHTSTICK,
    BUTTON_LEFTSHOULDER,
    BUTTON_RIGHTSHOULDER,
    BUTTON_DPAD_UP,
    BUTTON_DPAD_DOWN,
    BUTTON_DPAD_LEFT,
    BUTTON_DPAD_RIGHT
};

enum controller_axis {
    AXIS_LEFT_X,
    AXIS_LEFT_Y,
    AXIS_RIGHT_X,
    AXIS_RIGHT_Y,
    AXIS_TRIGGER_LEFT,
    AXIS_TRIGGER_RIGHT,
};

enum mouse_button {
    MOUSE_LEFT = 0,
    MOUSE_RIGHT = 1,
    MOUSE_MIDDLE = 2,
};

namespace Input {
    void init();
    void update();
    bool is_pressed(key keycode);
    bool is_pressed_gamepad(controller_button btn);
    bool is_released(key keycode);
    bool is_released_gamepad(controller_button btn);
    bool is_down(key keycode);
    bool is_down_gamepad(controller_button btn);
    float get_axis(controller_axis btn);
    key backend_to_key(char keycode);
    char key_to_backend(key keycode);
    char map_button(controller_button btn);
    int get_mouse_x();
    int get_mouse_y();

    bool is_mouse_down(mouse_button btn);
    bool is_mouse_pressed(mouse_button btn);
}