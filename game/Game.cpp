#include "Game.hpp"
#include "../common.hpp"
#include "../utils/RendererUtils.hpp"
#include "../entities/Paddle.hpp"
#include <iostream>
#include <math.h>

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
}

void Game::update(float deltaTime) {
	ball.update(deltaTime);

	for (Player* i : players) {
		i->update(deltaTime);
	}

	int colState = ball.getCollideState(*players[0]->paddle, *players[1]->paddle);

	if (colState == -1) {
		std::cout << "Out of left bound" << '\n';
		players[1]->score->increase();
		reset();
		ball.velocity.x *= -1;
	}
	else if (colState == -2) {
		std::cout << "Out of right bound" << '\n';
		players[0]->score->increase();
		reset();
	}
	else if (colState == 1) {
		speed += 0.05f;
		ball.changeDirection(*players[0]->paddle, speed);
	}
	else if (colState == 2) {
		speed += 0.05f;
		ball.changeDirection(*players[1]->paddle, speed);
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