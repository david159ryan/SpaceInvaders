#include "SpaceInvaders.h"

SpaceInvaders::SpaceInvaders()
{
	//intentionally blank
}

SpaceInvaders::SpaceInvaders(int WIDTH, int HEIGHT)
{
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	keyState = SDL_GetKeyboardState(NULL);
	player = new Player(100, 100);
}

void SpaceInvaders::render()
{
	//fprintf(stdout, "width:\t%d\nheight:\t%d\n", WIDTH, HEIGHT);
	player->render(WIDTH, HEIGHT);
}

void SpaceInvaders::update()
{
	player->update(keyState);
}



