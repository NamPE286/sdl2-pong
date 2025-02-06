#ifndef BALL_HEADER
#define BALL_HEADER

#include <SDL2/SDL.h>
#include "../geometry/Vec2.hpp"

class Ball {
	SDL_Rect rect;
	int size;
public:
	Vec2 pos;

	Ball(Vec2 _pos, int _size);

	void draw(SDL_Renderer* renderer);
	void move_to_center();
};

#endif