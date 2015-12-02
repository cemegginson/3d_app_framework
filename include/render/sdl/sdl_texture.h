#pragma once

#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "util/definitions.h"
#include "render/sdl/sdl_view.h"

class Texture {
protected:
    SDL_Texture* texture_;
    SDL_Renderer* renderer_;
    SDLView* SDLView_;

public:
    Texture();
    ~Texture();
    bool Initialize(SDL_Renderer*, SDLView*, std::string);
    void Render(Vector2, float32, SDL_Rect);
    // void Render(Vector2, float32);
    void GetDimensions(int32*, int32*);
};
