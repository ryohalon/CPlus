#include "SceneManager.h"

void SceneManager::update()
{
	switch (scene_number)
	{
	case TITLE:

		title.update();
		break;

	case GAME:

		game.update();
		break;

	}
}

void SceneManager::draw()
{
	switch (scene_number)
	{
	case TITLE:

		title.draw();
		break;

	case GAME:

		game.draw();
		break;

	}
}

void SceneManager::shift()
{
	switch (scene_number)
	{
	case TITLE:

		scene_number = title.shift();
		break;

	case GAME:

		scene_number = game.shift();
		break;

	}
}