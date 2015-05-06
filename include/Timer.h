#pragma once

#include "SDL.h"
#include "Definitions.h"

class Timer {
private:
	// The clock time when the timer started
	uint32 start_ticks_;

	// Time Delta!
	uint32 delta_time_;
	uint32 last_time_;

	// The ticks stored when the timer was paused
	uint32 paused_ticks_;

	// The timer status
	bool paused_;
	bool active_;

public:
	// Initializes variables
	Timer();

	// The various clock actions
	void Start();
	void Stop();
	void Pause();
	void Resume();

	// Gets the timer's time
	uint32 GetTicks();

	// Checks the status of the timer
	bool IsRunning();
	bool IsPaused();

	// Time Delta!
	void Update();
	float32 DeltaTime();
};
