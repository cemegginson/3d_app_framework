/*
* Author:	Keith Bush
*			UALR
*
* Date:		February 24, 2015 (Completed)
*
* File:		Definitions.h (Hmwk.1.Solution)
*
* Purpose:	This is a standard type redefinitions header that allows
*           for flexibility in programming should design parameters change.
*           Ideally, every SDL2 specific type would be renamed allowing
*           the code to be decoupled from any specific Media Library.
*/

#pragma once

// Unsigned Integers
// typedef unsigned long long int uint64;
typedef unsigned int uint32;
typedef unsigned short int uint16;

// Signed Integers
// typedef long long int sint64;
typedef int sint32;
typedef short int sint16;

// Floats
typedef float float32;
typedef double float64;

typedef struct Vector2 {
	float32 x;
	float32 y;
} Vector2;

// Event Types
enum GameEvent { GAME_NA, GAME_UP, GAME_DOWN, GAME_LEFT, GAME_RIGHT, GAME_W, GAME_A, GAME_S, GAME_D, GAME_SPACE };
enum ActorEvent { MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN, TURN_LEFT, TURN_RIGHT };

// Constants
const float32 PI = 3.14159f;
