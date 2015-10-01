#pragma once
#include "lib/framework.hpp"
#include "Bullet.h"
#include <list>

class Player
{
private:

	Vec2f pos;
	float radius;
	float speed;

	void Move();
	void BulletListUpDate();

	std::list<Bullet*> bullet_list;

public:

	Player();

	void UpDate();
	void Draw();

};