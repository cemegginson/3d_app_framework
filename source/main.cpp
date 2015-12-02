// Copyright 2015 Casey Megginson and Blaise Koch
#include <ctime>
#include <iostream>
#include <string>

// Media Libraries
#include "SDL.h"

// Physics
#include "Box2D/Box2D.h"

// Project Libraries
#include "util/definitions.h"
#include "core/Game.h"
#include "core/InputDevice.h"

// Plugable Renderers
#include "render/Renderer.h"
#include "render/opengl/opengl_renderer.h"
#include "render/sdl/sdl_renderer.h"

// 0 is SDL 1 is opengl
#define RENDER_TYPE 0

int main(int argc, char* argv[]) {
    UNUSED(argc); UNUSED(argv);

    Dispatcher::GetInstance();

    //========================================
    // Initialize the random number generator
    //========================================
    srand((unsigned int)time(NULL));

    //========================================
    // Base Game Constants
    //========================================
    uint32 screen_width = 800;
    uint32 screen_height = 600;

    //========================================
    // Construct Graphical Device
    //========================================
    Renderer* renderer = nullptr;
    #if RENDER_TYPE == 0
        renderer = new SDLRenderer(screen_width, screen_height);
    #elif RENDER_TYPE == 1
        renderer = new OpenGLRenderer(screen_width, screen_height);
    #endif
    static_assert(RENDER_TYPE == 0 || RENDER_TYPE == 1, "RENDER_TYPE is unrecognized.  Stopping compilation.");

    if (!renderer->Initialize()) {
        printf("Graphics Device could not initialize!");
        exit(1);
    }

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
    Game* game = new Game();
    if (!game->Initialize(renderer, input_device)) {
        printf("Game could not Initialize!");
        exit(1);  // this case will leak a lot of memory...
                  // should properly do destructor calls and proper shutdown
    }

    //========================================
    // Load Level
    //========================================
    game->Reset();
    std::string levelConfigFile = "./Assets/Config/level.xml";
    if (!game->LoadLevel(levelConfigFile)) {
        printf("Game could not load level %s: ",
               levelConfigFile.c_str());
        exit(1);  // this case will leak a lot of memory...
                  // should properly do destructor calls and proper shutdown
    }

    // Start the game
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            // Update the Input Device with the Event
            input_device->Update(&event);
        }
        game->Run();
    }

    //========================================
    // Clean-up
    //========================================
    if (game != nullptr) {
        delete game;
        game = nullptr;
    }

    if (input_device != nullptr) {
        delete input_device;
        input_device = nullptr;
    }

    if (renderer != nullptr) {
        delete renderer;
        renderer = nullptr;
    }

    SDL_Quit();

    return 0;
}
