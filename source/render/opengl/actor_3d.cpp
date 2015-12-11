#include "render/opengl/actor_3d.h"

Actor3D::Actor3D() {
    position_ = glm::vec3(0, 0, 0);
}

Actor3D::~Actor3D() {

}

// void Actor3D::Initialize(std::string name) {
//
// }

void Actor3D::AddComponent(Component* new_component) {
    components_.push_back(new_component);
}

void Actor3D::Update(float32 delta_time) {

}

glm::vec3 Actor3D::position() {
    return position_;
}
