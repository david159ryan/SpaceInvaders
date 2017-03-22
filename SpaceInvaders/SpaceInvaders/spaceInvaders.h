#pragma once
#include <entity.h>
#include <player.h>
#include <vector>

class SpaceInvaders {
public:
	SpaceInvaders();
	SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer);
	void render();
	void update(double delta);

private:
	int PLAYER_Y_OFFSET;
	
	int WIDTH;
	int HEIGHT;
	const Uint8 *keyState;
	SDL_Renderer *renderer;
	//std::vector<Entity> enemies;
	Player *player;
	SDL_Texture * texture;
	void load_sprites();

};