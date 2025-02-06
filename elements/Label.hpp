#ifndef LABEL_HEADER
#define LABEL_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "../geometry/Vec2.hpp"

class Label {
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
	TTF_Font* font;
	SDL_Rect rect;
public:
	std::string value;
	Vec2 pos;

	Label(SDL_Renderer* _renderer, TTF_Font* _font, Vec2 _pos, const std::string& _value);
	~Label();
	void draw();
};

#endif