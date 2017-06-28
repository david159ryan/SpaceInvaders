#include "SpaceInvaders.h"

SpaceInvaders::SpaceInvaders(int WIDTH, int HEIGHT, SDL_Renderer *renderer)
{
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->renderer = renderer;
	b_move_invaders = true;
	invader_speed = INVADER_MOVE_TIME;
	next_move_time = INVADER_MOVE_TIME;
	key_state = SDL_GetKeyboardState(NULL);
	player = new Player(100, HEIGHT - 20, key_state);
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
	//TODO maybe this should not be so hard-coded...
	int invader_bounds = (WIDTH * 5 / 6 - INVADER_SIDE_BORDER * 2);

	int x_gap =  invader_bounds / INVADER_COLS;
	int x_off = (WIDTH - invader_bounds) / 2;

	invaders.resize(INVADER_COLS);

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

	player->Render(texture, renderer);	//render player

	player->RenderBullets(texture, renderer);
	//Iterate through invaders and render them
	std::for_each(invaders.begin(), invaders.end(), [&](std::vector<Invader *> in) {
		std::for_each(in.begin(), in.end(),
			[&](Invader * i) { i->Render(texture, renderer); }
		);
	});

	SDL_RenderPresent(renderer);
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

void SpaceInvaders::Update(double delta)
{

	player->Update(delta);
	 
	// Fix player bounds
	player->Clamp(	PLAYER_SIDE_BORDER,								//left
					WIDTH - PLAYER_SIDE_BORDER - player->Width(),	//right
					player->GetY(),									//top (no change)
					player->GetY());								//bottom (no change)

	//Check if invaders should move
	if (stopwatch.GetTime() >= invader_speed) {
		MoveInvaders(delta);
		stopwatch.Reset();
		stopwatch.Start();
	}
}

void SpaceInvaders::MoveInvaders(double delta)
{
	Invader::ChangeDirection(CheckInvaderBorders());
	UpdateInvaders(delta);
	//Invader::ChangeDirection(next_dir);
}
 
void SpaceInvaders::UpdateInvaders(double delta)
{
	std::for_each(invaders.begin(), invaders.end(), [&](std::vector<Invader *> in) {
		std::for_each(in.begin(), in.end(), [&](Invader * i) { 
			i->Update(delta); 
		});
	});
}

//TODO sort out vector2 stuff, overload operators
Vector2 SpaceInvaders::CheckInvaderBorders()
{
	Vector2 d = Invader::GetAllDirection();
	Invader * inv_l = invaders.front().front();
	Invader * inv_r = invaders.back().back();

	bool b_left_border = (inv_l->LeftBorder() < INVADER_SIDE_BORDER);
	bool b_right_border = (inv_r->RightBorder() > WIDTH - INVADER_SIDE_BORDER);

	if (d == DOWN) {
		d = b_left_border ? RIGHT : LEFT;
	}else if (b_left_border || b_right_border) {
		d = DOWN;
	}
	return d;
}


const int SpaceInvaders::GetWidth()
{
	return WIDTH;
}

const int SpaceInvaders::GetHeight()
{
	return HEIGHT;
}



