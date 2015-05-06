#pragma once

#include <string>

#include "Definitions.h"
#include "Component.h"

class Carrier : public Component {
protected:
	Vector2 position;
	Vector2 center;
	float32 rotation;
	int radius;
	float32 angle;

public:
	Carrier(std::shared_ptr<Actor>);
	~Carrier();
	void Update(float32);
	void Initialize();
};
