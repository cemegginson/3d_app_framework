#include "input/controller.h"

Controller::Controller() {
    for (auto button = kButton1; button <= kButton10; button++) {
        buttonstates_[button] = false;
    }
    left_joystick_ = glm::vec2(0, 0);
    right_joystick_ = glm::vec2(0, 0);
}

Controller::~Controller() {}

void Controller::SetButton(ControllerButton button, bool is_pressed) {
    buttonstates_[button] = is_pressed;
}

bool Controller::CheckButton(ControllerButton button) {
    return buttonstates_.at(button);
}

void Controller::set_left_joystick(glm::vec2 position) {
    left_joystick_ = position;
}

glm::vec2 Controller::left_joystick() {
    return left_joystick_;
}

void Controller::set_right_joystick(glm::vec2 position) {
    right_joystick_ = position;
}
glm::vec2 Controller::right_joystick() {
    return right_joystick_;
}
