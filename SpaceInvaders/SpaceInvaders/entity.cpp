#include "entity.h"


Entity::Entity() : Entity(0, 0, 0)
{
	std::cout << "In Entity empty constructor:" << std::endl;

}

Entity::Entity(double x, double y, int type)
{

	texture_rect = sprite_rects[type];
	rect = { (int)x, (int)y, texture_rect.w , texture_rect.h };
}

void Entity::render(SDL_Texture *texture, SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, &texture_rect, &rect);
}

double Entity::GetX()
{
	return rect.x;
}

double Entity::GetY()
{
	return rect.y;
}

int Entity::GetWidth()
{
	return rect.w;
}

int Entity::GetHeight()
{
	return rect.h;
}