#include <iostream>

#include "Timer.h"
#include "Definitions.h"

Timer::Timer() {
	// Initialize the variables
	start_ticks_ = 0;
	paused_ticks_ = 0;
	paused_ = false;
	active_ = false;
	delta_time_ = 0;
	last_time_ = 0;
}

void Timer::Start() {
	// Start the timer
	active_ = true;
	paused_ = false;

	// Get the current clock time
	start_ticks_ = SDL_GetTicks();
}

void Timer::Stop() {
	// Stop the timer
	active_ = false;

	// Unpause the timer
	paused_ = false;
}

void Timer::Pause() {
	// If the timer is running and isn't already paused_
	if ((active_ == true) && (paused_ == false)) {
		// Pause the timer
		paused_ = true;

		// Calculate the paused_ ticks
		paused_ticks_ = SDL_GetTicks();
	}
}

void Timer::Resume() {
	// If the timer is paused_
	if (paused_ == true) {
		// Unpause the timer
		paused_ = false;

		// Reset the starting ticks
		start_ticks_ = SDL_GetTicks() - paused_ticks_;

		// Reset the paused_ ticks
		paused_ticks_ = 0;
	}
}

uint32 Timer::GetTicks() {
	// If the timer is running
	if (active_ == true) {
		// If the timer is paused_
		if (paused_ == true) {
			// Return the number of ticks when the timer was paused_
			return paused_ticks_;
		} else {
			// Return the current time minus the start time
			return SDL_GetTicks();
		}
	}

	// If the timer isn't running
	return 0;
}

bool Timer::IsRunning() { return active_; }

bool Timer::IsPaused() { return paused_; }

void Timer::Update() {
	delta_time_ = SDL_GetTicks() - last_time_;
	last_time_ = SDL_GetTicks();
}

float32 Timer::DeltaTime() {
	return (float32)delta_time_/1000.0;
}
