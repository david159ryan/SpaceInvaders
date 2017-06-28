#pragma once
#include <player.h>

Player::Player(float x, float y, const Uint8 *key_state) : 
	Entity(x, y, PLAYER)
{
	std::cout << "In player constructor:" << std::endl;
	direction = STILL;
	speed = 100;
	b_can_fire = true;
	bullet = nullptr;
	this->key_state = key_state;
}

void Player::Move(double delta)
{
	double step = direction.x * speed * delta;

	rect.x += (int)step;
	direction = STILL;
	//std::cout << "xdir * speed:\t" << (direction.x * speed) << "\t:\t" << delta << std::endl;
}

void Player::RenderBullets(SDL_Texture * texture, SDL_Renderer * renderer)
{
	if (bullet != nullptr) {
		bullet->Render(texture, renderer);
	}
}

void Player::Update(double delta)
{

	if (key_state[SDL_SCANCODE_A])
		direction = LEFT;
	if (key_state[SDL_SCANCODE_D])
		direction = RIGHT;
	
	Move(delta);

	if (key_state[SDL_SCANCODE_SPACE]) {
		Fire();
	}
	if (bullet != nullptr) {
		bullet->Update(delta);
		if (bullet->GetY() < 0) {
			delete bullet;
			bullet = nullptr;
		}
	}

	//std::cout << "delta:" <<  delta << std::endl;
}

void Player::Fire()
{
	if (bullet == nullptr) {
		bullet = new Bullet(this, BULLET1);
	}
}

Player::~Player()
{
	delete bullet;
}