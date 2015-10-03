#include <iostream>
#include <algorithm>
#include <list>
#include <functional>


bool IsErase(const int& num)
{
	return (num % 2) == 0;
}

int main()
{
	//�錾�̎d��
	std::list<int> i_list;

	//list�ɗv�f��ǉ����܂�
	// 1
	i_list.push_back(1);
	// 1 2
	i_list.push_back(2);
	// 1 2 3
	i_list.push_back(3);
	// 1 2 3 4
	i_list.push_back(4);
	//�ȉ�����
	i_list.push_back(5);
	i_list.push_back(6);
	i_list.push_back(7);
	i_list.push_back(8);
	i_list.push_back(9);
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_list���쐬���܂���\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//list�̖����̗v�f�������܂�
	i_list.pop_back();
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8
	std::cout << "i_list �� pop_back() ���g�p���܂���\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//list�̍ŏ��̗v�f�������܂�
	i_list.pop_front();
	//�񂵂܂�
	//�\�����ʁ@2 3 4 5 6 7 8
	std::cout << "i_list �� pop_front() ���g�p���܂���\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//�v�f�̍ŏ��ɒǉ����܂�
	i_list.push_front(1);
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8
	std::cout << "i_list �� push_front(1) ���g�p���܂���\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//�v�f�̖����ɒǉ����܂�
	i_list.push_back(9);
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_list �� push_back(9) ���g�p���܂���\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//remove���g���A5�������܂�
	i_list.remove(5);
	//remove(�l) �Ƃ́H
	//�v�f�̒�����(�l)�Ɠ������̂������܂�
	//vector�ƈႢ
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 6 7 8 9
	std::cout << "i_list �� remove(5) ���g�p���܂���\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list2���쐬�A�v�f��ǉ����܂�
	std::list<int> i_list2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_list2 ���쐬���܂���\n";
	for (auto it : i_list2)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//remove_if���g���܂�
	i_list2.remove_if(IsErase);
	//reomve_if(�֐�)�Ƃ�
	//�֐���true�̂Ƃ��ɗv�f�������܂�
	//�񂵂܂�
	//�\�����ʁ@1 3 5 7 9
	std::cout << "i_list2 �� remove_if(IsErase) ���g�p���܂���\n";
	for (auto it : i_list2)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//clear()���g���܂�
	i_list2.clear();
	//clear()�Ƃ�
	//list�̂��ׂĂ̗v�f�������܂�
	//�񂵂܂�
	//�\�����ʁ@�Ȃ�
	std::cout << "i_list2 �� clear() ���g�p���܂���\n";
	if (i_list2.empty())
	{
		std::cout << "�v�f���Ȃ��ł���i�΁j\n";
	}
	else
	{
		for (auto it : i_list2)
		{
			std::cout << it << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list3�̍쐬
	std::list<int> i_list3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_list3 ���쐬���܂���\n";
	for (auto it : i_list3)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//i_list3�̃C�e���[�^���쐬���A�ŏ��̃C�e���[�^�������܂���
	std::list<int>::iterator it3_begin = i_list3.begin();
	//erase()���g���܂�
	i_list3.erase(it3_begin);
	//erase() �Ƃ�
	// () �̒��ɂ͈������P���A�Q�w��ł��܂�
	//�������P�̏ꍇ�A���̃C�e���[�^���w���v�f�����������܂�
	//�������Q�̏ꍇ�A�����Q�̃C�e���[�^���w���v�f�Ԃɂ��邷�ׂĂ̗v�f���܂Ƃ߂ď����܂�
	//�v����ɔ͈͎w��ł�
	//�񂵂܂�
	//�\�����ʁ@2 3 4 5 6 7 8 9
	std::cout << "i_list3 �� erase(it3_begin) ���g�p���܂���\n";
	for (auto it : i_list3)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//�ŏ��̃C�e���[�^�����������܂�
	it3_begin = i_list3.begin();
	std::list<int>::iterator it3_3 = i_list3.begin();
	//advance()���g���܂�
	std::advance(it3_3, 3);
	//advance(�C�e���[�^, �l) �Ƃ�
	//�w�肵�� �C�e���[�^ �� �l �̕��������炷���̂ł�
	//erase()���g���܂�
	i_list3.erase(it3_begin, it3_3);
	//�������Q�w�肵�܂���
	//�͈͍͂ŏ�����3�܂łɂȂ�܂�
	//�񂵂܂�
	//�\�����ʁ@�Ȃ�
	std::cout << "i_list3 �� erase(it3_begin, it3_3) ���g�p���܂���\n";
	if (i_list3.empty())
	{
		std::cout << "�v�f���Ȃ��ł���i�΁j\n";
	}
	else
	{
		for (auto it : i_list3)
		{
			std::cout << it << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_list4���쐬���܂�
	std::list<int> i_list4 = { 1, 2, 3, 4, 5 };
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5
	std::cout << "i_list4 ���쐬���܂���\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	i_list4.sort(std::greater<int>());
	//�񂵂܂�
	//�\�����ʁ@5 4 3 2 1
	std::cout << "i_list4 �� sort() ���g���܂���\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	i_list4.sort();
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5
	std::cout << "i_list4 �� sort() ���g���܂���\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//i_list5���쐬���܂�
	std::list<int> i_list5 = { 6, 7, 8, 9};
	//�񂵂܂�
	//�\�����ʁ@6 7 8 9
	std::cout << "i_list5 ���쐬���܂���\n";
	for (auto it : i_list5)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//merge()���g���܂�
	i_list4.merge(i_list5);
	//merge() �Ƃ�
	// () �̒��Ɏw�肵�� list ���Ăяo�����ɘA�����܂�
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_list4 �� merge(i_list5) ���g���܂���\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list6���쐬���܂���
	std::list<int> i_list6;
	std::cout << "i_list6���쐬���܂���\n";
	//assign()���g���܂�
	i_list6.assign(5, 1);
	//�񂵂܂�
	//�\�����ʁ@1 1 1 1 1
	std::cout << "i_list6 �� assign(5, 1) ���g���܂���\n";
	for (auto it : i_list6)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list7, i_list8���쐬���܂���
	std::list<int> i_list7 = { 1, 2, 3, 4, 5 };
	std::list<int> i_list8 = { 0, 0, 0 };
	//�񂵂܂�
	//�\�����ʁ@1 2 3 4 5
	std::cout << "i_list7���쐬���܂���\n";
	for (auto it : i_list7)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//�񂵂܂�
	//�\�����ʁ@0 0 0
	std::cout << "i_list8���쐬���܂���\n";
	for (auto it : i_list8)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;



	//�C�e���[�^���쐬���܂�
	std::list<int>::iterator it7 = i_list7.begin();
	//advance()�ł��炵�܂�
	std::advance(it7, 2);
	//splice()���g���܂�
	i_list7.splice(it7, i_list8);
	//splice(�C�e���[�^, ���X�g) �Ƃ�
	//�C�e���[�^�̎w���ʒu���玟�̗v�f�̊ԂɎw�肵�����X�g���ړ������邱�Ƃ��ł���
	//�񂵂܂�
	//�\�����ʁ@1 2 0 0 0 3 4 5
	std::cout << "i_list7 �� splice(it7, i_list8) ���g���܂���\n";
	for(auto it : i_list7)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//�񂵂܂�
	//�\�����ʁ@�Ȃ�
	std::cout << "i_list8 �͒��g�� i_list7 �Ɉړ��������̂ŃJ���ł�\n";
	if (i_list8.empty())
	{
		std::cout << "�v�f���Ȃ��ł���i�΁j\n";
	}
	else
	{
		for (auto it : i_list8)
		{
			std::cout << it << " ";
		}
	}
	std::cout << std::endl;

	return 0;
}