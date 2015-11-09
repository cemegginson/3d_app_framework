#pragma once

#include <vector>
#include <memory>

#include "SDL.h"

#include "Util/Definitions.h"
#include "Core/Renderer.h"
#include "Core/Sprite.h"

class Sprite;

class SDLRenderer : public Renderer {
protected:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::vector<Sprite*> sprites_;

    uint32 width_;
    uint32 height_;

public:
    SDLRenderer();
    SDLRenderer(uint32, uint32);
    ~SDLRenderer();
    bool Initialize();
    void AddSprite(Sprite*);
    void Render();

    uint32 width();
    uint32 height();
    SDL_Renderer* renderer();
};
