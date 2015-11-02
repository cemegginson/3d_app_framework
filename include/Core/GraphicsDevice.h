#pragma once

#include <vector>
#include <memory>

#include "SDL.h"

#include "Util/Definitions.h"
#include "Core/Sprite.h"

class Sprite;

class GraphicsDevice {
protected:
    int width_;
    int height_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::vector<Sprite*> sprites_;

public:
    GraphicsDevice();
    GraphicsDevice(uint32, uint32);
    ~GraphicsDevice();
    bool Initialize();
    void AddSprite(Sprite*);
    void Render();

    int width();
    int height();
    SDL_Renderer* renderer();
};
