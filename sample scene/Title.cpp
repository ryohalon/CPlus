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
	font.draw("タイトル", Vec2f(-100, 0), Color::white);
}

void gameScene(AppEnv& env, Font& font)
{
	font.draw("ゲーム", Vec2f(-100, 0), Color::white);
}

void resultScene(AppEnv& env, Font& font)
{
	font.draw("リザルト", Vec2f(-100, 0), Color::white);
}