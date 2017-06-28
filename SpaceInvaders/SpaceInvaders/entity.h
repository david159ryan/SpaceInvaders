#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "global.h"
#include "Animation.h"

class Entity {

public:

	Entity(float x, float y, EntityType type);
	~Entity();
	void Render(SDL_Texture * image, SDL_Renderer *renderer);
	EntityType Type();
	Vector2 GetDirection();
	float GetX();
	float GetY();
	void SetX(int x);
	void SetY(int y);
	void Clamp(int left, int right, int top, int bottom);
	void SetPosition(int x, int y);
	int Width();
	int Height();
	int RightBorder();
	int LeftBorder();
	int TopBorder();
	int BottomBorder();
	bool Intersects(const Entity * other, SDL_Rect * result);
	void Kill();

protected:
	SDL_Rect texture_rect;
	SDL_Rect rect;
	EntityType type;
	Vector2 direction;
	Animation anim;
	bool b_death_anim;
	//Methods
	virtual void Update(double delta) = 0;
};
