#pragma once

#include <memory>

#include "virtual/Component.h"
#include "render/renderer.h"
#include "render/sdl/sdl_renderer.h"
#include "render/opengl/opengl_renderer.h"
#include "core/Texture.h"

class Sprite : public Component, public std::enable_shared_from_this<Sprite> {
protected:
    Texture* texture_;
    Renderer* renderer_;
    SDL_Rect sprite_clip_;

public:
    Sprite(Actor*);
    ~Sprite();
    void Initialize(Renderer*, Texture*);
    void Update(std::shared_ptr<void> delta_time);
    void Draw();
};
