#include <math.h>
#include "Carrier.h"
#include "GameFunctions.h"

#include <iostream>

Carrier::Carrier(std::shared_ptr<Actor> owner) : Component(owner) {}

Carrier::~Carrier() {}

void Carrier::Update(float32 delta_time) {
	angle += rotation * delta_time;
	if(angle > 360) {
		angle -= 360;
	} else if(angle < 0) {
		angle += 360;
	}

	float32 radian_angle = (angle * (PI / 180.0)) - PI;
	Vector2 temp_position;
	temp_position.x = RW2PW((float32)((radius * cos(radian_angle)) + center.x));
	temp_position.y = RW2PW((float32)((radius * sin(radian_angle)) + center.y));

	position.x = PW2RW(temp_position.x);
	position.y = PW2RW(temp_position.y);

	owner_->SetPosition(position);
	owner_->SetAngle(angle);
}

void Carrier::Initialize() {
	position = owner_->GetPosition();
	angle = owner_->GetAngle();
	rotation = 120;
	center = position;
	radius = rand() % 100;
	center.x += radius;
//
// 	// Physics stuff
// 	body_definition.type = b2_dynamicBody;
// 	body_definition.position.Set(RW2PW((int)position.x), RW2PW((int)position.y));
// 	body_definition.angle = RW2PWAngle(angle);
// 	body_definition.angularDamping = 10.0;
// 	body_definition.linearDamping = 10.0;
// 	body = world->CreateBody(&body_definition);
//
// 	shape.SetAsBox(RW2PW(w/2), RW2PW(h/2));
// 	shapefd.shape = &shape;
// 	shapefd.density = 0.1f;
// 	shapefd.friction = 0.0f;
// 	shapefd.restitution = 0.0f;
// 	body->CreateFixture(&shapefd);
}
