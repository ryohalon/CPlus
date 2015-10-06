#pragma once
#include "../lib/framework.hpp"

//�V�䂳��ver
//env �� App::getInstance()

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
	//��������Ƃ���1�����ɂ������̂�
	//�R���X�g���N�^��private�Ő����ł��Ȃ��悤�ɂ���
	App()
	{

	}

};