#pragma once

#include <vector>
#include <memory>

#include "SDL.h"

#include "util/definitions.h"
#include "core/Sprite.h"
#include "render/Renderer.h"

class Sprite;

class OpenGLRenderer : public Renderer {
protected:
    SDL_Window* window_;

    int32 width_;
    int32 height_;

public:
    bool Initialize();
    void Render();

    int32 width();
    int32 height();
};
