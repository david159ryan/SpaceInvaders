#include "entity.h"


Entity::Entity() : Entity(0, 0, 0)
{
	std::cout << "In Entity empty constructor:" << std::endl;

}

Entity::Entity(double x, double y, int type)
{
	this->x = x;
	this->y = y;
	texture_rect = sprite_rects[type];
	w = texture_rect.w;
	h = texture_rect.h;
	rect = { (int)x, (int)y, w , h };
}

void Entity::render(SDL_Texture *texture, SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, &texture_rect, &rect);
}

double Entity::GetX()
{
	return x;
}

double Entity::GetY()
{
	return y;
}

int Entity::GetWidth()
{
	return w;
}

int Entity::GetHeight()
{
	return h;
}