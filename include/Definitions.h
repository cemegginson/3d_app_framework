#pragma once

// Unsigned Integers
// typedef unsigned long long int uint64;
typedef unsigned int uint32;
typedef unsigned short int uint16;

// Signed Integers
// typedef long long int sint64;
typedef int int32;
typedef short int int16;

// Floats
typedef float float32;
typedef double float64;

typedef struct Vector2 {
    float32 x;
    float32 y;
} Vector2;

// Event Types
enum GameEvent { kGameNA, kGameUp, kGameDown, kGameLeft, kGameRight, kGameW, kGameA, kGameS, kGameD, kGameSpace };
enum ActorEvent { kMoveLeft, kMoveRight, kMoveUp, kMoveDown, kTurnLeft, kTurnRight };
enum State { kFacingLeft, kFacingRight, kStationary, kJumping, kStopped };

// Constants
const float32 PI = 3.14159f;



// Includes for EventSystem (should restructure to not need these globally.
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <list>

//include chrono before thread because some versions of the standard lib are bugged (erhm... stdlibc++ 4.6)
//libstd++ is fine though
#include <chrono>
#include <thread>

#include "EventSystem/Subscriber.h"

//Some Event ID's
enum Events {
	EVENT_UPDATE,
	EVENT_RENDER,
	EVENT_MOUSEUP,
	EVENT_MOUSEDOWN,
	EVENT_MOUSEMOVE,
	EVENT_MOUSEDRAGED,
	EVENT_KEYDOWN,
	EVENT_KEYUP
};

/**
 * Shorthand method to access cross-platform "sleep" functionality.
 * Will cause compile error without explicit inline or if inline is not respected.
*/
inline void sleep(int time_millis) {
	std::this_thread::sleep_for(std::chrono::milliseconds(time_millis));
}
