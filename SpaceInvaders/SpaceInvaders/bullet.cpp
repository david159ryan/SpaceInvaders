#include "bullet.h"

Bullet::Bullet(Entity* source, EntityType type) 
	: Entity(source->GetX(), source->GetY(), type, new Animation(SPRITES[type], 2, 500, true))
{
	this->source = source;
	direction = (source->Type() == PLAYER) ? UP : DOWN;
}

void Bullet::Update(double delta)
{
	anim->Update();
	rect.y += (int)(speed * direction.y * delta);
}