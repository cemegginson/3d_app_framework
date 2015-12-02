#include "render/sdl/sdl_view.h"

SDLView::SDLView() {}

SDLView::~SDLView() {}

bool SDLView::Initialize(InputDevice* input_device, float32 x, float32 y) {
    input_device_ = input_device;
    velocity_ = 400;
    position_.x = x;
    position_.y = y;
    return true;
}

void SDLView::Update(float32 delta_time) {
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

Vector2 SDLView::position() {
    return position_;
}
