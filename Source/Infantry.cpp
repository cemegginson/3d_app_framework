#include "Infantry.h"

#include "GameFunctions.h"

Infantry::Infantry(std::shared_ptr<Actor> owner) : Component(owner) {
	rotation_rate_ = 90;
}

Infantry::~Infantry() {
	;
}

void Infantry::Update(float32 delta_time) {
	// float32 angle = owner_->GetAngle();
	// angle += rotation_rate_ * delta_time;
	// owner_->SetAngle(angle);

	owner_->SetEvent(TURN_RIGHT);
}

void Infantry::Initialize() {
	;
}
