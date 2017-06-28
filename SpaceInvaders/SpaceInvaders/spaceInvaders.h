#pragma once
#include <entity.h>
#include <invader.h>
#include <player.h>
#include <algorithm>
#include <vector>
#include <stopwatch.h>


class SpaceInvaders {
public:

	const int PLAYER_SIDE_BORDER	= 10;
	const int PLAYER_Y_OFFSET		= 20;
	const int INVADER_SIDE_BORDER	= 5;
	const int INVADER_Y_OFFSET		= 30;
	const int INVADER_Y_GAP			= 15;
	const int INVADER_ROWS			= 5;
	const int INVADER_COLS			= 11;
	const int INVADER_MOVE_TIME		= 900; //initial move time

	SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer);
	void Render();
	void Update(double delta);
	void InitGame();
	const int GetWidth();
	const int GetHeight();


private:	
	int WIDTH;
	int HEIGHT;
	int next_move_time;
	int invader_speed;
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