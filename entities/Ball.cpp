#include "Ball.hpp"

Ball::Ball(Vec2 _pos, const int _size) {
	Ball::pos = _pos;
	Ball::size = _size;
	Ball::rect.x = static_cast<int>(_pos.x);
	Ball::rect.y = static_cast<int>(_pos.y);
	Ball::rect.w = Ball::rect.h = _size;
}

void Ball::draw(SDL_Renderer* renderer) {
	Ball::rect.x = static_cast<int>(Ball::pos.x);
	Ball::rect.y = static_cast<int>(Ball::pos.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &(Ball::rect));
}

void Ball::move_to_center(const int window_width, const int window_height) {
	Ball::pos.x = (window_width - Ball::size) / 2.0f;
	Ball::pos.y = (window_height - Ball::size) / 2.0f;
}