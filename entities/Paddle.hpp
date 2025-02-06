#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include <SDL2/SDL.h>
#include "../geometry/Vec2.hpp"

class Paddle {
	struct Key {
		Uint32 bind = 0x0;
		bool is_down = false;
	};

	SDL_Rect rect;
	Key keys[3];
	float velocity = 0.0f;
public:
	int size, width;
	Vec2 pos;

	Paddle(Vec2 _pos, int _size, int _width, Uint32 up_bind, Uint32 down_bind, Uint32 slow_bind);

	void draw(SDL_Renderer* renderer);
	void update(float deltaTIme);
	void input_handler(SDL_Event* event);
	void move_to_center();
};

#endif