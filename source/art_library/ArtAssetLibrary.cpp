// #include <string>
// #include <utility>
//
// #include "art_library/ArtAssetLibrary.h"
//
// ArtAssetLibrary::ArtAssetLibrary() {}
//
// ArtAssetLibrary::~ArtAssetLibrary() {
//     for(auto iter = library_.begin(); iter != library_.end();) {
//         delete iter->second;
//         iter = library_.erase(iter);
//     }
// }
//
// bool ArtAssetLibrary::LoadAssets(Renderer* renderer, SDLCamera* SDLCamera) {
//     SDL_Renderer* tmp_renderer = static_cast<SDLRenderer*>(renderer)->renderer();
//     // Bullet
//     library_.insert(std::pair<std::string, SDLTexture*>("Bullet", new SDLTexture()));
//     std::string bullet_path = "./Assets/Images/t_bullet.png";
//     library_.at("Bullet")->Initialize(tmp_renderer, SDLCamera, bullet_path);
//
//     // Carrier
//     library_.insert(std::pair<std::string, SDLTexture*>("Carrier", new SDLTexture()));
//     std::string carrier_path = "./Assets/Images/t_carrier.png";
//     library_.at("Carrier")->Initialize(tmp_renderer, SDLCamera, carrier_path);
//
//     // Infantry
//     library_.insert(std::pair<std::string, SDLTexture*>("Infantry", new SDLTexture()));
//     std::string infantry_path = "./Assets/Images/t_infantry.png";
//     library_.at("Infantry")->Initialize(tmp_renderer, SDLCamera, infantry_path);
//
//     // Samus
//     library_.insert(std::pair<std::string, SDLTexture*>("Samus", new SDLTexture()));
//     std::string player_path = "./Assets/Images/samus.gif";
//     library_.at("Samus")->Initialize(tmp_renderer, SDLCamera, player_path);
//
//     // Rock
//     library_.insert(std::pair<std::string, SDLTexture*>("Rock", new SDLTexture()));
//     std::string rock_path = "./Assets/Images/t_rock.png";
//     library_.at("Rock")->Initialize(tmp_renderer, SDLCamera, rock_path);
//
//     return true;
// }
//
// SDLTexture* ArtAssetLibrary::Search(std::string key) {
//     return library_.at(key);
// }
