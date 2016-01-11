#include "render/opengl/actor_3d.h"

#include "event_system/Dispatcher.h"
#include "event_system/Subscriber.h"


Actor3D::Actor3D() {
    position_ = glm::vec3(0.0, 0.0, 0.0);

    Subscriber* update_subscriber = new Subscriber(this);
    update_subscriber->method = std::bind(&Actor3D::Update, this, std::placeholders::_1);
    Dispatcher::GetInstance()->AddEventSubscriber(update_subscriber, "EVENT_ACTOR_UPDATE");

}

Actor3D::~Actor3D() {

}

// void Actor3D::Initialize(std::string name) {
//
// }

void Actor3D::AddComponent(Component* new_component) {
    components_.push_back(new_component);
}

void Actor3D::Update(std::shared_ptr<void> delta_time) {

}

glm::vec3 Actor3D::position() {
    return position_;
}
