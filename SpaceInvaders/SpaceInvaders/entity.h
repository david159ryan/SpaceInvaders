#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Entity {

public:
	Entity();
	Entity(int x, int y);
	void render(const int WIDTH, const int HEIGHT);

protected:
	int x, y;
	//virtual void move() = 0;
};
