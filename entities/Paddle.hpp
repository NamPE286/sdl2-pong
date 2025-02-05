#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include "SDL2/SDL.h"
#include "../geometry/Vec2.hpp"

class Paddle {
	SDL_Rect rect;
	int size;
	int width;
public:
	Vec2 pos;

	Paddle(Vec2 _pos, const int _size, const int _width);

	void draw(SDL_Renderer* renderer);
	void move_to_center(const int window_width, const int window_height);
};

#endif