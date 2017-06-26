#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "global.h"
#include "Animation.h"

enum EntityType {
	PLAYER = 0,
	ENEMY1 = 1,
	ENEMY2 = 2,
	ENEMY3 = 3,
	BULLETP = 4,
	BULLET1 = 5,
	BULLET2 = 6,
	BULLET3 = 7,
};

static const SDL_Rect SPRITES[][2] = {
	{{0,0,13,8},{0,8,13,8}},	//PLAYER1
	{{14,0,8,8},{14,8,8,8}},	//ENEMY1
	{{23,0,11,8},{23,8,11,8}},	//ENEMY2
	{{35,0,12,8},{35,8,12,8}},	//ENEMY3
	{{0,15,1,4},{0,15,1,4}},	//BULLETP
	{{14,16,3,9},{14,25,3,9}},	//BULLET1
	{{23,16,3,9},{23,25,3,9}},	//BULLET2
	{{35,16,3,9},{35,25,3,9}}	//BULLET3
};


class Entity {

public:

	Entity(float x, float y, EntityType type, Animation * anim);
	void Render(SDL_Texture * image, SDL_Renderer *renderer);
	EntityType Type();
	Vector2 GetDirection();
	float GetX();
	float GetY();
	int Width();
	int Height();
	int RightBorder();
	int LeftBorder();
	int TopBorder();
	int BottomBorder();
	bool Intersects(const Entity * other, SDL_Rect * result);

protected:
	SDL_Rect texture_rect;
	SDL_Rect rect;
	EntityType type;
	Vector2 direction;
	Animation * anim;
	const Uint8 *key_state;
	//Methods
	virtual void Update(double delta) = 0;
};
