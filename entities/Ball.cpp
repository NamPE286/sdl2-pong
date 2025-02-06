#include "Ball.hpp"
#include "../common.hpp"

Ball::Ball(Vec2 _pos, int _size) {
	pos = _pos;
	size = _size;
	rect.x = static_cast<int>(_pos.x);
	rect.y = static_cast<int>(_pos.y);
	rect.w = rect.h = _size;
}

void Ball:: draw(SDL_Renderer* renderer) {
	rect.x = static_cast<int>(pos.x);
	rect.y = static_cast<int>(pos.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &(rect));
}

void Ball::reset() {
	pos.x = (WINDOW_WIDTH - size) / 2.0f;
	pos.y = (WINDOW_HEIGHT - size) / 2.0f;
}