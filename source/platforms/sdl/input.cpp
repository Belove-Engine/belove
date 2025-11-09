#include "input.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_mouse.h>
#include <cstring>

namespace Input {
    inline SDL_GameControllerButton map_button(controller_button btn);
    inline bool pressed[512] = {0};
    inline bool released[512] = {0};
    const Uint8* state = nullptr;

    inline bool pressed_gamepad[16] = {0};
    inline bool released_gamepad[16] = {0};
    inline bool down_gamepad[16] = {0};
    int current_gamepad = 0;
    inline SDL_GameController* controller = nullptr;

    void init() {
        int n = SDL_NumJoysticks();
        for (int i = 0; i < n; i++) {
            if (SDL_IsGameController(i)) {
                controller = SDL_GameControllerOpen(i);
                current_gamepad = i;
                break;
            }
        }
    }

    void update() {
        memset(pressed, 0, sizeof(pressed));
        memset(released, 0, sizeof(released));
        memset(pressed_gamepad, 0, sizeof(pressed_gamepad));
        memset(released_gamepad, 0, sizeof(released_gamepad));

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                close_window();
            }
            if (e.type == SDL_CONTROLLERDEVICEADDED) {
                controller = SDL_GameControllerOpen(e.cdevice.which);
                current_gamepad = e.cdevice.which;
            }

            if (e.type == SDL_CONTROLLERBUTTONDOWN) {
                int b = e.cbutton.button;
                if (b < 16) pressed_gamepad[b] = true;
            }
            if (e.type == SDL_CONTROLLERBUTTONUP) {
                int b = e.cbutton.button;
                if (b < 16) released_gamepad[b] = true;
            }

            if (e.type == SDL_KEYDOWN && !e.key.repeat)
                pressed[e.key.keysym.scancode] = true;
            
            if (e.type == SDL_KEYUP)
                released[e.key.keysym.scancode] = true;
        }

        state = SDL_GetKeyboardState(NULL);

        if (!controller) return;

        for (int i = 0; i < 16; i++)
            down_gamepad[i] = SDL_GameControllerGetButton(controller, map_button((controller_button)i));
}

    bool is_pressed(key keycode) {
        if (!pressed) return false;
        SDL_Scancode sc = key_to_backend(keycode);
        if (sc >= 512) return false;
        return sc < 512 && pressed[sc];

    }

    bool is_pressed_gamepad(controller_button btn) {
        return pressed_gamepad[(int)btn];
    }

    bool is_down(key keycode) {
        SDL_Scancode sc = key_to_backend(keycode);
        if (sc >= 512) return false;
        return sc < 512 && state[sc];
    }

    bool is_down_gamepad(controller_button btn) {
        return down_gamepad[(int)btn];
    }

    float get_axis(controller_axis axis) {
        if (!controller) return 0.0f;

        float value = 0;

        switch (axis) {
            case AXIS_LEFT_X:
                value = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
                return value / 32767;
            case AXIS_LEFT_Y:
                value = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
                return value / 32767;
            case AXIS_RIGHT_X:
                value = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX);
                return value / 32767;
            case AXIS_RIGHT_Y:
                value = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY);
                return value / 32767;
            case AXIS_TRIGGER_LEFT:
                value = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
                return value / 32767;
            case AXIS_TRIGGER_RIGHT:
                value = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
                return value / 32767;
        }
        return 0.0f;
    }

    bool is_released(key keycode) {
        if (!released) return false;
        SDL_Scancode sc = key_to_backend(keycode);
        return sc < 512 && released[sc];
    }

    bool is_released_gamepad(controller_button btn) {
        return released_gamepad[(int)btn];
    }

    key backend_to_key(SDL_Scancode keycode) {
        switch (keycode) {
        case SDL_SCANCODE_UNKNOWN: return key_UNKNOWN;
        case SDL_SCANCODE_A: return key_A;
        case SDL_SCANCODE_B: return key_B;
        case SDL_SCANCODE_C: return key_C;
        case SDL_SCANCODE_D: return key_D;
        case SDL_SCANCODE_E: return key_E;
        case SDL_SCANCODE_F: return key_F;
        case SDL_SCANCODE_G: return key_G;
        case SDL_SCANCODE_H: return key_H;
        case SDL_SCANCODE_I: return key_I;
        case SDL_SCANCODE_J: return key_J;
        case SDL_SCANCODE_K: return key_K;
        case SDL_SCANCODE_L: return key_L;
        case SDL_SCANCODE_M: return key_M;
        case SDL_SCANCODE_N: return key_N;
        case SDL_SCANCODE_O: return key_O;
        case SDL_SCANCODE_P: return key_P;
        case SDL_SCANCODE_Q: return key_Q;
        case SDL_SCANCODE_R: return key_R;
        case SDL_SCANCODE_S: return key_S;
        case SDL_SCANCODE_T: return key_T;
        case SDL_SCANCODE_U: return key_U;
        case SDL_SCANCODE_V: return key_V;
        case SDL_SCANCODE_W: return key_W;
        case SDL_SCANCODE_X: return key_X;
        case SDL_SCANCODE_Y: return key_Y;
        case SDL_SCANCODE_Z: return key_Z;
        case SDL_SCANCODE_0: return key_0;
        case SDL_SCANCODE_1: return key_1;
        case SDL_SCANCODE_2: return key_2;
        case SDL_SCANCODE_3: return key_3;
        case SDL_SCANCODE_4: return key_4;
        case SDL_SCANCODE_5: return key_5;
        case SDL_SCANCODE_6: return key_6;
        case SDL_SCANCODE_7: return key_7;
        case SDL_SCANCODE_8: return key_8;
        case SDL_SCANCODE_9: return key_9;
        case SDL_SCANCODE_F1: return key_F1;
        case SDL_SCANCODE_F2: return key_F2;
        case SDL_SCANCODE_F3: return key_F3;
        case SDL_SCANCODE_F4: return key_F4;
        case SDL_SCANCODE_F5: return key_F5;
        case SDL_SCANCODE_F6: return key_F6;
        case SDL_SCANCODE_F7: return key_F7;
        case SDL_SCANCODE_F8: return key_F8;
        case SDL_SCANCODE_F9: return key_F9;
        case SDL_SCANCODE_F10: return key_F10;
        case SDL_SCANCODE_F11: return key_F11;
        case SDL_SCANCODE_F12: return key_F12;
        case SDL_SCANCODE_RETURN: return key_ENTER;
        case SDL_SCANCODE_ESCAPE: return key_ESCAPE;
        case SDL_SCANCODE_SPACE: return key_SPACE;
        case SDL_SCANCODE_TAB: return key_TAB;
        case SDL_SCANCODE_BACKSPACE: return key_BACKSPACE;
        case SDL_SCANCODE_LSHIFT: return key_LEFT_SHIFT;
        case SDL_SCANCODE_RSHIFT: return key_RIGHT_SHIFT;
        case SDL_SCANCODE_LCTRL: return key_LEFT_CTRL;
        case SDL_SCANCODE_RCTRL: return key_RIGHT_CTRL;
        case SDL_SCANCODE_LALT: return key_LEFT_ALT;
        case SDL_SCANCODE_RALT: return key_RIGHT_ALT;
        case SDL_SCANCODE_UP: return key_UP;
        case SDL_SCANCODE_DOWN: return key_DOWN;
        case SDL_SCANCODE_LEFT: return key_LEFT;
        case SDL_SCANCODE_RIGHT: return key_RIGHT;
        case SDL_SCANCODE_INSERT: return key_INSERT;
        case SDL_SCANCODE_DELETE: return key_DELETE;
        case SDL_SCANCODE_HOME: return key_HOME;
        case SDL_SCANCODE_END: return key_END;
        case SDL_SCANCODE_PAGEUP: return key_PAGE_UP;
        case SDL_SCANCODE_PAGEDOWN: return key_PAGE_DOWN;
        case SDL_SCANCODE_EQUALS: return key_EQUAL;
        case SDL_SCANCODE_MINUS: return key_MINUS; 
        default: return key_UNKNOWN;
        }
    };

    SDL_Scancode key_to_backend(key keycode) {
        switch (keycode) {
        case key_UNKNOWN: return SDL_SCANCODE_UNKNOWN;
        case key_A: return SDL_SCANCODE_A;
        case key_B: return SDL_SCANCODE_B;
        case key_C: return SDL_SCANCODE_C;
        case key_D: return SDL_SCANCODE_D;
        case key_E: return SDL_SCANCODE_E;
        case key_F: return SDL_SCANCODE_F;
        case key_G: return SDL_SCANCODE_G;
        case key_H: return SDL_SCANCODE_H;
        case key_I: return SDL_SCANCODE_I;
        case key_J: return SDL_SCANCODE_J;
        case key_K: return SDL_SCANCODE_K;
        case key_L: return SDL_SCANCODE_L;
        case key_M: return SDL_SCANCODE_M;
        case key_N: return SDL_SCANCODE_N;
        case key_O: return SDL_SCANCODE_O;
        case key_P: return SDL_SCANCODE_P;
        case key_Q: return SDL_SCANCODE_Q;
        case key_R: return SDL_SCANCODE_R;
        case key_S: return SDL_SCANCODE_S;
        case key_T: return SDL_SCANCODE_T;
        case key_U: return SDL_SCANCODE_U;
        case key_V: return SDL_SCANCODE_V;
        case key_W: return SDL_SCANCODE_W;
        case key_X: return SDL_SCANCODE_X;
        case key_Y: return SDL_SCANCODE_Y;
        case key_Z: return SDL_SCANCODE_Z;
        case key_0: return SDL_SCANCODE_0;
        case key_1: return SDL_SCANCODE_1;
        case key_2: return SDL_SCANCODE_2;
        case key_3: return SDL_SCANCODE_3;
        case key_4: return SDL_SCANCODE_4;
        case key_5: return SDL_SCANCODE_5;
        case key_6: return SDL_SCANCODE_6;
        case key_7: return SDL_SCANCODE_7;
        case key_8: return SDL_SCANCODE_8;
        case key_9: return SDL_SCANCODE_9;
        case key_F1: return SDL_SCANCODE_F1;
        case key_F2: return SDL_SCANCODE_F2;
        case key_F3: return SDL_SCANCODE_F3;
        case key_F4: return SDL_SCANCODE_F4;
        case key_F5: return SDL_SCANCODE_F5;
        case key_F6: return SDL_SCANCODE_F6;
        case key_F7: return SDL_SCANCODE_F7;
        case key_F8: return SDL_SCANCODE_F8;
        case key_F9: return SDL_SCANCODE_F9;
        case key_F10: return SDL_SCANCODE_F10;
        case key_F11: return SDL_SCANCODE_F11;
        case key_F12: return SDL_SCANCODE_F12;
        case key_ENTER: return SDL_SCANCODE_RETURN;
        case key_ESCAPE: return SDL_SCANCODE_ESCAPE;
        case key_SPACE: return SDL_SCANCODE_SPACE;
        case key_TAB: return SDL_SCANCODE_TAB;
        case key_BACKSPACE: return SDL_SCANCODE_BACKSPACE;
        case key_LEFT_SHIFT: return SDL_SCANCODE_LSHIFT;
        case key_RIGHT_SHIFT: return SDL_SCANCODE_RSHIFT;
        case key_LEFT_CTRL: return SDL_SCANCODE_LCTRL;
        case key_RIGHT_CTRL: return SDL_SCANCODE_RCTRL;
        case key_LEFT_ALT: return SDL_SCANCODE_LALT;
        case key_RIGHT_ALT: return SDL_SCANCODE_RALT;
        case key_UP: return SDL_SCANCODE_UP;
        case key_DOWN: return SDL_SCANCODE_DOWN;
        case key_LEFT: return SDL_SCANCODE_LEFT;
        case key_RIGHT: return SDL_SCANCODE_RIGHT;
        case key_INSERT: return SDL_SCANCODE_INSERT;
        case key_DELETE: return SDL_SCANCODE_DELETE;
        case key_HOME: return SDL_SCANCODE_HOME;
        case key_END: return SDL_SCANCODE_END;
        case key_PAGE_UP: return SDL_SCANCODE_PAGEUP;
        case key_PAGE_DOWN: return SDL_SCANCODE_PAGEDOWN;
        case key_EQUAL: return SDL_SCANCODE_EQUALS;
        case key_MINUS: return SDL_SCANCODE_MINUS;
        default: return SDL_SCANCODE_UNKNOWN;
        }
    }

    inline SDL_GameControllerButton map_button(controller_button btn) {
        switch (btn) {

        case BUTTON_A: return SDL_CONTROLLER_BUTTON_A;
        case BUTTON_B: return SDL_CONTROLLER_BUTTON_B;
        case BUTTON_X: return SDL_CONTROLLER_BUTTON_X;
        case BUTTON_Y: return SDL_CONTROLLER_BUTTON_Y;
        case BUTTON_BACK: return SDL_CONTROLLER_BUTTON_BACK;
        case BUTTON_GUIDE: return SDL_CONTROLLER_BUTTON_GUIDE;
        case BUTTON_START: return SDL_CONTROLLER_BUTTON_START;
        case BUTTON_LEFTSTICK: return SDL_CONTROLLER_BUTTON_LEFTSTICK;
        case BUTTON_RIGHTSTICK: return SDL_CONTROLLER_BUTTON_RIGHTSTICK;
        case BUTTON_LEFTSHOULDER: return SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
        case BUTTON_RIGHTSHOULDER: return SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
        case BUTTON_DPAD_UP: return SDL_CONTROLLER_BUTTON_DPAD_UP;
        case BUTTON_DPAD_DOWN: return SDL_CONTROLLER_BUTTON_DPAD_DOWN;
        case BUTTON_DPAD_LEFT: return SDL_CONTROLLER_BUTTON_DPAD_LEFT;
        case BUTTON_DPAD_RIGHT: return SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
        default: return SDL_CONTROLLER_BUTTON_INVALID;
        
        }
    }

    int get_mouse_x() {
        int x;
        SDL_GetMouseState(&x, nullptr);
        return x;
    }

    int get_mouse_y() {
        int y;
        SDL_GetMouseState(nullptr, &y);
        return y;
    }

    bool is_mouse_down(mouse_button btn) {
        Uint32 buttons = SDL_GetRelativeMouseState(nullptr, nullptr);
        return (buttons & SDL_BUTTON(btn + 1));
    }

    bool is_mouse_pressed(mouse_button btn) {
        static Uint32 prevButtons = 0;

        Uint32 buttons = SDL_GetRelativeMouseState(nullptr, nullptr);

        bool pressed = (buttons & SDL_BUTTON(btn + 1)) && !(prevButtons & SDL_BUTTON(btn + 1));

        prevButtons = buttons;
        return pressed;
    }
}