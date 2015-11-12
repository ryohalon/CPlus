#include <iostream>
#include <string>
//unique_ptr を使う時はinclude
#include <memory>
#include "memory_from_storage.hpp"


int main()
{
	//unipue_ptr の作成

	//コンストラクタの引数としてメモリを動的に確保
	std::unique_ptr<int> u_ptr(new int(10));
	std::cout << "u_ptr = " << *u_ptr << std::endl;



	//reset関数を使うことで後からでも代入できる
	std::unique_ptr<int> u_ptr2;
	u_ptr2.reset(new int(10));
	std::cout << "u_ptr2 = " << *u_ptr2 << std::endl;



	//make_unique<型>(値) でもできる
	std::unique_ptr<int> u_ptr3 = std::make_unique<int>(10);
	std::cout << "u_ptr3 = " << *u_ptr3 << std::endl;



	std::unique_ptr<int> u_ptr4(new int(10));
	std::cout << "u_ptr4 = " << *u_ptr4 << std::endl;

	//コピーはできない
	std::unique_ptr<int>u_ptr5;
	//u_ptr5 = u_ptr4;  ==ERROR==

	//ムーブコンストラクタや、ムーブ代入演算子はできる
	//u_ptr4 の所有権を u_ptr6 に移動
	std::unique_ptr<int>u_ptr6(std::move(u_ptr4));
	std::cout << "u_ptr6 = " << *u_ptr6 << std::endl;

	//u_ptr6 の所有権を u_ptr7 に移動
	std::unique_ptr<int> u_ptr7;
	u_ptr7 = std::move(u_ptr6);
	std::cout << "u_ptr7 = " << *u_ptr7 << std::endl;

	{
		std::unique_ptr<int> u_ptr8(new int(10));
		std::cout << "u_ptr8 = " << *u_ptr8 << std::endl;
	}//ここでデストラクタが呼ばれ自動的に開放される

	//引数無しや、nullptrが引数のreset関数で明示的に開放もできる
	std::unique_ptr<int> u_ptr9(new int(10));
	std::cout << "u_ptr9 = " << *u_ptr9 << std::endl;
	u_ptr9.reset();

	std::unique_ptr<int> u_ptr10(new int(10));
	std::cout << "u_ptr10 = " << *u_ptr10 << std::endl;
	u_ptr10.reset(nullptr);

	std::unique_ptr<std::string> u_ptr12(new std::string("test"));
	//operator*() でstring型を参照
	std::cout << "u_ptr12 = " << *u_ptr12 << std::endl;
	//operator->() でstring型のsize関数を呼び出せる
	unsigned int u_ptr12_size = u_ptr12->size();
	std::cout << "u_ptr12_size = " << u_ptr12_size << std::endl;

	std::unique_ptr<int> u_ptr13(new int(10));
	//通常のポインタがほしい場合はget()を使う
	//ポインタの所有権は u_ptr13 が保持し続ける
	int* u_p_int;
	u_p_int = u_ptr13.get();
	std::cout << "*u_p_int = " << *u_p_int << std::endl;

	//所有権事態を放棄する場合は、release() を使う
	//この場合、メモリの開放自体は自分で行う必要がある
	u_ptr13.release();

	{
		//unique_ptr を配列で宣言
		std::unique_ptr<int[]> u_ptr14(new int[10]);
		for (int i = 0; i < 10; i++)
		{
			u_ptr14[i] = i;

			std::cout << "u_ptr14 = " << u_ptr14[i] << std::endl;
		}
	}//配列の場合、自動的にdelete[] が呼ばれて開放される


	//第２引数で、deleterを指定する
	std::unique_ptr<int, deleter_for_storage> ptr(malloc_int_from_storage());
	//deleteではなく、free_int_from_storage() がメモリ開放の際に呼ばれる


	return  0;
}