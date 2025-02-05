#include "Paddle.hpp"

Paddle::Paddle(Vec2 _pos, const int _size, const int _width) {
	Paddle::pos = _pos;
	Paddle::size = _size;
	Paddle::width = _width;
	Paddle::rect.x = static_cast<int>(_pos.x);
	Paddle::rect.y = static_cast<int>(_pos.y);
	Paddle::rect.w = _width;
	Paddle::rect.h = _size;
}

void Paddle::draw(SDL_Renderer* renderer) {
	Paddle::rect.x = static_cast<int>(Paddle::pos.x);
	Paddle::rect.y = static_cast<int>(Paddle::pos.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &(Paddle::rect));
}

void Paddle::move_to_center(const int window_width, const int window_height) {
	Paddle::pos.y = (window_height - Paddle::size) / 2.0f;
}