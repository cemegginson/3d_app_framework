#include "Animation.h"

Animation::Animation(std::shared_ptr<Actor> owner) : Component(owner) {
    current_animation_ = nullptr;
}
Animation::~Animation() {
    ;
}

void Animation::Update(float32 delta_time) {
    frame_time_ += delta_time;
    if(frame_time_ >= .25) {
        frame_time_ = 0;
        current_frame_++;
        if(current_animation_ != nullptr && current_frame_ >= current_animation_->size()) {
            current_frame_ = 0;
        }
        owner_->SetSpriteClip(current_animation_->at(current_frame_));
    }
    if(!EventStateIsCurrent()) {
        SyncEventState();

        if(actor_events_.at(MOVE_LEFT)) {
            ;
        }
        if(actor_events_.at(MOVE_RIGHT)) {
            SetAnimation("run-right");
        }
        if(actor_events_.at(MOVE_UP)) {
            ;
        }
        if(actor_events_.at(MOVE_DOWN)) {
            ;
        }
        if(actor_events_.at(TURN_LEFT)) {
            ;
        }
        if(actor_events_.at(TURN_RIGHT)) {
            ;
        }
    }
}

void Animation::Initialize() {
    for(auto iter = actor_events_.begin(); iter != actor_events_.end(); ++iter) {
        iter->second = false;
    }
    SetAnimation("face-screen");
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

void Animation::SyncEventState() {
    ActorEvent temp;
    for(auto iter = actor_events_.begin(); iter != actor_events_.end(); ++iter) {
        temp = iter->first;
        actor_events_.at(temp) = owner_->CheckEvent(temp);
    }
}
