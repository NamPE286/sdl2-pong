#include "Player.hpp"
#include "../geometry/Vec2.hpp"

Player::Player(SDL_Renderer* _renderer, TTF_Font* font, bool pIndex, int _window_width, int _window_height) {
	renderer = _renderer;
	window_width = _window_width;
	window_height = _window_height;

	if (pIndex == 0) {
		paddle = new Paddle(Vec2(10, 0), 100, 10, window_width, window_height);
		score = new Counter(renderer, font, Vec2(window_width / 4.0f, 10));

	}
	else {
		paddle = new Paddle(Vec2(window_width - 10, 0), 100, 10, window_width, window_height);
		score = new Counter(renderer, font, Vec2(window_width * 3 / 4.0f, 10));
	}
}

Player::~Player() {
	delete paddle;
	delete score;
}

void Player::draw() {
	paddle->draw(renderer);
	score->draw();
}

void Player::update(float deltaTime) {
	paddle->update(deltaTime);
}

void Player::reset() {
	paddle->move_to_center();
}