#include "Player.h"
#include "SingletonApp.h"

Player::Player()
{
	pos = Vec2f(0.0f, 0.0f);
	radius = 100.0f;
	speed = 10.0f;
}

bool IsBulletErase(Bullet *bullet)
{
	return !bullet->IsActive();
}

void Player::Move()
{
	if (App::Get().isPressKey('A'))
		pos.x() -= speed;
	if (App::Get().isPressKey('D'))
		pos.x() += speed;
	if (App::Get().isPressKey('S'))
		pos.y() -= speed;
	if (App::Get().isPressKey('W'))
		pos.y() += speed;
}

void Player::BulletListUpDate()
{
	if (App::Get().isPushKey(GLFW_KEY_LEFT))
	{
		bullet_list.push_back(new Bullet(pos, Vec2f(-1.0f, 0.0f)));
	}

	if (App::Get().isPushKey(GLFW_KEY_RIGHT))
	{
		bullet_list.push_back(new Bullet(pos, Vec2f(1.0f, 0.0f)));
	}

	if (App::Get().isPushKey(GLFW_KEY_UP))
	{
		bullet_list.push_back(new Bullet(pos, Vec2f(0.0f, 1.0f)));
	}

	if (App::Get().isPushKey(GLFW_KEY_DOWN))
	{
		bullet_list.push_back(new Bullet(pos, Vec2f(0.0f, -1.0f)));
	}

	std::list<Bullet*>::iterator it = bullet_list.begin();
	while (it != bullet_list.end())
	{
		(*it)->UpDate();

		it++;
	}

	bullet_list.remove_if(IsBulletErase);
}

void Player::UpDate()
{
	Move();

	BulletListUpDate();
}

void Player::Draw()
{
	drawFillCircle(pos.x(), pos.y(), radius, radius, 100, Color::blue);

	std::list<Bullet*>::iterator it = bullet_list.begin();
	while (it != bullet_list.end())
	{
		(*it)->Draw();
		
		it++;
	}
}