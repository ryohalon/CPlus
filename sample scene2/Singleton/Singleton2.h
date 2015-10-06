#pragma once
#include "../lib/framework.hpp"

//新井さんver
//env → App::getInstance()

#define WIN_WIDTH (2048)
#define WIN_HEIGHT (1024)

class App
{
public:
	static AppEnv& getInstance()
	{
		static AppEnv instance(WIN_WIDTH, WIN_HEIGHT, false, true);
		return instance;
	}

private:
	//生成するときに1つだけにしたいので
	//コンストラクタはprivateで生成できないようにする
	App()
	{

	}

};