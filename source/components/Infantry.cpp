// Copyright 2015 Casey Megginson and Blaise Koch
#include "components/Infantry.h"

#include "util/box2d_utils.h"

Infantry::Infantry(Actor* owner) {
    owner_ = owner;
    rotation_rate_ = 90;

    Subscriber* s = new Subscriber(this);
    s->method = std::bind(&Infantry::Update, this, std::placeholders::_1);
    Dispatcher::GetInstance()->AddEventSubscriber(s, "EVENT_COMPONENT_UPDATE");
    subscribers_.push_back(s);
}

Infantry::~Infantry() {
    while (subscribers_.size() > 0) {
        delete subscribers_.back();
        subscribers_.pop_back();
    }
}

void Infantry::Update(std::shared_ptr<void> delta_time) {
    UNUSED(delta_time);

    // float32 angle = owner_->angle();
    // angle += rotation_rate_ * delta_time;
    // owner_->set_angle(angle);

    owner_->SetEvent(kTurnRight);
}

void Infantry::Initialize() {}
