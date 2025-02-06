#include "Counter.hpp"

Counter::Counter(SDL_Renderer* _renderer, TTF_Font* _font, Vec2 pos) {
	renderer = _renderer;
	font = _font;
	label = new Label(renderer, font, pos, "0");
}

Counter::~Counter() {
	delete label;
}

void Counter::draw() {
	label->draw();
}

void Counter::operator++() {

}

void Counter::operator--() {

}
