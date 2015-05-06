#include <iostream>
#include "GraphicsDevice.h"
#include "GameUtils.h"

GraphicsDevice::GraphicsDevice() {
	window_ = nullptr;
	renderer_ = nullptr;
	width_ = 0;
	height_ = 0;
}

GraphicsDevice::GraphicsDevice(uint32 screen_width, uint32 screen_height) {
	window_ = nullptr;
	renderer_ = nullptr;
	width_ = screen_width;
	height_ = screen_height;
}

GraphicsDevice::~GraphicsDevice() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}

bool GraphicsDevice::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		LogSDLError(std::cerr, "SDL_Init");
		return false;
	}

	window_ = SDL_CreateWindow("Game Homework 1", SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED, width_, height_,
				SDL_WINDOW_RESIZABLE);
	if (window_ == nullptr) {
		LogSDLError(std::cerr, "SDL_CreateWindow");
		return false;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer_ == nullptr) {
		LogSDLError(std::cerr, "SDL_CreateRenderer");
		return false;
	}

	SDL_SetRenderDrawColor(renderer_, 0, 100, 0, 0);

	return true;
}

int GraphicsDevice::GetWidth() { return width_; }

int GraphicsDevice::GetHeight() { return height_; }

SDL_Renderer* GraphicsDevice::GetRenderer() {
	return renderer_;
}

void GraphicsDevice::AddSprite(Sprite* sprite) {
	sprites_.push_back(sprite);
}

void GraphicsDevice::Render() {
	SDL_RenderClear(renderer_);

	// Cycle through every objects' Draw method
	for (auto iter = sprites_.begin(); iter != sprites_.end(); ++iter) {
		(*iter)->Render();
	}

	SDL_RenderPresent(renderer_);
}
