#include "Game.hpp"
#include "../common.hpp"
#include "../utils/RendererUtils.hpp"

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
	ball.move_to_center();

	for (Player* i : players) {
		i->reset();
	}
}