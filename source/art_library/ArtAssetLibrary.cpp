#include <string>

#include "art_library/ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary() {}

ArtAssetLibrary::~ArtAssetLibrary() {
    for(auto iter = library_.begin(); iter!=library_.end();) {
        delete iter->second;
        iter = library_.erase(iter);
    }
}

bool ArtAssetLibrary::LoadAssets(Renderer* renderer, View* view) {
    #if RENDER_TYPE == 0
        SDL_Renderer* tmp_renderer = static_cast<SDLRenderer*>(renderer)->renderer();
        // Bullet
        library_.insert(std::pair<std::string, Texture*>("Bullet", new Texture()));
        std::string bullet_path = "./Assets/Images/t_bullet.png";
        library_.at("Bullet")->Initialize(tmp_renderer, view, bullet_path);

        // Carrier
        library_.insert(std::pair<std::string, Texture*>("Carrier", new Texture()));
        std::string carrier_path = "./Assets/Images/t_carrier.png";
        library_.at("Carrier")->Initialize(tmp_renderer, view, carrier_path);

        // Infantry
        library_.insert(std::pair<std::string, Texture*>("Infantry", new Texture()));
        std::string infantry_path = "./Assets/Images/t_infantry.png";
        library_.at("Infantry")->Initialize(tmp_renderer, view, infantry_path);

        // Samus
        library_.insert(std::pair<std::string, Texture*>("Samus", new Texture()));
        std::string player_path = "./Assets/Images/samus.gif";
        library_.at("Samus")->Initialize(tmp_renderer, view, player_path);

        // Rock
        library_.insert(std::pair<std::string, Texture*>("Rock", new Texture()));
        std::string rock_path = "./Assets/Images/t_rock.png";
        library_.at("Rock")->Initialize(tmp_renderer, view, rock_path);
    #endif

    // I don't know what to do with loading to OpenGL stuff

    return true;
}

Texture* ArtAssetLibrary::Search(std::string key) {
    return library_.at(key);
}
