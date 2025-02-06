#ifndef COUNTER_HEADER
#define COUNTER_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../geometry/Vec2.hpp"
#include "Label.hpp"

class Counter {
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;
	Label* label = nullptr;
	Vec2 pos;
public:
	int count = 0;

	Counter(SDL_Renderer* _renderer, TTF_Font* _font, Vec2 _pos);
	~Counter();
	void draw();
	void increase();
};

#endif