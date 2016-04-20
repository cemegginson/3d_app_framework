#pragma once

class InputManager {
public:
    virtual void Initialize() = 0;
    virtual void Update() = 0;
};

typedef std::shared_ptr<InputManager> InputManagerPtr;
typedef std::weak_ptr<InputManager> InputManagerWeakPtr;
