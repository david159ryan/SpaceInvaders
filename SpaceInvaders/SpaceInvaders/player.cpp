#pragma once
#include <player.h>
#include <global.h>
#include <SpaceInvaders.h>

Player::Player() : Player(0, 0)
{
	//intentionally blank
}

Player::Player(double x, double y) : Entity(x, y)
{
	std::cout << "In player constructor:" << std::endl;
	w = 13;
	h = 8;
	x_dir = 0;
	speed = 100;
	texture_rect = { 0, 0, w, h };
	rect = { (int)x, (int)y, w , h};

}

void Player::Move(double delta)
{
	double step = x_dir * speed * delta;

	x += step;
	rect = { (int)x, (int)y, w, h};
	x_dir = 0;
	//std::cout << "xdir * speed:\t" << (xDir * speed) << "\t:\t" << delta << std::endl;
}

void Player::Move()
{
	//Intentionally Blank
}


void Player::Update(const Uint8 *keyState, double delta)
{
	
	if (keyState[SDL_SCANCODE_A])
		x_dir = -1;
	if (keyState[SDL_SCANCODE_D])
		x_dir = 1;

	//std::cout << "delta:" <<  delta << std::endl;
}

int Player::GetDirection()
{
	return x_dir;
}
