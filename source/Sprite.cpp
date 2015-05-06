#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Actor> owner) : Component(owner) {
    texture_ = nullptr;
}

Sprite::~Sprite() {
    // delete texture_;
}

void Sprite::Initialize(GraphicsDevice* graphics_device, Texture* texture) {
	graphics_device_ = graphics_device;
    graphics_device_->AddSprite(this);
    texture_ = texture;

	//Add Sprite to graphics_device_
	// graphics_device_->AddSprite(shared_from_this());

}

void Sprite::Update(float32 delta_time) {
    ;
}

void Sprite::Render() {
    Vector2 position = owner_->GetPosition();
    float32 angle = owner_->GetAngle();
    // Not finished here
    // texture_->Render(position, angle, clip);
    texture_->Render(position, angle);
}
