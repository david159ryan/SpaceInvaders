#include "bullet.h"

Bullet::Bullet(Entity* source, EntityType type) 
	: Entity(source->GetX(), source->GetY(), type)
{
	m_source = source;
	m_direction = (source->Type() == PLAYER) ? UP : DOWN;
	m_anim.Play();
}

void Bullet::Update(double delta)
{
	m_anim.Update();
	double step = SPEED * m_direction.y * delta;
	m_rect.y += static_cast<int>(step);
}