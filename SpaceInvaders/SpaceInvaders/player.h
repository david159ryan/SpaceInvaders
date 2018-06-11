#pragma once

#include "entity.h"
#include "bullet.h"

class Player : public Entity {

public :

	//Constructor
	Player(float x, float y, const Uint8 *key_state);
	~Player();
	//Methods
	void Update(double delta);
	void RenderBullets(SDL_Texture* texture, SDL_Renderer* renderer);

private:
	//Fields
	double m_speed;
	const Uint8 *m_keyState;
	Bullet* m_bullet;
	bool m_canFire;

	void Fire();
	void Move(double delta);
};
