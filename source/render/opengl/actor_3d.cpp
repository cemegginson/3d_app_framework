#include "render/opengl/actor_3d.h"

Actor3D::Actor3D() {

}

Actor3D::~Actor3D() {

}

void Actor3D::AddComponent(Component* new_component) {
    omponents_.push_back(new_component);
}

void Actor3D::Update(float32 delta_time) {

}
