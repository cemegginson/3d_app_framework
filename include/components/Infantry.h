#pragma once

#include <memory>
#include <string>

#include "virtual/component.h"
#include "util/definitions.h"

class Infantry : public Component {
protected:
    Actor2D* owner_;
    std::vector<Subscriber*> subscribers_;
    float32 rotation_rate_;

public:
    Infantry(Actor2D*);
    ~Infantry();
    void Update(std::shared_ptr<void> delta_time);
    void Initialize();
};
