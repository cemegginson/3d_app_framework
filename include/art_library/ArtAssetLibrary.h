#pragma once

#include <map>
#include <string>

#include "core/Texture.h"
#include "core/View.h"

#include "render/Renderer.h"
#include "render/sdl/SDLRenderer.h"
#include "render/opengl/opengl_renderer.h"


class ArtAssetLibrary {
protected:
    std::map<std::string, Texture*> library_;

public:
    ArtAssetLibrary();
    ~ArtAssetLibrary();
    bool LoadAssets(Renderer*, View*);
    Texture* Search(std::string);
};
