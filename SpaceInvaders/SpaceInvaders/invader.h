#pragma once
#include "entity.h"
#include "bullet.h"

class Invader : public Entity {

public:

	const uint INVADER_MOVE_X = 3;
	const uint INVADER_MOVE_Y = 8;

	static void ChangeDirection(Vector2 dir);
	static Vector2  GetAllDirection();
	static Invader * Invader1(int x, int y);
	static Invader * Invader2(int x, int y);
	static Invader * Invader3(int x, int y);
	void Update(double delta);
private:
	Invader(int x, int y, EntityType type);
	static Vector2 s_allDirection;
};
