#pragma once

#include "SDL.h"

#include "Component.h"
#include "Definitions.h"

class Animation : public Component {
protected:
    SDL_Rect sprite_clip_;
public:
    Animation(std::shared_ptr<Actor>);
    ~Animation();
    void Update(float32);
    void Initialize();
}
