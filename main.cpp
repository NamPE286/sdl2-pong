#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "geometry/Vec2.hpp"
#include "utils/WindowUtils.hpp"
#include "utils/RendererUtils.hpp"
#include "entities/Ball.hpp"
#include "entities/Paddle.hpp"
#include "elements/Counter.hpp"
#include "game/Player.hpp"
#include "game/Game.hpp"

constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;

int SDL_main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	TTF_Font* font = TTF_OpenFont("assets/DejaVuSansMono.ttf", 40);
	Game game(renderer, font, WINDOW_WIDTH, WINDOW_HEIGHT);
	bool running = true;

	WindowUtils::center(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.reset();

	while (running) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);

		game.draw();

		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

	return 0;
}