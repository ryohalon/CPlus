#include "Player.h"

bool IsBulletErase(Bullet *bullet)
{
	return !bullet->IsActive();
}

Player::Player()
{
	pos = Vec2f(0.0f, 0.0f);
	radius = 100.0f;
	move_axis = Vec2f(0, 1);
	speed = 5.0f;
}

void Player::BulletUpDate()
{
	if (App::Get().isPushKey(GLFW_KEY_ENTER))
	{
		bulletVector.push_back(new Bullet(pos, move_axis));
	}

	for (unsigned int i = 0; i < bulletVector.size(); i++)
	{
		bulletVector[i]->UpDate();
	}

	bulletVector.erase(std::remove_if(bulletVector.begin(), bulletVector.end(), IsBulletErase), bulletVector.end());

}

void Player::Move()
{
	if (App::Get().isPressKey('A'))
		pos.x() -= speed;
	if (App::Get().isPressKey('D'))
		pos.x() += speed;
	if (App::Get().isPressKey('W'))
		pos.y() += speed;
	if (App::Get().isPressKey('S'))
		pos.y() -= speed;
}

void Player::WallCollision()
{
	if (pos.x() + radius > WIN_WIDTH / 2)
		pos.x() = WIN_WIDTH / 2 - radius;

	if (pos.x() - radius < -WIN_WIDTH / 2)
		pos.x() = -WIN_WIDTH + radius;

	if (pos.y() + radius > WIN_HEIGHT / 2)
		pos.y() = WIN_HEIGHT / 2 - radius;

	if (pos.y() - radius < -WIN_HEIGHT / 2)
		pos.y() = -WIN_HEIGHT / 2 + radius;
}

void Player::UpDate()
{
	Move();

	BulletUpDate();

	WallCollision();
}

void Player::Draw()
{
	drawFillCircle(pos.x(), pos.y(), radius, radius, 100, Color::red);

	for (unsigned int i = 0; i < bulletVector.size(); i++)
	{
		bulletVector[i]->Draw();
	}
}