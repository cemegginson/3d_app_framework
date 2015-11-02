#include "Sprite.h"

Sprite::Sprite(Actor* owner) : Component(owner) {
    texture_ = nullptr;

    Subscriber* s = new Subscriber(this);
    s->method = std::bind(&Sprite::Update, this, std::placeholders::_1);
    Dispatcher::AddEventSubscriber(s, Events::EVENT_COMPONENT_UPDATE);
    subscribers.push_back(s);
}

Sprite::~Sprite() {
    while(subscribers.size() > 0) {
        delete subscribers.back();
        subscribers.pop_back();
    }
}

void Sprite::Initialize(GraphicsDevice* graphics_device, Texture* texture) {
    graphics_device_ = graphics_device;
    graphics_device_->AddSprite(this);
    texture_ = texture;

    // Add Sprite to graphics_device_
    // graphics_device_->AddSprite(shared_from_this());

}

void Sprite::Update(std::shared_ptr<void> delta_time) {
    sprite_clip_ = owner_->sprite_clip();
}

void Sprite::Render() {
    Vector2 position = owner_->transform();
    float32 angle = owner_->angle();
    // Not finished here
    texture_->Render(position, angle, sprite_clip_);
    // texture_->Render(position, angle);
}
