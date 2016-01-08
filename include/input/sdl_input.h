#pragma once

#include "input/input_manager.h"

class SDLInput : InputManager {
protected:

public:
    SDLInput();
    ~SDLInput();
    
    void Initialize();
    void Update();
};
