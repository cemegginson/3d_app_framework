#include <math.h>
#include <memory>
#include "GameFunctions.h"
#include "Player.h"

Player::Player(std::shared_ptr<Actor> owner) : Component(owner) {
	input_device_ = nullptr;
	radius_ = 27;
	travel_ = 200;
	rotation_ = 360.0;
	last_fire_time_ = 0;
}

Player::~Player() {
	;
}

void Player::Update(float32 delta_time) {
	float32 angle = owner_->GetAngle();
	Vector2 old_position = owner_->GetPosition();
	Vector2 new_position = old_position;

	float32 theta = RW2PWAngle(angle - 90);
	float32 tcos = cos(theta);
	float32 tsin = sin(theta);

	if(input_device_->IsPressed(GAME_A)) {
		// angle = angle - rotation_ * delta_time;
		owner_->SetEvent(TURN_LEFT);
	}
	if(input_device_->IsPressed(GAME_D)) {
		// angle = angle + rotation_ * delta_time;
		owner_->SetEvent(TURN_RIGHT);
	}
	if(input_device_->IsPressed(GAME_W)) {
		// new_position.x += travel_ * tcos * delta_time;
		// new_position.y += travel_ * tsin * delta_time;
		owner_->SetEvent(MOVE_UP);
	}
	if(input_device_->IsPressed(GAME_S)) {
		// new_position.x -= travel_ * tcos * delta_time;
		// new_position.y -= travel_ * tsin * delta_time;
		owner_->SetEvent(MOVE_DOWN);
	}

	Vector2 movement;
	movement.x = new_position.x - old_position.x;
	movement.y = new_position.y - old_position.y;

	owner_->SetAngle(angle);
	owner_->SetMovement(movement);

	last_fire_time_ += delta_time;
	// Create bullet if spacebar pressed
	// if(input_device_->IsPressed(GAME_SPACE) && last_fire_time_ > .075){
	// 	last_fire_time_ = 0;
	// 	Vector2 direction;
	// 	direction.x = 2 * tcos;
	// 	direction.y = 2 * tsin;
	//
	// 	Vector2 bulletpos;
	// 	bulletpos.x = position.x + center.x + radius * tcos;
	// 	bulletpos.y = position.y + center.y + radius * tsin;
	//
	// 	std::shared_ptr<Bullet> bullet = new Bullet();
	// 	bullet->Initialize(graphics_device_, art_library->Search("Bullet"), world, bulletpos, direction);
	// 	bullets.push_front(bullet);
	// }
}

void Player::Initialize() {
	;
}

void Player::SetInput(InputDevice* input_device) {
	input_device_ = input_device;
}
