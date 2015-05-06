#include "Actor.h"

Actor::Actor() {
    ;
}

Actor::~Actor() {
    ;
}

void Actor::Initialize(std::string name, Vector2 position, uint32 angle, bool controllable) {
    name_ = name;
    position_ = position;
    angle_ = angle;
    movement_.x = 0;
    movement_.y = 0;

    actor_events_[MOVE_UP] = false;
    actor_events_[MOVE_DOWN] = false;
    actor_events_[MOVE_LEFT] = false;
    actor_events_[MOVE_RIGHT] = false;
    actor_events_[TURN_LEFT] = false;
    actor_events_[TURN_RIGHT] = false;
}

void Actor::AddComponent(Component* component) {
    components_.push_back(component);
}

void Actor::Update(float32 delta_time) {
    movement_.x = 0;
    movement_.y = 0;
    ResetEvents();

    for(auto iter = components_.begin(); iter != components_.end(); ++iter) {
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

Vector2 Actor::GetMovement() {
    return movement_;
}

void Actor::SetMovement(Vector2 movement) {
    movement_ = movement;
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
