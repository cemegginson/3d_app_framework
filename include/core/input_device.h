#pragma once

#include <map>

#include "SDL.h"

#include "util/definitions.h"

class InputDevice {
protected:
    GameEvent game_event_;
    std::map<SDL_Keycode, GameEvent> translations_;
    std::map<GameEvent, bool> keystates_;

public:
    InputDevice();

    bool Initialize();
    void Update(SDL_Event*);
    bool IsPressed(GameEvent);
};
