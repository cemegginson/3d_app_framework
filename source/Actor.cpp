#include <string>

#include "Actor.h"

Actor::Actor() {}

Actor::~Actor() {}

void Actor::Initialize(std::string name,
                       Vector2 transform,
                       uint32 angle,
                       bool controllable) {
    name_ = name;
    transform_ = transform;
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

Vector2 Actor::transform() {
    return transform_;
}
void Actor::set_transform(Vector2 new_transform) {
    transform_ = new_transform;
}

float32 Actor::angle() {
    return angle_;
}
void Actor::set_angle(float32 new_angle) {
    angle_ = new_angle;
}

SDL_Rect Actor::sprite_clip() {
    return sprite_clip_;
}
void Actor::set_sprite_clip(SDL_Rect new_sprite_clip) {
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
