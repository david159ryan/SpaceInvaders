#include <player.h>
#include <global.h>

Player::Player() : Player(0, 0)
{
	//intentionally blank
}

Player::Player(double x, double y) : Entity(x, y)
{
	std::cout << "In player constructor:" << std::endl;
	w = 13;
	h = 8;
	textureRect = { 0, 0, w, h };
	rect = { (int)x, (int)y, w , h};
}

void Player::move(double delta)
{
	x += xDir * speed * delta;
	//std::cout << "xdir * speed:\t" << (xDir * speed) << "\t:\t" << delta << std::endl;
	xDir = 0;
	rect = { (int)x, (int)y, w, h};
}


void Player::update(const Uint8 *keyState, double delta)
{
	
	if (keyState[SDL_SCANCODE_A])
		xDir = -1;
	if (keyState[SDL_SCANCODE_D])
		xDir = 1;

	move(delta);

	//std::cout << "delta:" <<  delta << std::endl;
}