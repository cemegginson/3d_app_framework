#pragma once

#include <memory>
#include <string>

#include "Component.h"
#include "Definitions.h"

class Infantry : public Component {
protected:
	float32 rotation_rate_;

public:
	Infantry(std::shared_ptr<Actor>);
	~Infantry();
	void Update(float32);
	void Initialize();
};
