#pragma once

#include <list>
#include <string>

#include "ArtAssetLibrary.h"
#include "Bullet.h"
#include "Component.h"
#include "Definitions.h"


class Player : public Component {
protected:
	ArtAssetLibrary* art_library_;
	GraphicsDevice* graphics_device_;
	InputDevice* input_device_;
	uint32 travel_;
	uint32 radius_;
	Vector2 center_;
	float32 rotation_;
	float32 last_fire_time_;

public:
	Player(std::shared_ptr<Actor>);
	~Player();
	void Update(float32);
	void Initialize();
	void SetInput(InputDevice*);
};
