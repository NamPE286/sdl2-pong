#include "Game.hpp"
#include "../common.hpp"
#include "../utils/RendererUtils.hpp"
#include "../entities/Paddle.hpp"
#include <iostream>
#include <math.h>

static int collideState(Ball& ball, Paddle& paddle, bool left) {
	if (left) {
		if (ball.pos.x < 0) {
			return 1;
		}

		if (ball.pos.x > paddle.pos.x + paddle.width || ball.pos.x < paddle.pos.x) {
			return 0;
		}
	}

	if (!left) {
		if (ball.pos.x + ball.size > WINDOW_WIDTH) {
			return 1;
		}

		if (ball.pos.x + ball.size < paddle.pos.x || ball.pos.x + ball.size > paddle.pos.x + paddle.width) {
			return 0;
		}
	}

	if (paddle.pos.y <= ball.pos.y + ball.size && ball.pos.y <= paddle.pos.y + paddle.size) {
		return 2;
	}
}

static void changeBallDirection(Ball& ball, Paddle& paddle, float speed) {
	float degAngle = (ball.pos.y + ball.size / 2.0f) - (paddle.pos.y + paddle.size / 2.0f);
	degAngle *= 1.2;

	degAngle = __min(degAngle, 55.0f);
	degAngle = __max(degAngle, -55.0f);

	ball.velocity.x = speed * (ball.velocity.x < 0 ? 1 : -1);
	ball.velocity.y = tan(degAngle * 3.14f / 180.0f) * abs(ball.velocity.x);
}

Game::Game(SDL_Renderer* _renderer, TTF_Font* _font) {
	renderer = _renderer;
	font = _font;
	players = { new Player(renderer, font, 0), new Player(renderer, font, 1) };
}

Game::~Game() {
	for (Player* i : players) {
		delete i;
	}
}

void Game::draw() {
	RendererUtils::draw_net(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
	ball.draw(renderer);

	for (Player* i : players) {
		i->draw();
	}
	if (collideState(ball, *players[0]->paddle, true) == 1) {
		std::cout << "Out of left bound" << '\n';
		players[1]->score->increase();
		reset();
		ball.velocity.x *= -1;
	}
	else if (collideState(ball, *players[1]->paddle, false) == 1) {
		std::cout << "Out of right bound" << '\n';
		players[0]->score->increase();
		reset();
	}
	else if (collideState(ball, *players[0]->paddle, true) == 2) {
		speed += 0.05f;
		changeBallDirection(ball, *players[0]->paddle, speed);
	}
	else if (collideState(ball, *players[1]->paddle, false) == 2) {
		speed += 0.05f;
		changeBallDirection(ball, *players[1]->paddle, speed);
	}
}

void Game::update(float deltaTime) {
	ball.update(deltaTime);

	for (Player* i : players) {
		i->update(deltaTime);
	}
}

void Game::input_handler(SDL_Event* event) {
	for (Player* i : players) {
		i->input_handler(event);
	}
}

void Game::reset() {
	ball.reset();
	speed = 0.35f;
	ball.velocity = Vec2(speed, 0);

	for (Player* i : players) {
		i->reset();
	}
}