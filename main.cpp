#include <iostream>
#include "SDL2/SDL.h"

constexpr auto WIDTH = 640;
constexpr auto HEIGHT = 480;
constexpr auto FONT_SIZE = 32;

struct procStat {
	int frameCount, timerFPS, lastFrame, fps;
};

int SDL_main(int argc, char* argv[]) {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Failed to init SDL" << std::endl;
	}

	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
		std::cout << "Failed to create window and renderer" << std::endl;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, 640 / 2, 480 / 2);

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);

	return 0;
}