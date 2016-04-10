#include "input/controller.h"

Controller::Controller() {
    for (uint8 button = (uint8)kButtonInvalid; button <= (uint8)kButtonMax; button++) {
        buttonstates_[(ControllerButton)button] = false;
    }
    left_joystick_ = glm::vec2(0, 0);
    right_joystick_ = glm::vec2(0, 0);
}

Controller::~Controller() {}

void Controller::SetButton(ControllerButton button, bool is_pressed) {
    buttonstates_[button] = is_pressed;
}

bool Controller::CheckButton(ControllerButton button) const {
    return buttonstates_.at(button);
}

void Controller::set_left_joystick(glm::vec2 position) {
    left_joystick_ = position;
}

glm::vec2 Controller::left_joystick() const {
    return left_joystick_;
}

void Controller::set_right_joystick(glm::vec2 position) {
    right_joystick_ = position;
}
glm::vec2 Controller::right_joystick() const {
    return right_joystick_;
}
