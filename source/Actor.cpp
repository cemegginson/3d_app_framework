#include <string>

#include "Actor.h"

Actor::Actor() {}

Actor::~Actor() {}

void Actor::Initialize(std::string name,
                       Vector2 position,
                       uint32 angle,
                       bool controllable) {
    name_ = name;
    position_ = position;
    angle_ = angle;
    sprite_clip_.x = 0;
    sprite_clip_.y = 0;
    sprite_clip_.w = 35;
    sprite_clip_.h = 60;

    actor_events_[kMoveUp] = false;
    actor_events_[kMoveDown] = false;
    actor_events_[kMoveLeft] = false;
    actor_events_[kMoveRight] = false;
    actor_events_[kTurnLeft] = false;
    actor_events_[kTurnRight] = false;
}

void Actor::AddComponent(Component* component) {
    components_.push_back(component);
}

void Actor::Update(float32 delta_time) {
    ResetEvents();

    for (auto iter = components_.begin(); iter != components_.end(); ++iter) {
        (*iter)->Update(delta_time);
    }
}

Vector2 Actor::GetPosition() {
    return position_;
}
void Actor::SetPosition(Vector2 new_position) {
    position_ = new_position;
}

float32 Actor::GetAngle() {
    return angle_;
}
void Actor::SetAngle(float32 new_angle) {
    angle_ = new_angle;
}

SDL_Rect Actor::GetSpriteClip() {
    return sprite_clip_;
}
void Actor::SetSpriteClip(SDL_Rect new_sprite_clip) {
    sprite_clip_ = new_sprite_clip;
}

void Actor::SetEvent(ActorEvent event) {
    actor_events_.at(event) = true;
}
bool Actor::CheckEvent(ActorEvent event) {
    return actor_events_.at(event);
}
void Actor::ResetEvents() {
    for (auto iter = actor_events_.begin(); iter != actor_events_.end(); ++iter) {
        iter->second = false;
    }
}

bool Actor::IsControllable() {
    return controllable_;
}
