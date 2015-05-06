#include "Animation.h"

Animation::Animation(std::shared_ptr<Actor> owner) : Component(owner) {
    ;
}
Animation::~Animation() {
    ;
}
void Animation::Update(float32 delta_time) {
    frame_time_ += delta_time;
    if(frame_time_ >= .25) {
        frame_time_ = 0;
    }
}

void Animation::Initialize() {
    ;
}

void Animation::AddAnimation(std::string name, std::vector<SDL_Rect>* animation) {
    animations_[name] = animation;
}

void Animation::SetAnimation(std::string name) {
    frame_time_ = 0;
    current_animation_ = animations_.at(name);
}

bool Animation::EventStateIsCurrent() {
    ActorEvent temp;
    for(auto iter = actor_events_.begin(); iter != actor_events_.end(); ++iter) {
        temp = iter->first;
        if(actor_events_.at(temp) != owner_->CheckEvent(temp)) {
            return false;
        }
    }

    return true;
}
