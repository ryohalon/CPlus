#pragma once
#include <iostream>
#include <string>
#include <memory>



//int�^�̃��\�[�X��storage����m�ۂ���
int* malloc_int_from_storage()
{
	int* p = new int(1);

	return p;
}

//int�^�̃��\�[�X��storage����������
void free_int_from_storage(int* ptr)
{

}

//deleter
//������������̏������w�肷��A�֐��I�u�W�F�N�g�̂��Ƃł���
struct deleter_for_storage
{

	void operator()(int* ptr)
	{
		free_int_from_storage(ptr);
	}
};