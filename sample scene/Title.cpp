#include "Title.h"

int changeScene(AppEnv& env, int& n)
{
	if (env.isPushKey(GLFW_KEY_ENTER))
	{
		n = (n + 1) % 3;
	}

	return n;
}

void titleScene(AppEnv& env, Font& font)
{
	font.draw("�^�C�g��", Vec2f(-100, 0), Color::white);
}

void gameScene(AppEnv& env, Font& font)
{
	font.draw("�Q�[��", Vec2f(-100, 0), Color::white);
}

void resultScene(AppEnv& env, Font& font)
{
	font.draw("���U���g", Vec2f(-100, 0), Color::white);
}