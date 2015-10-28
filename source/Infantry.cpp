#include "Infantry.h"

#include "GameFunctions.h"

Infantry::Infantry(Actor* owner) : Component(owner) {
    rotation_rate_ = 90;
}

Infantry::~Infantry() {}

void Infantry::Update(float32 delta_time) {
    // float32 angle = owner_->angle();
    // angle += rotation_rate_ * delta_time;
    // owner_->set_angle(angle);

    owner_->SetEvent(kTurnRight);
}

void Infantry::Initialize() {}
