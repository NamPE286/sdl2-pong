#include "WindowUtils.hpp"
#include "../common.hpp"

void WindowUtils::center(SDL_Window* window) {
	SDL_DisplayMode DM;

	SDL_GetCurrentDisplayMode(0, &DM);
	SDL_SetWindowPosition(window, (DM.w - WINDOW_WIDTH) / 2, (DM.h - WINDOW_HEIGHT) / 2);
}