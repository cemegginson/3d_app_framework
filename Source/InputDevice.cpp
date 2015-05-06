#include <iostream>
#include "InputDevice.h"

InputDevice::InputDevice() { game_event_ = GAME_NA; }

InputDevice::~InputDevice() {}

bool InputDevice::Initialize() {
	translations_[SDLK_UP] = GAME_UP;
	translations_[SDLK_DOWN] = GAME_DOWN;
	translations_[SDLK_LEFT] = GAME_LEFT;
	translations_[SDLK_RIGHT] = GAME_RIGHT;
	translations_[SDLK_w] = GAME_W;
	translations_[SDLK_a] = GAME_A;
	translations_[SDLK_s] = GAME_S;
	translations_[SDLK_d] = GAME_D;
	translations_[SDLK_SPACE] = GAME_SPACE;

	keystates_[GAME_UP] = false;
	keystates_[GAME_DOWN] = false;
	keystates_[GAME_LEFT] = false;
	keystates_[GAME_RIGHT] = false;
	keystates_[GAME_W] = false;
	keystates_[GAME_A] = false;
	keystates_[GAME_S] = false;
	keystates_[GAME_D] = false;
	keystates_[GAME_SPACE] = false;

	return true;
}

void InputDevice::Update(SDL_Event* event) {
	if(event->type == SDL_KEYDOWN){
		keystates_[translations_[event->key.keysym.sym]] = true;
	} else if(event->type == SDL_KEYUP) {
		keystates_[translations_[event->key.keysym.sym]] = false;
	}
}

bool InputDevice::IsPressed(GameEvent event) {
	return keystates_.at(event);
}
