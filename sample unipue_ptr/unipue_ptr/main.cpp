#include <iostream>
#include <string>
//unique_ptr ���g������include
#include <memory>
#include "memory_from_storage.hpp"


int main()
{
	//unipue_ptr �̍쐬

	//�R���X�g���N�^�̈����Ƃ��ă������𓮓I�Ɋm��
	std::unique_ptr<int> u_ptr(new int(10));
	std::cout << "u_ptr = " << *u_ptr << std::endl;



	//reset�֐����g�����ƂŌォ��ł�����ł���
	std::unique_ptr<int> u_ptr2;
	u_ptr2.reset(new int(10));
	std::cout << "u_ptr2 = " << *u_ptr2 << std::endl;



	//make_unique<�^>(�l) �ł��ł���
	std::unique_ptr<int> u_ptr3 = std::make_unique<int>(10);
	std::cout << "u_ptr3 = " << *u_ptr3 << std::endl;



	std::unique_ptr<int> u_ptr4(new int(10));
	std::cout << "u_ptr4 = " << *u_ptr4 << std::endl;

	//�R�s�[�͂ł��Ȃ�
	std::unique_ptr<int>u_ptr5;
	//u_ptr5 = u_ptr4;  ==ERROR==

	//���[�u�R���X�g���N�^��A���[�u������Z�q�͂ł���
	//u_ptr4 �̏��L���� u_ptr6 �Ɉړ�
	std::unique_ptr<int>u_ptr6(std::move(u_ptr4));
	std::cout << "u_ptr6 = " << *u_ptr6 << std::endl;

	//u_ptr6 �̏��L���� u_ptr7 �Ɉړ�
	std::unique_ptr<int> u_ptr7;
	u_ptr7 = std::move(u_ptr6);
	std::cout << "u_ptr7 = " << *u_ptr7 << std::endl;

	{
		std::unique_ptr<int> u_ptr8(new int(10));
		std::cout << "u_ptr8 = " << *u_ptr8 << std::endl;
	}//�����Ńf�X�g���N�^���Ă΂ꎩ���I�ɊJ�������

	//����������Anullptr��������reset�֐��Ŗ����I�ɊJ�����ł���
	std::unique_ptr<int> u_ptr9(new int(10));
	std::cout << "u_ptr9 = " << *u_ptr9 << std::endl;
	u_ptr9.reset();

	std::unique_ptr<int> u_ptr10(new int(10));
	std::cout << "u_ptr10 = " << *u_ptr10 << std::endl;
	u_ptr10.reset(nullptr);

	std::unique_ptr<std::string> u_ptr12(new std::string("test"));
	//operator*() ��string�^���Q��
	std::cout << "u_ptr12 = " << *u_ptr12 << std::endl;
	//operator->() ��string�^��size�֐����Ăяo����
	unsigned int u_ptr12_size = u_ptr12->size();
	std::cout << "u_ptr12_size = " << u_ptr12_size << std::endl;

	std::unique_ptr<int> u_ptr13(new int(10));
	//�ʏ�̃|�C���^���ق����ꍇ��get()���g��
	//�|�C���^�̏��L���� u_ptr13 ���ێ���������
	int* u_p_int;
	u_p_int = u_ptr13.get();
	std::cout << "*u_p_int = " << *u_p_int << std::endl;

	//���L�����Ԃ��������ꍇ�́Arelease() ���g��
	//���̏ꍇ�A�������̊J�����͎̂����ōs���K�v������
	u_ptr13.release();

	{
		//unique_ptr ��z��Ő錾
		std::unique_ptr<int[]> u_ptr14(new int[10]);
		for (int i = 0; i < 10; i++)
		{
			u_ptr14[i] = i;

			std::cout << "u_ptr14 = " << u_ptr14[i] << std::endl;
		}
	}//�z��̏ꍇ�A�����I��delete[] ���Ă΂�ĊJ�������


	//��Q�����ŁAdeleter���w�肷��
	std::unique_ptr<int, deleter_for_storage> ptr(malloc_int_from_storage());
	//delete�ł͂Ȃ��Afree_int_from_storage() ���������J���̍ۂɌĂ΂��


	return  0;
}