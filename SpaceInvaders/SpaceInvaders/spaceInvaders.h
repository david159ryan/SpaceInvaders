#pragma once
#include <entity.h>
#include <player.h>
#include <vector>

class SpaceInvaders {
public:
	SpaceInvaders();
	SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer);
	void Render();
	void Update(double delta);
	const int GetWidth();
	const int GetHeight();
	static const int SIDE_BORDER = 10;
	static const int PLAYER_Y_OFFSET = 20;

private:	
	int WIDTH;
	int HEIGHT;
	const Uint8 *key_state;
	SDL_Renderer *renderer;
	//std::vector<Entity> enemies;
	Player *player;
	SDL_Texture * texture;
	void LoadSprites();

};