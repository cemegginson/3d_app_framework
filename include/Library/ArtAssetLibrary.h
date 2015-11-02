#pragma once

#include <map>
#include <string>

#include "Core/GraphicsDevice.h"
#include "Core/Texture.h"
#include "Core/View.h"


class ArtAssetLibrary {
protected:
    std::map<std::string, Texture*> library_;

public:
    ArtAssetLibrary();
    ~ArtAssetLibrary();
    bool LoadAssets(GraphicsDevice*, View*);
    Texture* Search(std::string);
};
