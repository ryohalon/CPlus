#include "Bullet.h"

Bullet::Bullet(Vec2f pos, Vec2f move_axis)
{
	this->pos = pos;
	this->move_axis = move_axis;
	speed = 2.0f;
	radius = 10.0f;
	is_active = true;
	destroy_count = 120;
}

void Bullet::UpDate()
{
	pos += move_axis * speed;

	destroy_count--;

	if (destroy_count <= 0)
	{
		is_active = false;
	}
}

void Bullet::Draw()
{
	drawFillCircle(pos.x(), pos.y(), radius, radius, 100, Color::cyan);
}