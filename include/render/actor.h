#pragma once

class Actor {
protected:

public:
    virtual void AddComponent(Component*) = 0;
    virtual void Update(float32) = 0;
};
