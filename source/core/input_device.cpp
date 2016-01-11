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

	Subscriber* new_input_subscriber = new Subscriber(this);
	new_input_subscriber->method = std::bind(&InputDevice::NewInput, this, std::placeholders::_1);
	Dispatcher::GetInstance()->AddEventSubscriber(new_input_subscriber, "EVENT_INPUT_NEW");

    return true;
}

void InputDevice::NewInput(std::shared_ptr<void> event) {
    SDL_Event* sdl_event = (SDL_Event*)event.get();

    if (sdl_event->type == SDL_KEYDOWN) {
        keystates_[translations_[sdl_event->key.keysym.sym]] = true;
    } else if (sdl_event->type == SDL_KEYUP) {
        keystates_[translations_[sdl_event->key.keysym.sym]] = false;
    }
}

bool InputDevice::IsPressed(GameEvent event) {
    return keystates_.at(event);
}
