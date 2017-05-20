#include "entity.h"


Entity::Entity() : Entity(0, 0)
{
	std::cout << "In Entity empty constructor:" << std::endl;

}

Entity::Entity(double x, double y)
{
	this->x = x;
	this->y = y;
	std::cout << "In Entity constructor:\t" << x << "\t" << y << std::endl;
}

void Entity::render(SDL_Texture *texture, SDL_Renderer *renderer)
{
	//std::cout << "In Entity render:" << std::endl;
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

