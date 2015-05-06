#pragma once

#include <map>
#include <memory>
#include <vector>

#include "SDL.h"

#include "Component.h"
#include "Definitions.h"
#include "InputDevice.h"
#include "View.h"

class Component;
class GraphicsDevice;

class Actor : public std::enable_shared_from_this<Actor> {
protected:
	std::string name_;
    Vector2 position_;
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

    Vector2 GetPosition();
    void SetPosition(Vector2);

    float32 GetAngle();
    void SetAngle(float32);

	SDL_Rect GetSpriteClip();
	void SetSpriteClip(SDL_Rect);

	void SetEvent(ActorEvent);
	bool CheckEvent(ActorEvent);
	void ResetEvents();

	bool IsControllable();
};
