#pragma once

#include "InputDevice.h"
#include "Definitions.h"

class View {
protected:
	InputDevice* input_device;
	Vector2 position;
	uint32 velocity_;

public:
	View();
	~View();
	bool Initialize(InputDevice*, float32, float32);
	void Update(float32);
	Vector2 GetPosition();
};
