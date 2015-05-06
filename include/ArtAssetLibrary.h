#pragma once

#include <map>
#include <string>

#include "GraphicsDevice.h"
#include "Texture.h"
#include "View.h"


class ArtAssetLibrary {
protected:
	std::map<std::string, Texture*> library_;

public:
	ArtAssetLibrary();
	~ArtAssetLibrary();
	bool LoadAssets(GraphicsDevice*, View*);
	Texture* Search(std::string);
};
