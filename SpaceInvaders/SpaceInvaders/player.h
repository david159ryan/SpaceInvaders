#pragma once

#include <entity.h>
#include <bullet.h>

class Player : public Entity {

public :

	//Constructor
	Player(float x, float y, const Uint8 *key_state);
	~Player();
	//Methods
	void Update(double delta);
	void RenderBullets(SDL_Texture* texture, SDL_Renderer* renderer);
	Bullet* bullet;

private:
	//Fields
	double speed;
	const Uint8 *key_state;
	bool b_can_fire;
	void Fire();
	void Move(double delta);
};