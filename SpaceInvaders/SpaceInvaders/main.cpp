// SpaceInvaders.cpp : Defines the entry point for the console application.
//
#include <main.h>
#undef main

int main(int argc, char *argv[])
{

	WIDTH = 640;
	HEIGHT = 480;

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	init_SDL(window, renderer);

	SpaceInvaders game(WIDTH, HEIGHT);

	int done = 0;
	while (!done)
	{
		done = process_events(window);
		game.update();
		//render(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	return 0;
}

int process_events(SDL_Window *window)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				return 1;
			}
			break;
		case SDLK_ESCAPE:
			return 1;
		case SDL_QUIT:
			//quit out of the game
			return 1;
		}

	}

	//update();

	return 0;
}

void init_SDL(SDL_Window *window, SDL_Renderer *renderer) 
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	window = SDL_CreateWindow("Game Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		0
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


}

