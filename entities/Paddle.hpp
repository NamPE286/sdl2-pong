#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include <SDL2/SDL.h>
#include "../geometry/Vec2.hpp"

class Paddle {
	SDL_Rect rect;
	int window_width, window_height;
	int size, width;
	float velocity = 0.0f;
public:
	Vec2 pos;

	Paddle(Vec2 _pos, const int _size, const int _width, const int _window_width, const int _window_height);

	void draw(SDL_Renderer* renderer);
	void update(float deltaTIme);
	void move_to_center();
};

#endif