#pragma once

#include <memory>
#include <vector>

#include "util/definitions.h"
#include "event_system/Subscriber.h"

class Actor;

class Component {
protected:
    std::vector<Subscriber*> subscribers;

public:
    // virtual Component() = 0;
    // virtual ~Component() = 0;
    virtual void Update() = 0;
};
