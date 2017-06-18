#include <invader.h>

Invader::Invader()
{

}

Invader::Invader(int x, int y, int type) : Entity(x, y, type)
{

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

void Invader::Move(double delta, int dir)
{
	rect.x += dir * INVADER_MOVE_X;
}

void Invader::Update()
{

}
