#include "Component.h"

Component::Component(std::shared_ptr<Actor> owner) {
    owner_ = owner;
}

Component::~Component() {
    // delete owner_;
}
