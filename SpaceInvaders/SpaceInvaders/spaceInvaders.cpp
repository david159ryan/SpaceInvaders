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
	key_state = SDL_GetKeyboardState(NULL);
	player = new Player(100, HEIGHT  - 20);
	LoadSprites();
}

void SpaceInvaders::Render()
{
	//fprintf(stdout, "width:\t%d\nheight:\t%d\n", WIDTH, HEIGHT);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	player->render(texture, renderer);
	SDL_RenderPresent(renderer);
}

void SpaceInvaders::Update(double delta)
{
	player->Update(key_state, delta);

	if ((player->GetX() > SIDE_BORDER && player->GetDirection() < 0) || 
			(player->GetX() < WIDTH - SIDE_BORDER - player->GetWidth() && player->GetDirection() > 0)) {
		player->Move(delta);
	}
}

void SpaceInvaders::LoadSprites()
{
	SDL_Surface * image = IMG_Load("res\\sprites.png");
	if (image == 0) {
		std::cout << "Image failed to load" << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
}

const int SpaceInvaders::GetWidth()
{
	return WIDTH;
}

const int SpaceInvaders::GetHeight()
{
	return HEIGHT;
}



