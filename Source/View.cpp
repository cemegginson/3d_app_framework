#include "View.h"

View::View() {}

View::~View() {}

bool View::Initialize(InputDevice* input, float32 x, float32 y) {
	input_device = input;
	velocity_ = 400;
	position.x = x;
	position.y = y;
	return true;
}

void View::Update(float32 delta_time) {
	if(input_device->IsPressed(GAME_UP)) {
		position.y += velocity_ * delta_time;
	}
	if(input_device->IsPressed(GAME_DOWN)) {
		position.y -= velocity_ * delta_time;
	}
	if(input_device->IsPressed(GAME_LEFT)) {
		position.x += velocity_ * delta_time;
	}
	if(input_device->IsPressed(GAME_RIGHT)) {
		position.x -= velocity_ * delta_time;
	}
	return;
}

Vector2 View::GetPosition() {
	return position;
}
