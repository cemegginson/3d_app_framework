/*
* Author:    Keith Bush
*            UALR
*
* Date:        February 23, 2015
*
* File:        Source.cpp
*
* Purpose:    This programming task examines the following concepts
*                - Abstraction of game devices (Graphics, Input)
*from SDL Library
*               - AssetManagement using Libraries
*               - Component Factory Design Pattern
*               - XML Construction of 2-D game system
*               - Main Game Loop
*/

// C++ Libraries
#include <ctime>
#include <iostream>
#include <string>

// Media Libraries
#include "SDL.h"

// Physics
#include "Box2D/Box2D.h"

// Project Libraries
#include "Definitions.h"
#include "Game.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"

int main(int argc, char* argv[]) {
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
    GraphicsDevice* graphics_device =
        new GraphicsDevice(screen_width, screen_height);
    // if (!gDevice->Initialize(true)) { Not sure what this true is about
    if (!graphics_device->Initialize()) {
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
    if (!game->Initialize(graphics_device, input_device)) {
        printf("Game could not Initialize!");
        exit(1); //this case will leak a lot of memory...
                 //should properly do destructor calls and proper shutdown
    }

    //========================================
    // Load Level
    //========================================
    game->Reset();
    std::string levelConfigFile = "./Assets/Config/level.xml";
    if (!game->LoadLevel(levelConfigFile)) {
        printf("Game could not load level %s: ",
               levelConfigFile.c_str());
        exit(1); //this case will leak a lot of memory...
                 //should properly do destructor calls and proper shutdown
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

    if (graphics_device != nullptr) {
        delete graphics_device;
        graphics_device = nullptr;
    }

    SDL_Quit();

    return 0;
}
