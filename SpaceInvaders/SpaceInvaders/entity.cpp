#include "entity.h"

Entity::Entity(float x, float y, EntityType type, Animation * anim)
{
	texture_rect = anim->CurrentFrame();
	rect = { (int)x, (int)y, texture_rect.w , texture_rect.h };
	this->anim = anim;
	this->type = type;
	direction = STILL;
	anim->Play();
}

void Entity::Render(SDL_Texture *texture, SDL_Renderer *renderer)
{
	texture_rect = anim->CurrentFrame();
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

EntityType Entity::Type()
{
	return type;
}

Vector2 Entity::GetDirection()
{
	return direction;
}
