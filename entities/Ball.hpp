#include "SDL2/SDL.h"
#include "../geometry/Vec2.hpp"


class Ball {
	SDL_Rect rect;
	Vec2 pos;

	Ball(Vec2 _pos, int size);

	void draw(SDL_Renderer* renderer);
};