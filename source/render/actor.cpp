#include "render/actor.h"

#include "event_system/Dispatcher.h"
#include "event_system/Subscriber.h"


Actor::Actor() {
    position_ = glm::vec3(0.0, 0.0, 0.0);

    Subscriber* update_subscriber = new Subscriber(this);
    update_subscriber->method = std::bind(&Actor::Update, this);
    Dispatcher::GetInstance()->AddEventSubscriber(update_subscriber, "EVENT_ACTOR_UPDATE");

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

}

glm::vec3 Actor::position() {
    return position_;
}
