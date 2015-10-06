#pragma once
#include "../lib/framework.hpp"
#include "../Scene/Scene.h"




/////////////////////////////////////////////////////////////////////////////////
//�V�[���}�l�[�W���[
/////////////////////////////////////////////////////////////////////////////////

class SceneManager
{
private:

	Title title;
	Game game;

	SceneName scene_number = TITLE;

public:

	void update();
	void draw();
	void shift();

};