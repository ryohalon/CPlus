#include "lib/framework.hpp"
#include "Title.h"
#include <iostream>

enum Window
{
	WIDTH = 512,
	HEIGHT = 512
};

enum
{
	TITLE,
	GAME,
	RESULT
};

int main()
{

	AppEnv env(Window::WIDTH, Window::HEIGHT);

	Font font("res/k.ttf");
	font.size(50);

	int n = 0;

	while (env.isOpen())
	{
		env.begin();

		n = changeScene(env, n);

		switch (n)
		{
		case TITLE:
			titleScene(env, font);
			break;

		case GAME:
			gameScene(env, font);
			break;

		case RESULT:
			resultScene(env, font);
			break;
		}

		env.end();
	}
}
