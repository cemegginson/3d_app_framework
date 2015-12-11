#pragma once

#include "virtual/component.h"
#include "util/definitions.h"

class Component;

class Actor {
protected:

public:
    virtual void AddComponent(Component*) = 0;
    virtual void Update(float32) = 0;
};
