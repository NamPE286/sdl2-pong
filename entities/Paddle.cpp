#include "Paddle.hpp"

Paddle::Paddle(Vec2 _pos, const int _size, const int _width, const int _window_width, const int _window_height) {
	pos = _pos;
	size = _size;
	width = _width;
	window_width = _window_width;
	window_height = _window_height;
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
}

void Paddle::move_to_center() {
	pos.y = (window_height - size) / 2.0f;
}