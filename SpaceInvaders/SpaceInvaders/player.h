#pragma once

#include <entity.h>

class Player : public Entity {

public :
	Player();
	Player(double x, double y);
	void update(const Uint8 *keyState, double delta);

private:
	int xDir = 0;
	double speed = 100;
	void move(double delta);
};