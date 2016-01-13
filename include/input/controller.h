#pragma once

#include <map>
#include <utility>

#include "glm/vec2.hpp"

#include "input/control_utils.h"
#include "util/definitions.h"

class Controller {
protected:
    std::map<ControllerButton, bool> buttonstates_;
    glm::vec2 left_joystick_;
    glm::vec2 right_joystick_;

public:
    Controller();
    ~Controller();

    void SetButton(ControllerButton button, bool is_pressed);
    bool CheckButton(ControllerButton button);

    void set_left_joystick(glm::vec2 position);
    glm::vec2 left_joystick();

    void set_right_joystick(glm::vec2 position);
    glm::vec2 right_joystick();
};

typedef std::shared_ptr<Controller> ControllerPtr;
typedef std::weak_ptr<Controller> ControllerWeakPtr;
