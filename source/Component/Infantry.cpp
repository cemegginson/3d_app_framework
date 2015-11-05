#include "Component/Infantry.h"

#include "Util/GameFunctions.h"

Infantry::Infantry(Actor* owner) : Component(owner) {
    rotation_rate_ = 90;

    Subscriber* s = new Subscriber(this);
    s->method = std::bind(&Infantry::Update, this, std::placeholders::_1);
    Dispatcher::GetInstance()->AddEventSubscriber(s, "EVENT_COMPONENT_UPDATE");
    subscribers.push_back(s);
}

Infantry::~Infantry() {
    while(subscribers.size() > 0) {
        delete subscribers.back();
        subscribers.pop_back();
    }
}

void Infantry::Update(std::shared_ptr<void> delta_time) {

    // float32 angle = owner_->angle();
    // angle += rotation_rate_ * delta_time;
    // owner_->set_angle(angle);

    owner_->SetEvent(kTurnRight);
}

void Infantry::Initialize() {}
