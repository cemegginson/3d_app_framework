#pragma once

#include "virtual/component.h"
#include "util/definitions.h"

#include <memory>

class Component;

class Actor {
protected:

public:
    virtual void AddComponent(Component*) = 0;
    virtual void Update(std::shared_ptr<void>) = 0;
};
