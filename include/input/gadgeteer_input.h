#pragma once

#include "input/input_manager.h"

class GadgeteerInput : InputManager {
protected:

public:
    GadgeteerInput();
    ~GadgeteerInput();

    void Initialize();
    void Update();
};
