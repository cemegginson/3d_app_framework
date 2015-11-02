#include <math.h>
#include <memory>
#include "Util/GameFunctions.h"
#include "Component/Player.h"

Player::Player(Actor* owner) : Component(owner) {
    input_device_ = nullptr;
    travel_ = 200;
    rotation_ = 360.0;
    last_fire_time_ = 0;

    Subscriber* s = new Subscriber(this);
    s->method = std::bind(&Player::Update, this, std::placeholders::_1);
    Dispatcher::AddEventSubscriber(s, Events::EVENT_COMPONENT_UPDATE);
    subscribers.push_back(s);
}

Player::~Player() {
    while(subscribers.size() > 0) {
        delete subscribers.back();
        subscribers.pop_back();
    }
}

void Player::Update(std::shared_ptr<void> delta_time) {
    float time = *(float*)delta_time.get();
    std::cout << "Player updated " << time << std::endl;

    float32 angle = owner_->angle();
    Vector2 old_position = owner_->transform();
    Vector2 new_position = old_position;

    float32 theta = RW2PWAngle(angle - 90);
    float32 tcos = cos(theta);
    float32 tsin = sin(theta);

    if (input_device_->IsPressed(kGameA)) {
        std::cout << "PRESSED LEFT" << std::endl;
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

    last_fire_time_ += time;
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
