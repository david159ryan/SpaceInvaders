#include "player.h"

Player::Player(float x, float y, const Uint8 *key_state) :
	Entity(x, y, PLAYER),
	m_speed(100),
	m_keyState(key_state),
	m_bullet(nullptr),
	m_canFire(true)
{

}

void Player::Move(double delta)
{
	double step = m_direction.x * m_speed * delta;

	m_rect.x += static_cast<int>(step);
	m_direction = STILL;
	//std::cout << "xdir * speed:\t" << (m_direction.x * m_speed) << "\t:\t" << delta << std::endl;
}

void Player::RenderBullets(SDL_Texture * texture, SDL_Renderer * renderer)
{
	if (m_bullet != nullptr) {
		m_bullet->Render(texture, renderer);
	}
}

void Player::Update(double delta)
{

	if (m_keyState[SDL_SCANCODE_A])
	{
		m_direction = LEFT;
	}
	if (m_keyState[SDL_SCANCODE_D])
	{
		m_direction = RIGHT;
	}

	Move(delta);

	if (m_keyState[SDL_SCANCODE_SPACE]) 
	{
		Fire();
	}

	if (m_bullet != nullptr) 
	{
		m_bullet->Update(delta);
		if (m_bullet->GetY() < 0) 
		{
			delete m_bullet;
			m_bullet = nullptr;
		}
	}
}

void Player::Fire()
{
	if (m_bullet == nullptr) {
		m_bullet = new Bullet(this, BULLET1);
	}
}

Player::~Player()
{
	if (m_bullet)
	{
		delete m_bullet;
	}
}
