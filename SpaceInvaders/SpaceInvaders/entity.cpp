#include "entity.h"

Entity::Entity(int x, int y, EntityType type) :
	m_direction(STILL),
	m_type(type),
	m_anim(Animation(ANIMATIONS[m_type])),
	m_textureRect(*(m_anim.CurrentFrame())),
	m_rect({ x, y, m_textureRect.w , m_textureRect.h }),
	m_isDeathAnim(false)
{

}

void Entity::Render(SDL_Texture *texture, SDL_Renderer *renderer)
{
	m_textureRect = *(m_anim.CurrentFrame());
	if (renderer == nullptr || texture == nullptr) {
		std::cout << "renderer: " << renderer << std::endl << "texture: " << texture << std::endl;
		return;
	}
	SDL_RenderCopy(renderer, texture, &m_textureRect, &m_rect);
}

int Entity::GetX()
{
	return m_rect.x;
}

int Entity::GetY()
{
	return m_rect.y;
}

void Entity::SetX(int x)
{
	m_rect.x = x;
}

void Entity::SetY(int y)
{
	m_rect.y = y;
}

void Entity::Clamp(int left, int right, int top, int bottom)
{
	m_rect.x = (m_rect.x < left)	? left		: m_rect.x;
	m_rect.x = (m_rect.x > right)	? right		: m_rect.x;
	m_rect.y = (m_rect.y > top)		? top		: m_rect.y;
	m_rect.y = (m_rect.y < bottom)	? bottom	: m_rect.y;
}

void Entity::SetPosition(int x, int y)
{
	SetX(x);
	SetY(y);
}

uint Entity::Width()
{
	return m_rect.w;
}

uint Entity::Height()
{
	return m_rect.h;
}

uint Entity::RightBorder()
{
	return m_rect.x + m_rect.w;
}

uint Entity::LeftBorder()
{
	return m_rect.x;
}

uint Entity::TopBorder()
{
	return m_rect.y;
}

uint Entity::BottomBorder()
{
	return m_rect.y + m_rect.h;
}

bool Entity::Intersects(const Entity * other, SDL_Rect * result)
{
	return SDL_IntersectRect(&m_rect, &other->m_rect, result);
}

void Entity::Kill()
{

}

EntityType Entity::Type()
{
	return m_type;
}

Vector2 Entity::GetDirection()
{
	return m_direction;
}

Entity::~Entity()
{

}