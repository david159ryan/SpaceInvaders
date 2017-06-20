#include <main.h>
#undef main


int main(int argc, char *argv[])
{

	//TODO possibly move this somewhere else
	SCALE = 3;
	LOGICAL_WIDTH = 224;
	LOGICAL_HEIGHT = 256;
	WIDTH = LOGICAL_WIDTH * SCALE;
	HEIGHT = LOGICAL_HEIGHT * SCALE;
	//--------------------------------------


	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	InitSDL(&window, &renderer);

	SpaceInvaders game(LOGICAL_WIDTH, LOGICAL_HEIGHT, renderer);


	//int bRunning = 1; 
	int frameRate = 60; 
	double frameMs = 1000 / (double)frameRate; //calculate the length of each frame 
	double delta = 0;
	int done = 0;


	Uint32 currentTick = SDL_GetTicks();
	Uint32 previousTick = currentTick;
	Uint32 frameTimer = currentTick;
	int ticks = 0;
	while (!done)
	{
		previousTick = currentTick;
		currentTick = SDL_GetTicks();

		delta += currentTick - previousTick;

		if (delta > frameMs) {
			game.Update(delta / 1000.0);
			ticks++;
			delta = (delta - frameMs);
		}
		game.Render();

		if (currentTick - frameTimer > 1000) {
			std::cout << "frames:\t" << ticks << std::endl;
			frameTimer = currentTick;
			ticks = 0;
		}
		SDL_Delay(1);
		done = ProcessEvents(window);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	return 0;
}

int ProcessEvents(SDL_Window *window)
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

	return 0;
}

void InitSDL(SDL_Window **window, SDL_Renderer **renderer) 
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	*window = SDL_CreateWindow("Game Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		0
	);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(*renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);

}

