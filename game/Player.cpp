#include "Player.hpp"
#include "../common.hpp"
#include "../geometry/Vec2.hpp"

Player::Player(SDL_Renderer* _renderer, TTF_Font* font, bool pIndex) {
	renderer = _renderer;

	if (pIndex == 0) {
		paddle = new Paddle(Vec2(10, 0), 100, 10, SDLK_w, SDLK_s);
		score = new Counter(renderer, font, Vec2(WINDOW_WIDTH / 4.0f, 10));

	}
	else {
		paddle = new Paddle(Vec2(WINDOW_WIDTH - 20, 0), 100, 10, SDLK_UP, SDLK_DOWN);
		score = new Counter(renderer, font, Vec2(WINDOW_WIDTH * 3 / 4.0f, 10));
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

void Player::input_handler(SDL_Event* event) {
	paddle->input_handler(event);
}

void Player::reset() {
	paddle->move_to_center();
}