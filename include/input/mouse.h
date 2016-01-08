#pragma once

#include <map>
#include <utility>

#include "glm/vec2.hpp"

#include "input/control_utils.h"

class Mouse {
protected:
    std::map<MouseButton, bool> buttonstates_;
    glm::vec2 position_;
    glm::vec2 movement_;

public:
    Mouse();
    ~Mouse();

    void SetButton(MouseButton button, bool is_pressed);
    bool CheckButton(MouseButton button);

    void set_position(glm::vec2 new_position);
    glm::vec2 position();

    void set_movement(glm::vec2 movement);
    glm::vec2 movement();
};
