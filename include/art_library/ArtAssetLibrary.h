#pragma once

#include <map>
#include <string>

#include "core/Texture.h"
#include "render/sdl/sdl_view.h"

#include "render/renderer.h"
#include "render/sdl/sdl_renderer.h"
#include "render/opengl/opengl_renderer.h"


class ArtAssetLibrary {
protected:
    std::map<std::string, Texture*> library_;

public:
    ArtAssetLibrary();
    ~ArtAssetLibrary();
    bool LoadAssets(Renderer*, SDLView*);
    Texture* Search(std::string);
};
