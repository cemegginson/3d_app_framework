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
