#pragma once

#include "render/actor.h"

class Actor3D : Actor {
protected:

public:
    void AddComponent(Component*);
    void Update(float32);
};
