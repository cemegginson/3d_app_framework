#pragma once

#include <map>
#include <utility>

#include "input/control_utils.h"
#include "util/definitions.h"

class Keyboard {
protected:
    std::map<KeyboardKey, bool> keystates_;

public:
    Keyboard();
    ~Keyboard();

    void SetKey(KeyboardKey key, bool is_pressed);
    bool CheckKey(KeyboardKey key) const;
};

typedef std::shared_ptr<Keyboard> KeyboardPtr;
typedef std::weak_ptr<Keyboard> KeyboardWeakPtr;
