#pragma once

#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "Definitions.h"
#include "View.h"

class Texture {
protected:
	SDL_Texture* texture_;
	SDL_Renderer* renderer_;
	View* view_;

public:
	Texture();
	~Texture();
	bool Initialize(SDL_Renderer*, View*, std::string);
	// void Render(Vector2, float32, SDL_Rect*);
	void Render(Vector2, float32);
	void GetDimensions(sint32*, sint32*);
};
