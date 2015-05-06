#include "Animation.h"

Animation::Animation(std::shared_ptr<Actor> owner) : Component(owner) {
    current_animation_ = nullptr;
}
Animation::~Animation() {
    ;
}

void Animation::Update(float32 delta_time) {
    frame_time_ += delta_time;
    if(frame_time_ >= .07) {
        frame_time_ = 0;
        current_frame_++;
        if(current_animation_ != nullptr && current_frame_ >= current_animation_->size()) {
            current_frame_ = 0;
        }
        owner_->SetSpriteClip(current_animation_->at(current_frame_));
    }
    if(!EventStateIsCurrent()) {
        SyncEventState();

        if(owner_->CheckEvent(MOVE_LEFT)) {
            SetAnimation("run-left");
        }
        if(owner_->CheckEvent(MOVE_RIGHT)) {
            SetAnimation("run-right");
        }
        if(owner_->CheckEvent(MOVE_UP)) {
            ;
        }
        if(owner_->CheckEvent(MOVE_DOWN)) {
            ;
        }
    }
}

void Animation::Initialize() {
    actor_events_[MOVE_UP] = false;
    actor_events_[MOVE_DOWN] = false;
    actor_events_[MOVE_LEFT] = false;
    actor_events_[MOVE_RIGHT] = false;

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
