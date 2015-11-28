#include "core/View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input_device, float32 x, float32 y) {
    input_device_ = input_device;
    velocity_ = 400;
    transform_.x = x;
    transform_.y = y;
    return true;
}

void View::Update(float32 delta_time) {
    if (input_device_->IsPressed(kGameUp)) {
        transform_.y += velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameDown)) {
        transform_.y -= velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameLeft)) {
        transform_.x += velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameRight)) {
        transform_.x -= velocity_ * delta_time;
    }
    return;
}

Vector2 View::transform() {
    return transform_;
}
