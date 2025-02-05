#include <iostream>
#include "SDL2/SDL.h"
#include "geometry/Vec2.hpp"
#include "utils/WindowUtils.hpp"
#include "utils/RendererUtils.hpp"
#include "entities/Ball.hpp"

constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;

int SDL_main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	bool running = true;

	Ball ball(Vec2(50, 50), 10);

	WindowUtils::center(window, WINDOW_WIDTH, WINDOW_HEIGHT);

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

		RendererUtils::draw_net(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
		ball.draw(renderer);

		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}