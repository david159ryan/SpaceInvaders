#pragma once
#include <algorithm>
#include <vector>

#include "entity.h"
#include "invader.h"
#include "player.h"
#include "stopwatch.h"

class SpaceInvaders {
public:

	const uint PLAYER_SIDE_BORDER	= 10;
	const uint PLAYER_Y_OFFSET		= 20;
	const uint INVADER_SIDE_BORDER	= 5;
	const uint INVADER_Y_OFFSET		= 30;
	const uint INVADER_Y_GAP		= 15;
	const uint INVADER_ROWS			= 5;
	const uint INVADER_COLS			= 11;
	const uint INVADER_MOVE_TIME	= 900; //initial move time

	SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer);
	void Render();
	void Update(double delta);
	void InitGame();
	const int GetWidth();
	const int GetHeight();


private:
	uint WIDTH;
	uint HEIGHT;
	uint next_move_time;
	uint invader_speed;
	const Uint8 *key_state;
	SDL_Renderer *renderer;
	//std::vector<Entity> enemies;
	Player *player;
	std::vector<std::vector<Invader *>> invaders;
	SDL_Texture * texture;
	void LoadSprites();
	void InitInvaders();
	void MoveInvaders(double delta);
	void UpdateInvaders(double delta);
	Vector2 CheckInvaderBorders();
	bool b_move_invaders;
	Stopwatch stopwatch;
};
