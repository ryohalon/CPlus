#include "lib/framework.hpp"
#include "Bullet/Bullet.h"
#include "Player/Player.h"
#include "Singleton/AppEnvSingletonr.h"
#include <iostream>


int main()
{
	Player player;

	while (App::Get().isOpen())
	{
		player.UpDate();

		App::Get().begin();

		player.Draw();

		App::Get().end();
	}
}
