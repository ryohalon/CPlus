#pragma once
#include <iostream>
#include <string>
#include <memory>



//int型のリソースをstorageから確保する
int* malloc_int_from_storage()
{
	int* p = new int(1);

	return p;
}

//int型のリソースをstorageから解放する
void free_int_from_storage(int* ptr)
{

}

//deleter
//メモリ解放時の処理を指定する、関数オブジェクトのことである
struct deleter_for_storage
{

	void operator()(int* ptr)
	{
		free_int_from_storage(ptr);
	}
};