#pragma once

#include <memory>
#include <vector>

#include "util/definitions.h"

class Actor;

class Component {
protected:

public:
    virtual ~Component() {}
    virtual void Update() = 0;
};

typedef std::shared_ptr<Component> ComponentPtr;
typedef std::weak_ptr<Component> ComponentWeakPtr;
