#pragma once
#include <entity.h>
#include <bullet.h>

class Invader : public Entity {

public:

	const int INVADER_MOVE_X = 3;
	const int INVADER_MOVE_Y = 8;

	static Vector2 all_direction;
	static void ChangeDirection(Vector2 dir);
	static Vector2  GetAllDirection();
	static Invader * Invader1(int x, int y);
	static Invader * Invader2(int x, int y);
	static Invader * Invader3(int x, int y);
	void Update(double delta);
private:
	Invader(int x, int y, EntityType type);
};