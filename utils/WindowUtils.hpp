#ifndef WINDOWUTILS_HEADER
#define WINDOWUTILS_HEADER

#include "SDL2/SDL.h"

namespace WindowUtils {
	void center(SDL_Window* window, const int window_width, const int window_height);
}

#endif