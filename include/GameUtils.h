#pragma once

#include <iostream>
#include <string>

#include "SDL.h"

void LogSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}
