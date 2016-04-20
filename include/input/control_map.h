#pragma once

#include "util/definitions.h"

#include "input/control_utils.h"
#include "input/controller.h"
#include "input/keyboard.h"
#include "input/mouse.h"

class ControlMap {
protected:
    std::map<, bool> event_triggers_;
    ControllerPtr controller_;
    KeyboardPtr keyboard_;
    MousePtr mouse_;

public:
    ControlMap();
    ~ControlMap();

    void Update();
    bool CheckEvent();
};

typedef std::shared_ptr<ControlMap> ControlMapPtr;
typedef std::weak_ptr<ControlMap> ControlMapWeakPtr;
