#include <iostream>
#include "SDL2/SDL.h"
#include "utils/Vec2.hpp"
#include "utils/WindowUtils.hpp"

constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;

void draw_net(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int cur = 0;

	for (int y = 0; y < WINDOW_HEIGHT; y++) {
		if (cur < 10) {
			SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
		}

		if (cur == 15) {
			cur = 0;
		}
		else {
			cur++;
		}
	}
}

int SDL_main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	bool running = true;

	Window::center(window, WINDOW_WIDTH, WINDOW_HEIGHT);

	while (running) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);

		draw_net(renderer);

		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}