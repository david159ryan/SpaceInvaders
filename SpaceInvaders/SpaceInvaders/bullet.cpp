#include "bullet.h"

Bullet::Bullet(Entity* source, EntityType type) 
	: Entity(source->GetX(), source->GetY(), type)
{
	this->source = source;
	direction = (source->Type() == PLAYER) ? UP : DOWN;
	anim.Play();
}

void Bullet::Update(double delta)
{
	anim.Update();
	rect.y += (int)(speed * direction.y * delta);
}