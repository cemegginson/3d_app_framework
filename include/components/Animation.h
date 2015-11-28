#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

#include "SDL.h"

#include "virtual/Component.h"
#include "util/definitions.h"

class Animation : public Component {
protected:
    SDL_Rect sprite_clip_;
    std::map<std::string, std::vector<SDL_Rect>*> animations_;
    std::vector<SDL_Rect>* current_animation_;
    float32 frame_time_;
    uint16 current_frame_;

    std::map<State, bool> last_state_;
    std::map<State, bool> state_;
    // bool moving_;

public:
    Animation(Actor*);
    ~Animation();
    void Update(std::shared_ptr<void> delta_time);
    void UpdateState();
    void Initialize();
    void AddAnimation(std::string, std::vector<SDL_Rect>*);
    void ChooseAnimation();
    void SetAnimation(std::string);
    bool EventStateIsCurrent();
    void CopyEventState();
};
