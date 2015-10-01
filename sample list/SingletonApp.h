#pragma once
#include "lib/framework.hpp"

#define WIDTH (1024)
#define HEIGHT (1024)

class App
{
private:

public:

	static AppEnv& App::Get()
	{
		static AppEnv env(WIDTH, HEIGHT, false, true);

		return env;
	}
};