#include "SpaceInvaders.h"

SpaceInvaders::SpaceInvaders()
{
	//intentionally blank
}

SpaceInvaders::SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer)
{
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->renderer = renderer;
	keyState = SDL_GetKeyboardState(NULL);
	player = new Player(100, HEIGHT  - 20);
	load_sprites();
}

void SpaceInvaders::render()
{
	//fprintf(stdout, "width:\t%d\nheight:\t%d\n", WIDTH, HEIGHT);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	player->render(texture, renderer);
	SDL_RenderPresent(renderer);
}

void SpaceInvaders::update(double delta)
{
	player->update(keyState, delta);
}

void SpaceInvaders::load_sprites()
{
	SDL_Surface * image = IMG_Load("res\\sprites.png");
	if (image == 0) {
		std::cout << "Image failed to load" << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
}



