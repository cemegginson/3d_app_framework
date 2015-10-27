#include <math.h>
#include <memory>
#include "GameFunctions.h"
#include "Player.h"

Player::Player(std::shared_ptr<Actor> owner) : Component(owner) {
    input_device_ = nullptr;
    travel_ = 200;
    rotation_ = 360.0;
    last_fire_time_ = 0;
}

Player::~Player() {}

void Player::Update(float32 delta_time) {
    float32 angle = owner_->angle();
    Vector2 old_position = owner_->transform();
    Vector2 new_position = old_position;

    float32 theta = RW2PWAngle(angle - 90);
    float32 tcos = cos(theta);
    float32 tsin = sin(theta);

    if (input_device_->IsPressed(kGameA)) {
        owner_->SetEvent(kMoveLeft);
    }
    if (input_device_->IsPressed(kGameD)) {
        owner_->SetEvent(kMoveRight);
    }
    if (input_device_->IsPressed(kGameW)) {
        owner_->SetEvent(kMoveUp);
    }
    if (input_device_->IsPressed(kGameS)) {
        owner_->SetEvent(kMoveDown);
    }

    last_fire_time_ += delta_time;
    // Create bullet if spacebar pressed
    // if(input_device_->IsPressed(kGameSpace) && last_fire_time_ > .075){
    //     last_fire_time_ = 0;
    //     Vector2 direction;
    //     direction.x = 2 * tcos;
    //     direction.y = 2 * tsin;
    //
    //     Vector2 bulletpos;
    //     bulletpos.x = position.x + center.x + radius * tcos;
    //     bulletpos.y = position.y + center.y + radius * tsin;
    //
    //     std::shared_ptr<Bullet> bullet = new Bullet();
    //     bullet->Initialize(graphics_device_, art_library->Search("Bullet"), world, bulletpos, direction);
    //     bullets.push_front(bullet);
    // }
}

void Player::Initialize() {}

void Player::set_input_device(InputDevice* input_device) {
    input_device_ = input_device;
}
