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
	float speed = 0.3f;
public:
	Game(SDL_Renderer* _renderer, TTF_Font* _font);
	~Game();
	void draw();
	void update(float deltaTime);
	void input_handler(SDL_Event* event);
	void reset();
};

#endif