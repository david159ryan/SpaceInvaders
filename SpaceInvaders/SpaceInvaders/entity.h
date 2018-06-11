#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "global.h"
#include "animation.h"

class Entity {

public:

	Entity(int x, int y, EntityType type);
	virtual ~Entity();
	void Render(SDL_Texture * image, SDL_Renderer *renderer);
	EntityType Type();
	Vector2 GetDirection();
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	void Clamp(int left, int right, int top, int bottom);
	void SetPosition(int x, int y);
	uint Width();
	uint Height();
	uint RightBorder();
	uint LeftBorder();
	uint TopBorder();
	uint BottomBorder();
	bool Intersects(const Entity * other, SDL_Rect * result);
	void Kill();

protected:
	Vector2 m_direction;
	EntityType m_type;
	Animation m_anim;
	SDL_Rect m_textureRect;
	SDL_Rect m_rect;
	bool m_isDeathAnim;
	//Methods
	virtual void Update(double delta) = 0;
};
