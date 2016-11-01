#include "entity.h"


Entity::Entity() : Entity(0, 0)
{
	std::cout << "In Entity empty constructor:" << std::endl;

}

Entity::Entity(int x, int y)
{
	this->x = x;
	this->y = y;
	std::cout << "In Entity constructor:\t" << x << "\t" << y << std::endl;
}

void Entity::render(const int WIDTH, const int HEIGHT)
{
	std::cout << "In Entity render:" << std::endl;

}

