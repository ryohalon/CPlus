#pragma once
#include "../lib/framework.hpp"

class Bullet
{
private:

	bool is_active;
	Vec2f pos;
	float radius;
	float speed;
	Vec2f move_axis;
	int destroy_count;

public:

	Bullet(Vec2f, Vec2f);

	void UpDate();
	void Draw();

	bool IsActive(){ return is_active; }
};