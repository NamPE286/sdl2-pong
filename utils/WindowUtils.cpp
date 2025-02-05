#include "WindowUtils.hpp"

void WindowUtils::center(SDL_Window* window, const int window_width, const int window_height) {
	SDL_DisplayMode DM;

	SDL_GetCurrentDisplayMode(0, &DM);
	SDL_SetWindowPosition(window, (DM.w - window_width) / 2, (DM.h - window_height) / 2);
}