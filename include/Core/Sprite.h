#pragma once

#include <memory>

#include "Virtual/Component.h"
#include "Core/GraphicsDevice.h"
#include "Core/Texture.h"

class Sprite : public Component, public std::enable_shared_from_this<Sprite> {
protected:
    Texture* texture_;
    GraphicsDevice* graphics_device_;
    SDL_Rect sprite_clip_;

public:
    Sprite(Actor*);
    ~Sprite();
    void Initialize(GraphicsDevice*, Texture*);
    void Update(std::shared_ptr<void> delta_time);
    void Render();
};
