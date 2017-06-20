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
	x_dir = DOWN;
	speed = 100;
}

void Player::Move(double delta, Direction dir)
{
	double step = x_dir * speed * delta;

	rect.x += (int)step;
	x_dir = DOWN;
	//std::cout << "xdir * speed:\t" << (xDir * speed) << "\t:\t" << delta << std::endl;
}



void Player::Update(const Uint8 *keyState, double delta)
{
	
	if (keyState[SDL_SCANCODE_A])
		x_dir = LEFT;
	if (keyState[SDL_SCANCODE_D])
		x_dir = RIGHT;

	//std::cout << "delta:" <<  delta << std::endl;
}

void Player::Update()
{
	//Intentionally Blank
}

Direction Player::GetDirection()
{
	return x_dir;
}
