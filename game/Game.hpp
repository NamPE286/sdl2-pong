#ifndef GAME_HEADER
#define GAME_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "../entities/Ball.hpp"
#include "Player.hpp"

class Game {
	SDL_Renderer* renderer;
	TTF_Font* font;
	Ball ball = Ball(Vec2(), 10);
	std::vector<Player*> players;
	int window_width, window_height;
public:
	Game(SDL_Renderer* _renderer, TTF_Font* _font, int _window_width, int _window_height);
	~Game();
	void draw();
	void reset();
};

#endif