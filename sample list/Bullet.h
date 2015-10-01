#pragma once
#include "lib/framework.hpp"

class Bullet
{
private:

	bool is_active;
	Vec2f pos;
	Vec2f move_axis;
	float radius;
	float speed;
	int destroy_count;

public:

	Bullet(Vec2f, Vec2f);

	void UpDate();
	void Draw();

	bool IsActive(){ return is_active; }
};