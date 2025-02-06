#ifndef BALL_HEADER
#define BALL_HEADER

#include <SDL2/SDL.h>
#include "Paddle.hpp"
#include "../geometry/Vec2.hpp"

class Ball {
	SDL_Rect rect;
public:
	Vec2 pos;
	Vec2 velocity = Vec2(0, 0);
	int size;

	Ball(Vec2 _pos, int _size);

	void draw(SDL_Renderer* renderer);
	void update(float deltaTime);
	int getCollideState(Paddle& left, Paddle& right);
	void changeDirection(Paddle& paddle, float speed);
	void reset();
};

#endif