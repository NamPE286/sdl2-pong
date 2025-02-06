#include "Counter.hpp"
#include <string>
#include <iostream>

Counter::Counter(SDL_Renderer* _renderer, TTF_Font* _font, Vec2 _pos) {
	renderer = _renderer;
	font = _font;
	pos = _pos;
	label = new Label(renderer, font, pos, std::to_string(count).c_str());
}

Counter::~Counter() {
	delete label;
}

void Counter::draw() {
	label->draw();
}

void Counter::increase() {
	count++;
	label->~Label();
	label = new Label(renderer, font, pos, std::to_string(count).c_str());
}