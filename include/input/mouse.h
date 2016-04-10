#pragma once

#include <map>
#include <utility>

#include "glm/vec2.hpp"

#include "input/control_utils.h"
#include "util/definitions.h"

class Mouse {
protected:
    std::map<MouseButton, bool> buttonstates_;
    glm::vec2 position_;
    glm::vec2 movement_;

public:
    Mouse();
    ~Mouse();

    void SetButton(MouseButton button, bool is_pressed);
    bool CheckButton(MouseButton button) const;

    void set_position(glm::vec2 new_position);
    glm::vec2 position() const;

    void set_movement(glm::vec2 movement);
    glm::vec2 movement() const;
};

typedef std::shared_ptr<Mouse> MousePtr;
typedef std::weak_ptr<Mouse> MouseWeakPtr;
