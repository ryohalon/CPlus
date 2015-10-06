#include "lib/framework.hpp"
//#include "Singleton/Singleton.h"
#include "Singleton/Singleton2.h"
#include "SceneManager/SceneManager.h"
#include "Scene/Scene.h"
#include <iostream>



int main()
{
	SceneManager scene;

	while (App::getInstance().isOpen())
	{
		scene.update();

		scene.shift();

		App::getInstance().begin();

		scene.draw();

		App::getInstance().end();
	}
}
