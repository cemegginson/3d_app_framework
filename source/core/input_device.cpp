#include "core/input_device.h"

InputDevice::InputDevice() {
  game_event_ = kGameNA;
}

bool InputDevice::Initialize() {
    translations_[SDLK_UP] = kGameUp;
    translations_[SDLK_DOWN] = kGameDown;
    translations_[SDLK_LEFT] = kGameLeft;
    translations_[SDLK_RIGHT] = kGameRight;
    translations_[SDLK_w] = kGameW;
    translations_[SDLK_a] = kGameA;
    translations_[SDLK_s] = kGameS;
    translations_[SDLK_d] = kGameD;
    translations_[SDLK_SPACE] = kGameSpace;

    keystates_[kGameUp] = false;
    keystates_[kGameDown] = false;
    keystates_[kGameLeft] = false;
    keystates_[kGameRight] = false;
    keystates_[kGameW] = false;
    keystates_[kGameA] = false;
    keystates_[kGameS] = false;
    keystates_[kGameD] = false;
    keystates_[kGameSpace] = false;

    return true;
}

void InputDevice::Update(SDL_Event* event) {
    if (event->type == SDL_KEYDOWN) {
        keystates_[translations_[event->key.keysym.sym]] = true;
    } else if (event->type == SDL_KEYUP) {
        keystates_[translations_[event->key.keysym.sym]] = false;
    }
}

bool InputDevice::IsPressed(GameEvent event) {
    return keystates_.at(event);
}
