#pragma once
#include <SDL.h>
#include "Animation.h"
extern int SCALE, WIDTH, HEIGHT;

struct Vector2 {
	float x;
	float y;
	bool operator==(const Vector2  &rhs) const;
};

inline
bool Vector2::operator==(const Vector2 &rhs) const
{
	return (x == rhs.x) && (y == rhs.y);
}

const static Vector2 LEFT	= { -1, 0  };
const static Vector2 RIGHT	= {  1, 0  };
const static Vector2 UP		= {  0, -1  };
const static Vector2 DOWN	= {  0, 1 };
const static Vector2 STILL	= {  0, 0  };

static const uint64_t BULLET_ANIM_SPEED = 200;

//TODO implement something a little less archaic
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
	{ { 0,0,13,8 },{ 0,8,13,8 } },	//PLAYER1
	{ { 14,0,8,8 },{ 14,8,8,8 } },	//ENEMY1
	{ { 23,0,11,8 },{ 23,8,11,8 } },	//ENEMY2
	{ { 35,0,12,8 },{ 35,8,12,8 } },	//ENEMY3
	{ { 0,15,1,4 },{ 0,15,1,4 } },	//BULLETP
	{ { 14,16,3,9 },{ 14,25,3,9 } },	//BULLET1
	{ { 23,16,3,9 },{ 23,25,3,9 } },	//BULLET2
	{ { 35,16,3,9 },{ 35,25,3,9 } }	//BULLET3
};


const Animation ANIMATIONS[] = {
	Animation(SPRITES[PLAYER], 1, 0L, false),
	Animation(SPRITES[ENEMY1], 2, 0L, true),
	Animation(SPRITES[ENEMY2], 2, 0L, true),
	Animation(SPRITES[ENEMY3], 2, 0L, true),
	Animation(SPRITES[BULLETP], 1, 0L, false),
	Animation(SPRITES[BULLET1], 2, BULLET_ANIM_SPEED, true),
	Animation(SPRITES[BULLET2], 2, BULLET_ANIM_SPEED, true),
	Animation(SPRITES[BULLET3], 2, BULLET_ANIM_SPEED, true)
};
