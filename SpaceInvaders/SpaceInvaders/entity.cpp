#include "entity.h"

Entity::Entity(float x, float y, EntityType type)
{
	this->anim = Animation(ANIMATIONS[type]);
	texture_rect = *(this->anim.CurrentFrame());
	rect = { (int)x, (int)y, texture_rect.w , texture_rect.h };
	this->type = type;
	direction = STILL;
	//anim.Play();
}

void Entity::Render(SDL_Texture *texture, SDL_Renderer *renderer)
{
	texture_rect = *(anim.CurrentFrame());
	if (renderer == nullptr || texture == nullptr) {
		std::cout << "renderer: " << renderer << std::endl << "texture: " << texture << std::endl;
		return;
	}
	SDL_RenderCopy(renderer, texture, &texture_rect, &rect);
}

float Entity::GetX()
{
	return rect.x;
}

float Entity::GetY()
{
	return rect.y;
}

void Entity::SetX(int x)
{
	rect.x = x;
}

void Entity::SetY(int y)
{
	rect.y = y;
}

void Entity::Clamp(int left, int right, int top, int bottom)
{
	rect.x = (rect.x < left)	? left		: rect.x;
	rect.x = (rect.x > right)	? right		: rect.x;
	rect.y = (rect.y > top)		? top		: rect.y;
	rect.y = (rect.y < bottom)	? bottom	: rect.y;
}

void Entity::SetPosition(int x, int y)
{
	SetX(x);
	SetY(y);
}

int Entity::Width()
{
	return rect.w;
}

int Entity::Height()
{
	return rect.h;
}

int Entity::RightBorder()
{
	return rect.x + rect.w;
}

int Entity::LeftBorder()
{
	return rect.x;
}

int Entity::TopBorder()
{
	return rect.y;
}

int Entity::BottomBorder()
{
	return rect.y + rect.h;
}

bool Entity::Intersects(const Entity * other, SDL_Rect * result)
{
	return SDL_IntersectRect(&rect, &other->rect, NULL);
}

void Entity::Kill()
{

}

EntityType Entity::Type()
{
	return type;
}

Vector2 Entity::GetDirection()
{
	return direction;
}

Entity::~Entity()
{
	//delete anim;
}