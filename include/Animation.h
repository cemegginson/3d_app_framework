#pragma once

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

    std::map<ActorEvent, bool> actor_events_;
    bool event_state_is_current_;

public:
    Animation(std::shared_ptr<Actor>);
    ~Animation();
    void Update(float32);
    void Initialize();
    void AddAnimation(std::string, std::vector<SDL_Rect>*);
    void SetAnimation(std::string);
    bool EventStateIsCurrent();
};
