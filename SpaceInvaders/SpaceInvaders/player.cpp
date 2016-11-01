#include "player.h"

Player::Player() : Player(0, 0)
{

}

Player::Player(int x, int y) : Entity(x, y)
{
	std::cout << "In player constructor:" << std::endl;
}

void Player::move()
{
	x += (int)(xDir * speed);
	xDir = 0;
}


void Player::update(const Uint8 *keyState)
{
	
	if (keyState[SDL_SCANCODE_A])
		xDir = -1;
	if (keyState[SDL_SCANCODE_D])
		xDir = 1;

	move();

	std::cout << "x:" <<  x << std::endl;
}