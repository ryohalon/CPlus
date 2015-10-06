#pragma once
#include "../Singleton/Singleton2.h"

enum SceneName
{
	TITLE,
	GAME,
};

/////////////////////////////////////////////////////////////////////////////////
//タイトル
/////////////////////////////////////////////////////////////////////////////////

class Title
{
private:

public:

	void update();
	void draw();
	SceneName shift();

};




/////////////////////////////////////////////////////////////////////////////////
//ゲーム
/////////////////////////////////////////////////////////////////////////////////

class Game
{
private:

public:

	void update();
	void draw();
	SceneName shift();

};