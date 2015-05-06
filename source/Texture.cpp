#include <iostream>
#include <SDL_image.h>
#include "Texture.h"
//#include "GameUtils.h"

Texture::Texture() { texture_ = nullptr; }

Texture::~Texture() { SDL_DestroyTexture(texture_); }

bool Texture::Initialize(SDL_Renderer* renderer, View* view, std::string image_path) {
	renderer_ = renderer;
	view_ = view;

	// Load image
	SDL_Surface* surface = nullptr;
	surface = IMG_Load(image_path.c_str());
	if(surface == NULL) {
		std::cerr << "Surface failed: " << IMG_GetError() << std::endl;
		return false;
	}

	// Create texture
	texture_ = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture_ == NULL) {
		//LogSDLError(std::cerr, "LoadTexture");
		std::cerr << "Texture failed: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

// void Texture::Render(Vector2 position, float32 angle, SDL_Rect* clip) {
void Texture::Render(Vector2 position, float32 angle) {
	Vector2 view_position = view_->GetPosition();

	SDL_Rect dst;
	dst.x = position.x + view_position.x;
	dst.y = position.y + view_position.y;

	SDL_QueryTexture(texture_, NULL, NULL, &dst.w, &dst.h);

	SDL_RenderCopyEx(renderer_, texture_, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
}

void Texture::GetDimensions(sint32* w, sint32* h) {
	SDL_QueryTexture(texture_, NULL, NULL, w, h);
	return;
}
