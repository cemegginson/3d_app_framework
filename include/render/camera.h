#pragma once

#include "core/input_device.h"
#include "util/definitions.h"
#include "util/timer.h"

class Camera {
protected:
    

public:
    // virtual Camera() = 0;
    // virtual ~Camera() = 0;
    virtual bool Initialize(InputDevice*) = 0;
    virtual void Update() = 0;
};
