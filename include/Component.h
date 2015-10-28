#pragma once

#include <memory>

#include "Actor.h"
#include "Definitions.h"

class Actor;

class Component {
protected:
    Actor* owner_;

public:
    Component(Actor*);
    ~Component();
    virtual void Update(float32) = 0;
};
