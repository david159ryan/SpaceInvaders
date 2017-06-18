#pragma once
#include <player.h>
#include <global.h>
#include <SpaceInvaders.h>

Player::Player() : Player(0, 0)
{
	//intentionally blank
}

Player::Player(double x, double y) : Entity(x, y, PLAYER)
{
	std::cout << "In player constructor:" << std::endl;
	x_dir = 0;
	speed = 100;
}

void Player::Move(double delta, int dir)
{
	double step = x_dir * speed * delta;

	x += step;
	rect = { (int)x, (int)y, w, h};
	x_dir = 0;
	//std::cout << "xdir * speed:\t" << (xDir * speed) << "\t:\t" << delta << std::endl;
}



void Player::Update(const Uint8 *keyState, double delta)
{
	
	if (keyState[SDL_SCANCODE_A])
		x_dir = -1;
	if (keyState[SDL_SCANCODE_D])
		x_dir = 1;

	//std::cout << "delta:" <<  delta << std::endl;
}

void Player::Update()
{
	//Intentionally Blank
}

int Player::GetDirection()
{
	return x_dir;
}
