#pragma once

#include <memory>
#include <vector>

#include "core/actor.h"
#include "util/definitions.h"
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
