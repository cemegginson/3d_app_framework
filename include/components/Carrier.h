#pragma once

#include <string>

#include "util/definitions.h"
#include "virtual/Component.h"

class Carrier : public Component {
protected:
    Vector2 position;
    Vector2 center;
    float32 rotation;
    int radius;
    float32 angle;

public:
    Carrier(Actor*);
    ~Carrier();
    void Update(float32);
    void Initialize();
};
