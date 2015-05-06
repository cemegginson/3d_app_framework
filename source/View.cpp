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
	if(input_device->IsPressed(kGameUp)) {
		position.y += velocity_ * delta_time;
	}
	if(input_device->IsPressed(kGameDown)) {
		position.y -= velocity_ * delta_time;
	}
	if(input_device->IsPressed(kGameLeft)) {
		position.x += velocity_ * delta_time;
	}
	if(input_device->IsPressed(kGameRight)) {
		position.x -= velocity_ * delta_time;
	}
	return;
}

Vector2 View::GetPosition() {
	return position;
}
