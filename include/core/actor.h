#pragma once

#include <map>
#include <memory>
#include <vector>
#include <string>

#include "SDL.h"

#include "virtual/component.h"
#include "util/definitions.h"
#include "core/InputDevice.h"
#include "render/sdl/sdl_view.h"

class Component;
class GraphicsDevice;

class Actor : public std::enable_shared_from_this<Actor> {
protected:
    std::string name_;
    Vector2 transform_;
    Vector2 dimensions_;
    float32 angle_;
    std::vector<Component*> components_;
    std::map<ActorEvent, bool> actor_events_;
    bool controllable_;

    // For sprite clipping
    SDL_Rect sprite_clip_;

public:
    Actor();
    ~Actor();
    void Initialize(std::string, Vector2, uint32, bool);
    void AddComponent(Component*);

    void Update(float32);

    void SetEvent(ActorEvent, bool value = true);
    bool CheckEvent(ActorEvent);
    void ResetEvents();

    bool IsControllable();

    Vector2 transform();
    void set_transform(Vector2);

    float32 angle();
    void set_angle(float32);

    SDL_Rect sprite_clip();
    void set_sprite_clip(SDL_Rect);
};
