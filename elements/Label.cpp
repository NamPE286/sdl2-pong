#include "Label.hpp"

Label::Label(SDL_Renderer* _renderer, TTF_Font* _font, Vec2 pos, const std::string _value) {
	renderer = _renderer;
	value = _value;
	font = _font;

	surface = TTF_RenderText_Solid(font, value.c_str(), { 0xFF, 0xFF, 0xFF, 0xFF });
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	int w, h;
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

	rect.x = static_cast<int>(pos.x) - w / 2;
	rect.y = static_cast<int>(pos.y);
	rect.w = w;
	rect.h = h;
}

Label::~Label() {
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Label::draw() {
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}