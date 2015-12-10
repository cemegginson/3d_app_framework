#pragma once

#include <memory>
#include <string>

#include "virtual/component.h"
#include "util/definitions.h"

class Infantry : public Component {
protected:
    Actor* owner_;
    std::vector<Subscriber*> subscribers_;
    float32 rotation_rate_;

public:
    Infantry(Actor*);
    ~Infantry();
    void Update(std::shared_ptr<void> delta_time);
    void Initialize();
};
