#include "common.h"
#include "invader.h"

Vector2 Invader::s_allDirection = RIGHT;

Invader::Invader(int x, int y, EntityType type)
	: Entity(x, y, type)
{

}

void Invader::ChangeDirection(const Vector2 dir)
{
	s_allDirection = dir;
}

Vector2 Invader::GetAllDirection()
{
	return s_allDirection;
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
	UNUSED(delta);
	m_rect.x += s_allDirection.x * INVADER_MOVE_X;
	m_rect.y += s_allDirection.y * INVADER_MOVE_Y;
	m_anim.Update();
}
