#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../entities/Paddle.hpp"
#include "../elements/Counter.hpp"

class Player {
	SDL_Renderer* renderer;
public:
	Paddle* paddle;
	Counter* score;

	Player(SDL_Renderer* _renderer, TTF_Font* font, bool pIndex);
	~Player();
	void draw();
	void update(float deltaTime);
	void input_handler(SDL_Event* event);
	void reset();
};

#endif