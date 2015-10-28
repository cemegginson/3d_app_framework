#include <iostream>
#include <string>
#include <utility>

#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() {}

ArtAssetLibrary::~ArtAssetLibrary() {
    for(auto iter = library_.begin(); iter!=library_.end();) {
        delete iter->second;
        iter = library_.erase(iter);
    }
}

bool ArtAssetLibrary::LoadAssets(GraphicsDevice* graphics_device, View* view) {
    // Bullet
    library_.insert(std::pair<std::string, Texture*>("Bullet", new Texture()));
    std::string bullet_path = "./Assets/Images/t_bullet.png";
    library_.at("Bullet")->Initialize(graphics_device->renderer(), view, bullet_path);

    // Carrier
    library_.insert(std::pair<std::string, Texture*>("Carrier", new Texture()));
    std::string carrier_path = "./Assets/Images/t_carrier.png";
    library_.at("Carrier")->Initialize(graphics_device->renderer(), view, carrier_path);

    // Infantry
    library_.insert(std::pair<std::string, Texture*>("Infantry", new Texture()));
    std::string infantry_path = "./Assets/Images/t_infantry.png";
    library_.at("Infantry")->Initialize(graphics_device->renderer(), view, infantry_path);

    // Samus
    library_.insert(std::pair<std::string, Texture*>("Samus", new Texture()));
    std::string player_path = "./Assets/Images/samus.gif";
    library_.at("Samus")->Initialize(graphics_device->renderer(), view, player_path);

    // Rock
    library_.insert(std::pair<std::string, Texture*>("Rock", new Texture()));
    std::string rock_path = "./Assets/Images/t_rock.png";
    library_.at("Rock")->Initialize(graphics_device->renderer(), view, rock_path);

    return true;
}

Texture* ArtAssetLibrary::Search(std::string key) {
    return library_.at(key);
}
