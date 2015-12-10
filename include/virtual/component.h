#pragma once

#include <memory>
#include <vector>

#include "render/sdl/actor_2d.h"
#include "util/definitions.h"
#include "event_system/Subscriber.h"

class Actor;

class Component {
protected:

public:
    virtual Component() = 0;
    virtual ~Component() = 0;
    virtual void Update(float32) = 0;
};
