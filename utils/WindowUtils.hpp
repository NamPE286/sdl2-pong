#ifndef WINDOWUTILS_HEADER
#define WINDOWUTILS_HEADER

#include <SDL2/SDL.h>

namespace WindowUtils {
	void center(SDL_Window* window, int window_width, int window_height);
}

#endif