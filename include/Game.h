#pragma once

#include <list>
#include <string>

#include "Box2D/Box2D.h"

#include "ComponentLibrary.h"
#include "ArtAssetLibrary.h"
#include "Timer.h"
#include "View.h"
#include "Component.h"

class Game {
protected:
	ComponentLibrary* component_factories_;
	ArtAssetLibrary* art_library_;
	GraphicsDevice* graphics_device_;
	InputDevice* input_device_;
	Timer* timer_;
	View* view_;
	std::list<std::shared_ptr<Actor>> actors_;
	b2World* world_;
	float32 physics_delta_time_;
	uint32 velocity_iterations_;
	uint32 position_iterations_; 

public:
	Game();
	~Game();
	bool Initialize(GraphicsDevice*, InputDevice*);
	void Reset();
	bool LoadLevel(std::string);
	void Run();
	void Update(float32);
};
