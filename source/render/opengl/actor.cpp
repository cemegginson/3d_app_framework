#include "render/actor.h"

Actor::Actor() {
    position_ = glm::vec3(0.0, 0.0, 0.0);
}

Actor::~Actor() {

}

// void Actor::Initialize(std::string name) {
//
// }

void Actor::AddComponent(Component* new_component) {
    components_.push_back(new_component);
}

void Actor::Update() {
    for (auto iter = components_.begin(); iter != components_.end(); ++iter) {
        (*iter)->Update();
    }
}

glm::vec3 Actor::position() {
    return position_;
}
