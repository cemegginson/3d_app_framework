#include "input/keyboard.h"

Keyboard::Keyboard() {
    for (auto key = kKeyA; key <= kKeyUnderscore; key++) {
        keystates_[key] = false;
    }
}

Keyboard::~Keyboard() {}

void Keyboard::SetKey(KeyboardKey key, bool is_pressed) {
    keystates_[key] = is_pressed;
}

bool Keyboard::CheckKey(KeyboardKey key) {
    return keystates_.at(key);
}
