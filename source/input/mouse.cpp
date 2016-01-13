#include "input/mouse.h"

Mouse::Mouse() {
    for (uint8 button = (uint8)kMouseLeft; button <= (uint8)kMouse5; button++) {
        buttonstates_[(MouseButton)button] = false;
    }
    position_ = glm::vec2(0, 0);
    movement_ = glm::vec2(0, 0);
}

Mouse::~Mouse() {}

void Mouse::SetButton(MouseButton button, bool is_pressed) {
    buttonstates_[button] = is_pressed;
}

bool Mouse::CheckButton(MouseButton button) {
    return buttonstates_.at(button);
}

void Mouse::set_position(glm::vec2 new_position) {
    position_ = new_position;
}

glm::vec2 Mouse::position() {
    return position_;
}

void Mouse::set_movement(glm::vec2 movement) {
    movement_ = movement;
}

glm::vec2 Mouse::movement() {
    return movement_;
}
