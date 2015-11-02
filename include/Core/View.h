#pragma once

#include "Core/InputDevice.h"
#include "Util/Definitions.h"

class View {
protected:
    InputDevice* input_device_;
    Vector2 transform_;
    uint32 velocity_;

public:
    View();
    ~View();
    bool Initialize(InputDevice*, float32, float32);
    void Update(float32);
    Vector2 transform();
};
