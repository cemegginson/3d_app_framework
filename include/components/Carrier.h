#pragma once

#include <string>

#include "util/definitions.h"
#include "virtual/component.h"

class Carrier : public Component {
protected:
    Actor* owner_;
    std::vector<Subscriber*> subscribers_;
    Vector2 position;
    Vector2 center;
    float32 rotation;
    int radius;
    float32 angle;

public:
    Carrier(Actor2D*);
    ~Carrier();
    void Update(float32);
    void Initialize();
};
