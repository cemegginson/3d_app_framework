#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input, float32 x, float32 y) {
    input_device = input;
    velocity_ = 400;
    transform_.x = x;
    transform_.y = y;
    return true;
}

void View::Update(float32 delta_time) {
    if (input_device->IsPressed(kGameUp)) {
        transform_.y += velocity_ * delta_time;
    }
    if (input_device->IsPressed(kGameDown)) {
        transform_.y -= velocity_ * delta_time;
    }
    if (input_device->IsPressed(kGameLeft)) {
        transform_.x += velocity_ * delta_time;
    }
    if (input_device->IsPressed(kGameRight)) {
        transform_.x -= velocity_ * delta_time;
    }
    return;
}

Vector2 View::transform() {
    return transform_;
}
