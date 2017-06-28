#include <invader.h>

Vector2 Invader::all_direction = RIGHT;

Invader::Invader(int x, int y, EntityType type) 
	: Entity((float)x, (float)y, type)
{
	
}

void Invader::ChangeDirection(const Vector2 dir)
{
	all_direction = dir;
}

Vector2 Invader::GetAllDirection()
{
	return all_direction;
}

Invader * Invader::Invader1(int x, int y)
{
	return new Invader(x, y, ENEMY1);
}

Invader * Invader::Invader2(int x, int y)
{
	return new Invader(x, y, ENEMY2);
}

Invader * Invader::Invader3(int x, int y)
{
	return new Invader(x, y, ENEMY3);
}

void Invader::Update(double delta)
{
	rect.x += (int)(all_direction.x * INVADER_MOVE_X);
	rect.y += (int)(all_direction.y * INVADER_MOVE_X);
	anim.Update();
}
