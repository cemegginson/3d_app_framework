#pragma once

#include <memory>
#include <vector>

#include "util/definitions.h"

class Actor;

class Component {
protected:

public:
    // virtual Component() = 0;
    // virtual ~Component() = 0;
    virtual void Update() = 0;
};
