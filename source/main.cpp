// Copyright 2015 Casey Megginson and Blaise Koch

#include <ctime>
#include <iostream>
#include <string>

// Media Libraries
#include "SDL.h"

// Project Libraries
#include "util/definitions.h"
#include "core/app_3d.h"
#include "core/input_device.h"

int main(int argc, char* argv[]) {
    UNUSED(argc); UNUSED(argv);
    SDL_Init(0);

    //========================================
    // Initialize the random number generator
    //========================================
    srand((unsigned int)time(NULL));

    //========================================
    // Construct Input Device
    //========================================
    InputDevice* input_device = new InputDevice();
    if (!input_device->Initialize()) {
        printf("Input Device could not initialize!");
        exit(1);
    }

    //========================================
    // Construct Game
    //========================================
    App3D* app = new App3D();
    if (!app->Initialize(input_device)) {
        printf("Game could not Initialize!");
        exit(1);  // this case will leak a lot of memory...
                  // should properly do destructor calls and proper shutdown
    }

    //========================================
    // Load Level
    //========================================
    app->Reset();
    std::string level_config_file = "foobar.xml";
    if (!app->LoadLevel(level_config_file)) {
        printf("Game could not load level %s: ",
               level_config_file.c_str());
        exit(1);  // this case will leak a lot of memory...
                  // should properly do destructor calls and proper shutdown
    }

    SDL_InitSubSystem(SDL_INIT_EVENTS);
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            // Update the Input Device with the Event
            if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                input_device->Update(&event);
            }
        }
        app->Run();
    }

    //========================================
    // Clean-up
    //========================================
    if (app != nullptr) {
        delete app;
        app = nullptr;
    }

    if (input_device != nullptr) {
        delete input_device;
        input_device = nullptr;
    }

    SDL_Quit();

    return 0;
}
