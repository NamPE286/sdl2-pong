#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include <SDL2/SDL.h>
#include "../geometry/Vec2.hpp"

class Paddle {
	struct Key {
		Uint32 bind;
		bool is_down = false;
	};

	SDL_Rect rect;
	int window_width, window_height;
	int size, width;
	Key keys[2];
	float velocity = 0.0f;
public:
	Vec2 pos;

	Paddle(Vec2 _pos, int _size, int _width, Uint32 up_bind, Uint32 down_bind, int _window_width, int _window_height);

	void draw(SDL_Renderer* renderer);
	void update(float deltaTIme);
	void input_handler(SDL_Event* event);
	void move_to_center();
};

#endif