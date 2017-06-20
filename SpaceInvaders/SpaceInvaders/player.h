#pragma once

#include <entity.h>

class Player : public Entity {

public :

	//Constructors
	Player();
	Player(double x, double y);

	//Methods
	void Update(const Uint8 *keyState, double delta);
	void Update();
	Direction GetDirection();
	void Move(double delta, Direction dir);

private:
	//Fields
	Direction x_dir;
	double speed;
	//Methods
};