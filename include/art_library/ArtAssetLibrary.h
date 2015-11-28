#pragma once

#include <map>
#include <string>

#include "core/GraphicsDevice.h"
#include "core/Texture.h"
#include "core/View.h"


class ArtAssetLibrary {
protected:
    std::map<std::string, Texture*> library_;

public:
    ArtAssetLibrary();
    ~ArtAssetLibrary();
    bool LoadAssets(GraphicsDevice*, View*);
    Texture* Search(std::string);
};
