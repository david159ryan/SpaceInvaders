#pragma once

#include <entity.h>

class Player : public Entity {

public :

	//Constructors
	Player();
	Player(double x, double y);

	//Methods
	void Update(const Uint8 *keyState, double delta);
	int GetDirection();
	void Move(double delta);
	void Move();

private:
	//Fields
	int x_dir;
	double speed;
	//Methods
};