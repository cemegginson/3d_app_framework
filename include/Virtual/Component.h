#pragma once

#include <memory>

#include "Core/Actor.h"
#include "Util/Definitions.h"
#include <vector>
#include "EventSystem/Subscriber.h"

class Actor;

class Component {
protected:
    Actor* owner_;
    std::vector<Subscriber*> subscribers;

public:
    Component(Actor*);
    virtual ~Component();
};
