#pragma once

#include <memory>
#include <string>

#include "virtual/Component.h"
#include "util/definitions.h"

class Infantry : public Component {
protected:
    float32 rotation_rate_;

public:
    Infantry(Actor*);
    ~Infantry();
    void Update(std::shared_ptr<void> delta_time);
    void Initialize();
};
