#include "Component.h"

Component::Component(Actor* owner) {
    owner_ = owner;
}

Component::~Component() {
    // delete owner_;
}
