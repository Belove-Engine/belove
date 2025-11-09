#include "input.hpp"
#include <cstring>
#include <raylib.h>

namespace Input {
    inline bool pressed_gamepad[16] = {0};
    inline bool released_gamepad[16] = {0};
    inline bool down_gamepad[16] = {0};
    int current_gamepad = 0;
    void init() {};

    void update() {
        memset(pressed_gamepad, 0, sizeof(pressed_gamepad));
        memset(released_gamepad, 0, sizeof(released_gamepad));
        // for every gamepad
        for (int i = 0; i < 4; i++) {
            if (!IsGamepadAvailable(i)) continue;
            if (IsGamepadAvailable(i)) {
                current_gamepad = i;
            }
            for (int b = 0; b < 16; b++) {
                if (IsGamepadButtonPressed(i, b))  pressed_gamepad[b]  = true;
                if (IsGamepadButtonReleased(i, b)) released_gamepad[b] = true;
                down_gamepad[b] = IsGamepadButtonDown(i, b);
            }
        }

    }

    bool is_pressed(key keycode) {
        return IsKeyPressed(key_to_backend(keycode));
    }

    bool is_pressed_gamepad(controller_button btn) {
        return pressed_gamepad[(int)btn];
    }

    bool is_down(key keycode){
        return IsKeyDown(key_to_backend(keycode));
    }

    bool is_down_gamepad(controller_button btn) {
        return down_gamepad[(int)btn];
    }

    bool is_released(key keycode) {
        return IsKeyReleased(key_to_backend(keycode));
    }

    bool is_released_gamepad(controller_button btn) {
        return released_gamepad[(int)btn];
    }

    float get_axis(controller_axis axis) {
        if (!IsGamepadAvailable(current_gamepad)) return 0.0f;
        
        float value = 0;

        switch (axis) {
            case AXIS_LEFT_X:
                value = GetGamepadAxisMovement(current_gamepad, GAMEPAD_AXIS_LEFT_X);
                return value / 32767;
            case AXIS_LEFT_Y:
                value = GetGamepadAxisMovement(current_gamepad, GAMEPAD_AXIS_LEFT_Y);
                return value / 32767;
            case AXIS_RIGHT_X:
                value = GetGamepadAxisMovement(current_gamepad, GAMEPAD_AXIS_RIGHT_X);
                return value / 32767;
            case AXIS_RIGHT_Y:
                value = GetGamepadAxisMovement(current_gamepad, GAMEPAD_AXIS_RIGHT_Y);
                return value / 32767;
            case AXIS_TRIGGER_LEFT:
                value = GetGamepadAxisMovement(current_gamepad, GAMEPAD_AXIS_LEFT_TRIGGER);
                return value / 32767;
            case AXIS_TRIGGER_RIGHT:
                value = GetGamepadAxisMovement(current_gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER);
                return value / 32767;
        }
        return 0.0f;
    }

    key backend_to_key(KeyboardKey keycode) {
        switch (keycode) {
        case KEY_NULL: return key_UNKNOWN;
        case KEY_A: return key_A;
        case KEY_B: return key_B;
        case KEY_C: return key_C;
        case KEY_D: return key_D;
        case KEY_E: return key_E;
        case KEY_F: return key_F;
        case KEY_G: return key_G;
        case KEY_H: return key_H;
        case KEY_I: return key_I;
        case KEY_J: return key_J;
        case KEY_K: return key_K;
        case KEY_L: return key_L;
        case KEY_M: return key_M;
        case KEY_N: return key_N;
        case KEY_O: return key_O;
        case KEY_P: return key_P;
        case KEY_Q: return key_Q;
        case KEY_R: return key_R;
        case KEY_S: return key_S;
        case KEY_T: return key_T;
        case KEY_U: return key_U;
        case KEY_V: return key_V;
        case KEY_W: return key_W;
        case KEY_X: return key_X;
        case KEY_Y: return key_Y;
        case KEY_Z: return key_Z;
        case KEY_ZERO: return key_0;
        case KEY_ONE: return key_1;
        case KEY_TWO: return key_2;
        case KEY_THREE: return key_3;
        case KEY_FOUR: return key_4;
        case KEY_FIVE: return key_5;
        case KEY_SIX: return key_6;
        case KEY_SEVEN: return key_7;
        case KEY_EIGHT: return key_8;
        case KEY_NINE: return key_9;
        case KEY_F1: return key_F1;
        case KEY_F2: return key_F2;
        case KEY_F3: return key_F3;
        case KEY_F4: return key_F4;
        case KEY_F5: return key_F5;
        case KEY_F6: return key_F6;
        case KEY_F7: return key_F7;
        case KEY_F8: return key_F8;
        case KEY_F9: return key_F9;
        case KEY_F10: return key_F10;
        case KEY_F11: return key_F11;
        case KEY_F12: return key_F12;
        case KEY_ENTER: return key_ENTER;
        case KEY_ESCAPE: return key_ESCAPE;
        case KEY_SPACE: return key_SPACE;
        case KEY_TAB: return key_TAB;
        case KEY_BACKSPACE: return key_BACKSPACE;
        case KEY_LEFT_SHIFT: return key_LEFT_SHIFT;
        case KEY_RIGHT_SHIFT: return key_RIGHT_SHIFT;
        case KEY_LEFT_CONTROL: return key_LEFT_CTRL;
        case KEY_RIGHT_CONTROL: return key_RIGHT_CTRL;
        case KEY_LEFT_ALT: return key_LEFT_ALT;
        case KEY_RIGHT_ALT: return key_RIGHT_ALT;
        case KEY_UP: return key_UP;
        case KEY_DOWN: return key_DOWN;
        case KEY_LEFT: return key_LEFT;
        case KEY_RIGHT: return key_RIGHT;
        case KEY_INSERT: return key_INSERT;
        case KEY_DELETE: return key_DELETE;
        case KEY_HOME: return key_HOME;
        case KEY_END: return key_END;
        case KEY_PAGE_UP: return key_PAGE_UP;
        case KEY_PAGE_DOWN: return key_PAGE_DOWN;
        case KEY_EQUAL: return key_EQUAL;
        case KEY_MINUS: return key_MINUS; 
        default: return key_UNKNOWN;
        }
    };

    KeyboardKey key_to_backend(key keycode) {
        switch (keycode) {
        case key_UNKNOWN: return KEY_NULL;
        case key_A: return KEY_A;
        case key_B: return KEY_B;
        case key_C: return KEY_C;
        case key_D: return KEY_D;
        case key_E: return KEY_E;
        case key_F: return KEY_F;
        case key_G: return KEY_G;
        case key_H: return KEY_H;
        case key_I: return KEY_I;
        case key_J: return KEY_J;
        case key_K: return KEY_K;
        case key_L: return KEY_L;
        case key_M: return KEY_M;
        case key_N: return KEY_N;
        case key_O: return KEY_O;
        case key_P: return KEY_P;
        case key_Q: return KEY_Q;
        case key_R: return KEY_R;
        case key_S: return KEY_S;
        case key_T: return KEY_T;
        case key_U: return KEY_U;
        case key_V: return KEY_V;
        case key_W: return KEY_W;
        case key_X: return KEY_X;
        case key_Y: return KEY_Y;
        case key_Z: return KEY_Z;
        case key_0: return KEY_ZERO;
        case key_1: return KEY_ONE;
        case key_2: return KEY_TWO;
        case key_3: return KEY_THREE;
        case key_4: return KEY_FOUR;
        case key_5: return KEY_FIVE;
        case key_6: return KEY_SIX;
        case key_7: return KEY_SEVEN;
        case key_8: return KEY_EIGHT;
        case key_9: return KEY_NINE;
        case key_F1: return KEY_F1;
        case key_F2: return KEY_F2;
        case key_F3: return KEY_F3;
        case key_F4: return KEY_F4;
        case key_F5: return KEY_F5;
        case key_F6: return KEY_F6;
        case key_F7: return KEY_F7;
        case key_F8: return KEY_F8;
        case key_F9: return KEY_F9;
        case key_F10: return KEY_F10;
        case key_F11: return KEY_F11;
        case key_F12: return KEY_F12;
        case key_ENTER: return KEY_ENTER;
        case key_ESCAPE: return KEY_ESCAPE;
        case key_SPACE: return KEY_SPACE;
        case key_TAB: return KEY_TAB;
        case key_BACKSPACE: return KEY_BACKSPACE;
        case key_LEFT_SHIFT: return KEY_LEFT_SHIFT;
        case key_RIGHT_SHIFT: return KEY_RIGHT_SHIFT;
        case key_LEFT_CTRL: return KEY_LEFT_CONTROL;
        case key_RIGHT_CTRL: return KEY_RIGHT_CONTROL;
        case key_LEFT_ALT: return KEY_LEFT_ALT;
        case key_RIGHT_ALT: return KEY_RIGHT_ALT;
        case key_UP: return KEY_UP;
        case key_DOWN: return KEY_DOWN;
        case key_LEFT: return KEY_LEFT;
        case key_RIGHT: return KEY_RIGHT;
        case key_INSERT: return KEY_INSERT;
        case key_DELETE: return KEY_DELETE;
        case key_HOME: return KEY_HOME;
        case key_END: return KEY_END;
        case key_PAGE_UP: return KEY_PAGE_UP;
        case key_PAGE_DOWN: return KEY_PAGE_DOWN;
        case key_EQUAL: return KEY_EQUAL;
        case key_MINUS: return KEY_MINUS;
        default: return KEY_NULL;

        }
    }

    int get_mouse_x() {
        return GetMouseX();
    }
    int get_mouse_y() {
        return GetMouseY();
    }

    bool is_mouse_down(mouse_button btn) {
        return IsMouseButtonDown(btn);
    }

    bool is_mouse_pressed(mouse_button btn) {
        return IsMouseButtonPressed(btn);
    }
}