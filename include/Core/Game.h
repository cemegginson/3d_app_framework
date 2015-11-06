#pragma once

#include <list>
#include <string>

#include "Box2D/Box2D.h"

#include "Library/ComponentLibrary.h"
#include "Library/ArtAssetLibrary.h"

#include "Core/Timer.h"
#include "Core/View.h"

#include "Virtual/Component.h"

class Game {
protected:
    ComponentLibrary* component_factories_;
    ArtAssetLibrary* art_library_;
    GraphicsDevice* graphics_device_;
    InputDevice* input_device_;
    Timer* timer_;
    View* view_;
    std::list<Actor*> actors_;
    b2World* world_;
    // float32 physics_delta_time_;
    int32 velocity_iterations_;
    int32 position_iterations_;
    // int32 particle_iterations_;

public:
    Game();
    ~Game();
    bool Initialize(GraphicsDevice*, InputDevice*);
    void Reset();
    bool LoadLevel(std::string);
    void Run();
    void Update(float32);

    // cmake adds NDEBUG by default for debug builds
    #ifdef NDEBUG
    Subscriber* debugSubscriber;
    void printFrameRate();
    #endif

};
