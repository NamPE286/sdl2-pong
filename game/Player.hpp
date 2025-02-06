#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../entities/Paddle.hpp"
#include "../elements/Counter.hpp"

class Player {
	SDL_Renderer* renderer;
	int window_width, window_height;
public:
	Paddle* paddle;
	Counter* score;

	Player(SDL_Renderer* _renderer, TTF_Font* font, bool pIndex, int _window_width, int _window_height);
	~Player();
	void draw();
	void reset();
};

#endif