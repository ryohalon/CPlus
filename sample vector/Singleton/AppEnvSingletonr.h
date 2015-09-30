#pragma once
#include "../lib/framework.hpp"

#define WIN_WIDTH (1024)
#define WIN_HEIGHT (1024)

class App
{
private:

public:

	static AppEnv& Get()
	{
		static AppEnv env(WIN_WIDTH, WIN_HEIGHT, false, true);

		return env;
	}

	
};