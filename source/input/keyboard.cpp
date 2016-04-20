#include "input/keyboard.h"

Keyboard::Keyboard() {
    for (uint8 key = (uint8)kKeyA; key <= (uint8)kKeyUnderscore; key++) {
        keystates_[(KeyboardKey)key] = false;
    }
}

Keyboard::~Keyboard() {}

void Keyboard::SetKey(KeyboardKey key, bool is_pressed) {
    keystates_[key] = is_pressed;
}

bool Keyboard::CheckKey(KeyboardKey key) const {
    return keystates_.at(key);
}
