#include "input/sdl_input.h"

SDLInput::SDLInput() {}

SDLInput::~SDLInput() {}

void SDLInput::Initialize() {
    SDL_InitSubSystem(SDL_INIT_EVENTS);
}

void SDLInput::Update() {
    SDL_Event event;
    bool quit = false;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        // Update the Input Device with the Event
        input_device->Update(&event);
    }
}
