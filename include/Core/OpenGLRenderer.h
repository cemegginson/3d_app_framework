#pragma once

#include <vector>
#include <memory>

#include "SDL.h"

#include "Util/Definitions.h"
#include "Core/Sprite.h"
#include "Core/Renderer.h"

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
