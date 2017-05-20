#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "global.h"

class Entity {

public:
	Entity();
	Entity(double x, double y);
	void render(SDL_Texture * image, SDL_Renderer *renderer);
	double GetX();
	double GetY();
	int GetWidth();
	int GetHeight();

protected:
	double x, y;
	int w, h;
	SDL_Rect texture_rect;
	SDL_Rect rect;

	//Methods
	virtual void Move() = 0;

};
