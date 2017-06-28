#pragma once

#include "entity.h"

class Bullet : public Entity{
public:
	Bullet(Entity* source, EntityType type);
	//void Move(double delta);
	void Update(double delta);
private:

	Entity* source;
	static const int speed = 150;
};