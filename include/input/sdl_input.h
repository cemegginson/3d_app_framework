#pragma once

#include <map>
#include <memory>
#include <utility>

#include "SDL.h"

#include "util/definitions.h"

#include "input/input_manager.h"
#include "input/control_utils.h"
#include "input/keyboard.h"
#include "input/mouse.h"
#include "input/controller.h"

class SDLInput : InputManager {
protected:
    std::map<SDL_Keycode, KeyboardKey> keyboard_map_;
    std::map<uint8, ControllerButton> controller_map_;
    std::map<uint8, MouseButton> mouse_map_;

    std::shared_ptr<Keyboard> keyboard_;
    std::shared_ptr<Mouse> mouse_;
    std::shared_ptr<Controller> controller_;

public:
    SDLInput();
    ~SDLInput();

    void Initialize();
    void Update();
};
