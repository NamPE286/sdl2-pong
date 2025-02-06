#include "Game.hpp"
#include "../utils/RendererUtils.hpp"

Game::Game(SDL_Renderer* _renderer, TTF_Font* _font, int _window_width, int _window_height) {
	renderer = _renderer;
	font = _font;
	window_width = _window_width;
	window_height = _window_height;
	players = { new Player(renderer, font, 0, window_width, window_height), new Player(renderer, font, 1, window_width, window_height) };
}

Game::~Game() {
	for (Player* i : players) {
		delete i;
	}
}

void Game::draw() {
	RendererUtils::draw_net(renderer, window_width, window_height);
	ball.draw(renderer);

	for (Player* i : players) {
		i->draw();
	}
}

void Game::reset() {
	ball.move_to_center(window_width, window_height);

	for (Player* i : players) {
		i->reset();
	}
}