#include "lib/framework.hpp"
#include "SingletonApp.h"
#include "Player.h"
#include <iostream>
#include <vector>







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
