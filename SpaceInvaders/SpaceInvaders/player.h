#pragma once

#include <entity.h>

class Player : public Entity {

public :
	Player();
	Player(int x, int y);
	void update(const Uint8 *keyState);

private:
	int xDir = 0;
	float speed = 1;
	void move();
};