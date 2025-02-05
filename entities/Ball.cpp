#include "Ball.hpp"

Ball::Ball(Vec2 _pos, int size) {
	Ball::pos = _pos;
	Ball::rect.x = static_cast<int>(_pos.x);
	Ball::rect.y = static_cast<int>(_pos.y);
	Ball::rect.w = Ball::rect.h = size;
}

void Ball::draw(SDL_Renderer* renderer) {
	Ball::rect.x = static_cast<int>(Ball::pos.x);
	Ball::rect.y = static_cast<int>(Ball::pos.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &(Ball::rect));
}