#include "Ball.hpp"
#include "../common.hpp"
#include <math.h>

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

void Ball::update(float deltaTime) {
	pos += velocity * deltaTime;

	if (pos.y < 0) {
		velocity.y = fabs(velocity.y);
	}
	else if (pos.y + size > WINDOW_HEIGHT) {
		velocity.y = -fabs(velocity.y);
	}
}

int Ball::getCollideState(Paddle& left, Paddle& right) {
	if (pos.x < WINDOW_WIDTH / 2.0f) {
		if (pos.x < 0) {
			return -1;
		}

		if (pos.x > left.pos.x + left.width || pos.x < left.pos.x) {
			return 0;
		}

		if (left.pos.y <= pos.y + size && pos.y <= left.pos.y + left.size) {
			return 1;
		}
	}
	else {
		if (pos.x + size > WINDOW_WIDTH) {
			return -2;
		}

		if (pos.x + size < right.pos.x || pos.x + size > right.pos.x + right.width) {
			return 0;
		}

		if (right.pos.y <= pos.y + size && pos.y <= right.pos.y + right.size) {
			return 2;
		}
	}
}

void Ball::changeDirection(Paddle& paddle, float speed) {
	float degAngle = (pos.y + size / 2.0f) - (paddle.pos.y + paddle.size / 2.0f);
	degAngle *= 1.2;

	degAngle = __min(degAngle, 50.0f);
	degAngle = __max(degAngle, -50.0f);

	velocity.x = speed * (velocity.x < 0 ? 1 : -1);
	velocity.y = tan(degAngle * 3.14f / 180.0f) * fabs(velocity.x);
}

void Ball::reset() {
	pos.x = (WINDOW_WIDTH - size) / 2.0f;
	pos.y = (WINDOW_HEIGHT - size) / 2.0f;
}