#include "Paddle.hpp"
#include <iostream>
#include "../common.hpp"

const float SPEED = 0.7f;

Paddle::Paddle(Vec2 _pos, int _size, int _width, Uint32 up_bind, Uint32 down_bind) {
	pos = _pos;
	size = _size;
	width = _width;
	keys[0].bind = up_bind;
	keys[1].bind = down_bind;
	rect.x = static_cast<int>(_pos.x);
	rect.y = static_cast<int>(_pos.y);
	rect.w = _width;
	rect.h = _size;
}

void Paddle::draw(SDL_Renderer* renderer) {
	rect.x = static_cast<int>(Paddle::pos.x);
	rect.y = static_cast<int>(Paddle::pos.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &rect);
}

void Paddle::update(float deltaTIme) {
	pos.y += velocity * deltaTIme;

	if (pos.y < 0) {
		pos.y = 0;
	}
	else if (pos.y > WINDOW_HEIGHT - size) {
		pos.y = WINDOW_HEIGHT - size;
	}
}

void Paddle::input_handler(SDL_Event* event) {
	if (event->type == SDL_KEYDOWN) {
		if (event->key.keysym.sym == keys[0].bind) {
			velocity = -SPEED;
			keys[0].is_down = true;
		}
		else if (event->key.keysym.sym == keys[1].bind) {
			velocity = SPEED;
			keys[1].is_down = true;
		}
	}
	else if (event->type == SDL_KEYUP) {
		if (event->key.keysym.sym == keys[0].bind) {
			keys[0].is_down = false;
		}
		else if (event->key.keysym.sym == keys[1].bind) {
			keys[1].is_down = false;
		}

		if (!keys[0].is_down && !keys[1].is_down) {
			velocity = 0;
		}
		else if (keys[0].is_down && !keys[1].is_down) {
			velocity = -SPEED;
		}
		else if (!keys[0].is_down && keys[1].is_down) {
			velocity = SPEED;
		}
	}
}

void Paddle::move_to_center() {
	pos.y = (WINDOW_HEIGHT - size) / 2.0f;
}