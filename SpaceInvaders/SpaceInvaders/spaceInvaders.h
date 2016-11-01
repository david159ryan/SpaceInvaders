#pragma once
#include <entity.h>
#include <player.h>
#include <vector>

class SpaceInvaders {
public:
	SpaceInvaders();
	SpaceInvaders(int WIDTH, int HEIGHT);
	void render();
	void update();

private:
	int WIDTH;
	int HEIGHT;
	const Uint8 *keyState;
	//std::vector<Entity> enemies;
	Player *player;
};