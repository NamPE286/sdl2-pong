#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "common.hpp"
#include "geometry/Vec2.hpp"
#include "utils/WindowUtils.hpp"
#include "utils/RendererUtils.hpp"
#include "entities/Ball.hpp"
#include "entities/Paddle.hpp"
#include "elements/Counter.hpp"
#include "game/Player.hpp"
#include "game/Game.hpp"
#include "utils/LogUtils.hpp"

#ifdef _WIN32
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // _WIN32

#ifdef linux
#pragma comment(linker, "-mwindows")
#endif


int SDL_main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	TTF_Font* font = TTF_OpenFont("assets/DejaVuSansMono.ttf", 40);
	Status stat;
	Game game(renderer, font);

	WindowUtils::center(window);
	game.reset();
	auto tLog = LogUtils::statusThread(&stat);

	while (stat.running) {
		SDL_Event event;
		auto frameStartTime = std::chrono::high_resolution_clock::now();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				stat.running = false;
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				stat.running = false;
			}

			game.input_handler(&event);
		}

		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);

		game.update(stat.deltaTime);
		game.draw();

		SDL_RenderPresent(renderer);

		auto frameStopTime = std::chrono::high_resolution_clock::now();
		stat.deltaTime = std::chrono::duration<float, std::chrono::milliseconds::period>(frameStopTime - frameStartTime).count();
	}

	tLog.join();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

	return 0;
}