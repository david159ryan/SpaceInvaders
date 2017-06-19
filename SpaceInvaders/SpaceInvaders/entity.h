#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "global.h"

#define PLAYER		0
#define ENEMY1		1
#define ENEMY2		2
#define ENEMY3		3

#define S_X			0
#define S_Y			1
#define S_WIDTH		2
#define S_HEIGHT	3
#define S_FRAMES	4

const SDL_Rect sprite_rects[] = {
	{0,0,13,8},
	{14,0,8,8},
	{23,0,11,8},
	{35,0,12,8},
	{48,0,11,8}
};

class Entity {

public:

	Entity();
	Entity(double x, double y, int type);
	void render(SDL_Texture * image, SDL_Renderer *renderer);
	double GetX();
	double GetY();
	int GetWidth();
	int GetHeight();

protected:
	SDL_Rect texture_rect;
	SDL_Rect rect;

	//Methods
	virtual void Move(double delta, Direction dir) = 0;
	virtual void Update() = 0;

};
