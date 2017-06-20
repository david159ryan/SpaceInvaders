#include "SpaceInvaders.h"


SpaceInvaders::SpaceInvaders()
{
}

SpaceInvaders::SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer)
{
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->renderer = renderer;
	b_move_invaders = true;
	invader_speed = INVADER_MOVE_TIME;
	next_move_time = INVADER_MOVE_TIME;
	key_state = SDL_GetKeyboardState(NULL);
	player = new Player(100, HEIGHT - 20);
	stopwatch = Stopwatch();
	InitGame();
}

void SpaceInvaders::InitGame()
{
	InitInvaders();
	LoadSprites();
	stopwatch.Reset();
	stopwatch.Start();
}

/*
	Stores invaders as for vector of columns which each contain a
	vector of Invaders. This should help keep track of which Invaders
	are at the edges and which Invaders are at the bottom.
*/
void SpaceInvaders::InitInvaders()
{
	int invader_bounds = (WIDTH * 4 / 5 - INVADER_SIDE_BORDER * 2);
	int x_gap =  invader_bounds / INVADER_COLS;
	int x_off = (WIDTH - invader_bounds) / 2;
	invaders.resize(INVADER_COLS);
	invader_move_dir = Direction::RIGHT;

	for (int i = 0; i < INVADER_ROWS; i++) {
		int yy = INVADER_Y_OFFSET + (INVADER_Y_GAP * i);
		for (int j = 0; j < INVADER_COLS; j++) {
			int xx = x_off + INVADER_SIDE_BORDER + x_gap * j;
			switch (i) {
			case 0:
				invaders[j].push_back(Invader::Invader1(xx, yy));
				break;
			case 1: case 2:
				invaders[j].push_back(Invader::Invader2(xx, yy));
				break;
			default:
				invaders[j].push_back(Invader::Invader3(xx, yy));
			}
		}
	}
}

void SpaceInvaders::Render()
{
	//fprintf(stdout, "width:\t%d\nheight:\t%d\n", WIDTH, HEIGHT);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	player->render(texture, renderer);		//render player

	//Iterate through invaders and render them
	std::for_each(invaders.begin(), invaders.end(), [&](std::vector<Invader *> in) {
		std::for_each(in.begin(), in.end(),
			[&](Invader * i) { i->render(texture, renderer); }
		);
	});

	SDL_RenderPresent(renderer);
}

void SpaceInvaders::Update(double delta)
{
	player->Update(key_state, delta);

	// Check player bounds and move
	if ((player->GetX() > PLAYER_SIDE_BORDER && player->GetDirection() < 0) || 
			(player->GetX() < WIDTH - PLAYER_SIDE_BORDER - player->GetWidth() && 
				player->GetDirection() > 0)) 
	{
		player->Move(delta, Direction::DOWN); //DOWN will be ignored by player
	}


	//Check if invaders
	if (stopwatch.GetTime() >= invader_speed) {
		MoveInvaders(delta);
		stopwatch.Reset();
		stopwatch.Start();
	}
}

void SpaceInvaders::MoveInvaders(double delta)
{
	Direction next_dir = CheckInvaderBorders();

	invader_move_dir = (next_dir == invader_move_dir) ? next_dir : Direction::DOWN;

	std::for_each(invaders.begin(), invaders.end(), [&](std::vector<Invader *> in) {
		std::for_each(in.begin(), in.end(),
			[&](Invader * i) { i->Move(delta, invader_move_dir); }
		);
	});

	invader_move_dir = next_dir;
}
 
Direction SpaceInvaders::CheckInvaderBorders()
{
	Direction d = invader_move_dir;
	if (invader_move_dir == Direction::LEFT) {
		Invader * inv = invaders.front().front();
		if (inv->GetX() < INVADER_SIDE_BORDER) {
			d = Direction::RIGHT;
		}
	}
	else if (invader_move_dir == Direction::RIGHT) {
		Invader * inv = invaders.back().back();
		if (inv->GetX() + inv->GetWidth() > WIDTH - INVADER_SIDE_BORDER) {
			d = Direction::LEFT;
		}
	}
	return d;
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



