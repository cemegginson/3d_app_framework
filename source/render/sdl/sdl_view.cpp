#include "core/View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input_device, float32 x, float32 y) {
    input_device_ = input_device;
    velocity_ = 400;
    position_.x = x;
    position_.y = y;
    return true;
}

void View::Update(float32 delta_time) {
    if (input_device_->IsPressed(kGameUp)) {
        position_.y += velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameDown)) {
        position_.y -= velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameLeft)) {
        position_.x += velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameRight)) {
        position_.x -= velocity_ * delta_time;
    }
    return;
}

Vector2 View::position() {
    return position_;
}
