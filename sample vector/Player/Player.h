#pragma once
#include "../lib/framework.hpp"
#include "../Bullet/Bullet.h"
#include "../Singleton/AppEnvSingletonr.h"

class Player
{
private:

	Vec2f pos, move_axis;
	float radius;
	float speed;

	void BulletUpDate();
	void Move();
	void WallCollision();

public:

	Player();

	void UpDate();
	void Draw();

	std::vector<Bullet*> bulletVector;

};