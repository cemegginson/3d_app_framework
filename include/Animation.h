#pragma once

#include <string>
#include <vector>

#include "SDL.h"

#include "Component.h"
#include "Definitions.h"

class Animation : public Component {
protected:
    SDL_Rect sprite_clip_;
    std::map<std::string, std::vector<SDL_Rect>*> animations_;
    std::vector<SDL_Rect>* current_animation_;
    float32 frame_time_;
    uint16 current_frame_;

    std::map<State, bool> last_state_;
    std::map<State, bool> state_;
    bool event_state_is_current_;

public:
    Animation(std::shared_ptr<Actor>);
    ~Animation();
    void Update(float32);
    void UpdateState();
    void Initialize();
    void AddAnimation(std::string, std::vector<SDL_Rect>*);
    void ChooseAnimation();
    void SetAnimation(std::string);
    bool EventStateIsCurrent();
    void CopyEventState();
};
