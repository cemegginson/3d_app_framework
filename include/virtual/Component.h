#pragma once

#include <memory>

#include "core/Actor.h"
#include "util/definitions.h"
#include <vector>
#include "event_system/Subscriber.h"

class Actor;

class Component {
protected:
    Actor* owner_;
    std::vector<Subscriber*> subscribers;

public:
    Component(Actor*);
    virtual ~Component();
};
