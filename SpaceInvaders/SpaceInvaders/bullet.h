#pragma once

#include "entity.h"

class Bullet : public Entity{
public:
	Bullet(Entity* source, EntityType type);
	//void Move(double delta);
	void Update(double delta);
private:

	Entity* source;
	const int speed = 100;
	uint64_t ANIM_SPEED = (uint64_t)(500L);
};