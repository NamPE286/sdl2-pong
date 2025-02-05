#ifndef COUNTER_HEADER
#define COUNTER_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../geometry/Vec2.hpp"

class Counter {
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect* rect;
	TTF_Font* font;
public:
	int count = 0;

	Counter(Vec2 _pos, SDL_Renderer* renderer, TTF_Font* font);
	void draw();
	void operator++();
	void operator--();
};

#endif