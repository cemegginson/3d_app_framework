#pragma once

#include <vector>
#include <memory>

#include "SDL.h"

#include "util/definitions.h"
#include "render/sdl/sprite.h"
#include "render/renderer.h"

class Sprite;

class OpenGLRenderer : public Renderer {
protected:
    SDL_Window* window_;

    uint32 width_;
    uint32 height_;

public:
    OpenGLRenderer();
    OpenGLRenderer(uint32 screen_width, uint32 screen_height);

    ~OpenGLRenderer();

    bool Initialize();

    inline void PreDraw();
    inline void Draw();
    inline void PostDraw();

    uint32 width();
    uint32 height();
};
