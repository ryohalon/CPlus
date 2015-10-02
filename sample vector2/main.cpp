#include <iostream>
#include <vector>
#include <algorithm>

bool IsErase(const int& num)
{
	return ( (num % 2) == 0 );
}


int main()
{
	//i_vector�̍쐬
	std::vector<int> i_vector;
	std::cout << "i_vector���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	i_vector.push_back(1);
	i_vector.push_back(2);
	i_vector.push_back(3);
	i_vector.push_back(4);
	i_vector.push_back(5);
	i_vector.push_back(6);
	i_vector.push_back(7);
	i_vector.push_back(8);
	i_vector.push_back(9);

	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_vector�̒��g�ł�" << std::endl;
	for (auto i : i_vector)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//�����v�f���㑱�̗v�f�ŏ㏑�����邾��
	remove(i_vector.begin(), i_vector.end(), 5);

	//�\�����ʁ@1 2 3 4 6 7 8 9 9
	std::cout << "remove���܂���" << std::endl;
	for (auto i : i_vector)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_vector2�̍쐬
	std::vector<int> i_vector2;
	std::cout << "i_vector2���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	i_vector2.push_back(1);
	i_vector2.push_back(2);
	i_vector2.push_back(3);
	i_vector2.push_back(4);
	i_vector2.push_back(5);
	i_vector2.push_back(6);
	i_vector2.push_back(7);
	i_vector2.push_back(8);
	i_vector2.push_back(9);

	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_vector2�̒��g�ł�" << std::endl;
	for (auto i : i_vector2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// remove �͖߂�l�Ƃ��ď㏑����̏�ԂƂ��ėL���Ȕ͈̖͂�����Ԃ�
	std::vector<int>::iterator it2_end = remove(i_vector2.begin(), i_vector2.end(), 5);

	//�ŏ����l��
	std::vector<int>::iterator it2 = i_vector2.begin();

	//�L���Ȕ͈͂�i_vector2����
	//�\�����ʁ@1 2 3 4 6 7 8 9
	std::cout << "iterator�Ŋl�������͈͂ŉ񂵂܂�" << std::endl;
	while (it2 != it2_end)
	{
		std::cout << *it2 << " ";

		++it2;
	}
	std::cout << std::endl;

	//������S���̗v�f���񂷂Ƃ΂��
	//�\�����ʁ@1 2 3 4 6 7 8 9 9
	std::cout << "�������킯�ł͂Ȃ��̂ł��ׂĂ͈̔͂ŉ񂷂Ƃ΂�܂�" << std::endl;
	for (auto i : i_vector2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//i_vector3�̍쐬
	std::vector<int> i_vector3;
	std::cout << "i_vector3���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	//���̐����𕪂���₷�����邽��
	// 5��3�ɑ��₵�܂���
	i_vector3.push_back(1);
	i_vector3.push_back(2);
	i_vector3.push_back(3);
	i_vector3.push_back(4);
	i_vector3.push_back(5);
	i_vector3.push_back(5);
	i_vector3.push_back(5);
	i_vector3.push_back(6);
	i_vector3.push_back(7);
	i_vector3.push_back(8);
	i_vector3.push_back(9);

	//�\�����ʁ@1 2 3 4 5 5 5 6 7 8 9
	std::cout << "i_vector3�̒��g�ł�" << std::endl;
	for (auto i : i_vector3)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//�������ƈꏏ
	std::vector<int>::iterator it3_end = remove(i_vector3.begin(), i_vector3.end(), 5);

	//erase(x1, x2)��x1�`x2�̗v�f��{���̈Ӗ��ł̍폜������
	//���̏ꍇ�폜�����̂�
	//         it3_end    i_vector.end()
	//              �@���@ ��
	//1 2 3 4 6 7 8 9 9 9 9
	i_vector3.erase(it3_end, i_vector3.end());

	//������ꏏ
	std::vector<int>::iterator it3 = i_vector3.begin();

	//�\�����ʁ@1 2 3 4 6 7 8 9
	std::cout << "remove�������erase�����̂ł��ׂĉ񂵂Ă��΂�܂���" << std::endl;
	while (it3 != i_vector3.end())
	{
		std::cout << *it3 << " ";

		++it3;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_vector4�̍쐬
	std::vector<int> i_vector4;
	std::cout << "i_vector4���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	i_vector4.push_back(1);
	i_vector4.push_back(2);
	i_vector4.push_back(3);
	i_vector4.push_back(4);
	i_vector4.push_back(5);
	i_vector4.push_back(6);
	i_vector4.push_back(7);
	i_vector4.push_back(8);
	i_vector4.push_back(9);

	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_vector4�̒��g�ł�" << std::endl;
	for (auto it : i_vector4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//remove_if���g���Ă����@�ł�
	std::vector<int>::iterator it4_end = remove_if(i_vector4.begin(), i_vector4.end(), IsErase);
	//remove_if(x1, x2,�@������) �Ƃ�
	//x1�`x2�͈̔͂łR�ڂɎw�肵���������� true �̂Ƃ���
	//���̗v�f�� remove ����
	//������ remove ����̂Ŗ{���̈Ӗ��ł͍폜����܂���,�@�����ӂ�������

	//����č���� erase ���Ȃ��Ă͂����܂���
	i_vector4.erase(it4_end, i_vector4.end());

	//�O�ƈꏏ�ł�
	std::vector<int>::iterator it4 = i_vector4.begin();

	//�\�����ʁ@1 3 5 7 9
	std::cout << "�����erase���Ă�̂ō�����΂�܂���" << std::endl;
	while (it4 != i_vector4.end())
	{
		std::cout << *it4 << " ";

		++it4;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//i_vector5�̍쐬��i_vector6�̍쐬
	std::vector<int> i_vector5, i_vector6;
	std::cout << "i_vector5��i_veector6���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	i_vector5.push_back(1);
	i_vector5.push_back(2);
	i_vector5.push_back(3);
	i_vector5.push_back(4);
	i_vector5.push_back(5);
	i_vector5.push_back(6);
	i_vector5.push_back(7);
	i_vector5.push_back(8);
	i_vector5.push_back(9);

	//i_vecotr6��i_vector5�Ɠ����T�C�Y�ɕύX����
	i_vector6.resize(i_vector5.size());

	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_vector5�̒��g�ł�" << std::endl;
	for (auto i : i_vector5)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//�\�����ʁ@0 0 0 0 0 0 0 0 0
	std::cout << "i_vector6�̒��g�ł�" << std::endl;
	for (auto i : i_vector6)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//����� remove_copy ���g���܂�
	std::vector<int>::iterator it6_end = remove_copy(i_vector5.begin(), i_vector5.end(), i_vector6.begin(), 5);
	//remove_copy(x1, x2,�@�x�N�^�[.begin(), �l) �Ƃ�
	//remove�@�������̂�
	//�R�ڂɎw�肵���x�N�^�[�ɃR�s�[��
	//�߂�l�͍Ō�ɃR�s�[���ꂽ�v�f�ɂȂ�܂�

	//���������������x�N�^�[�ŏ��̎擾�ł�
	std::vector<int>::iterator it6 = i_vector6.begin();

	//�\�����ʁ@1 2 3 4 6 7 8 9
	std::cout << "remove_copy�ŃR�s����i_vector6�̒��g�ł�" << std::endl;
	while (it6 != it6_end)
	{
		std::cout << *it6 << " ";

		++it6;
	}
	std::cout << std::endl;

	//�\�����ʁ@1 2 3 4 6 7 8 9 0
	std::cout << "remove�̏���������i_vector5���R�s�����̂�i_vector6�̂��܂�͂��̂܂܂ł�" << std::endl;
	
	it6 = i_vector6.begin();

	while (it6 != i_vector6.end())
	{
		std::cout << *it6 << " ";

		++it6;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_vector7�̍쐬��i_vector8�̍쐬
	std::vector<int> i_vector7, i_vector8;
	std::cout << "i_vector7��i_veector8���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	i_vector7.push_back(1);
	i_vector7.push_back(2);
	i_vector7.push_back(3);
	i_vector7.push_back(4);
	i_vector7.push_back(5);
	i_vector7.push_back(6);
	i_vector7.push_back(7);
	i_vector7.push_back(8);
	i_vector7.push_back(9);

	//i_vecotr8��i_vector7�Ɠ����T�C�Y�ɕύX����
	i_vector8.resize(i_vector7.size());

	//�\�����ʁ@1 2 3 4 5 6 7 8 9
	std::cout << "i_vector7�̒��g�ł�" << std::endl;
	for (auto i : i_vector7)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//�\�����ʁ@0 0 0 0 0 0 0 0 0
	std::cout << "i_vector8�̒��g�ł�" << std::endl;
	for (auto i : i_vector8)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//����� remove_copy_if ���g���܂�
	std::vector<int>::iterator it8_end = remove_copy_if(i_vector7.begin(), i_vector7.end(), i_vector8.begin(), IsErase);
	//remove_copy_if(x1, x2,�@�x�N�^�[.begin(),������) �Ƃ�
	//remove_if�@�������̂�
	//�R�ڂɎw�肵���x�N�^�[�ɃR�s�[��
	//�߂�l�͍Ō�ɃR�s�[���ꂽ�v�f�̂ɂȂ�܂�

	//���������������x�N�^�[�ŏ��̎擾�ł�
	std::vector<int>::iterator it8 = i_vector8.begin();

	//�\�����ʁ@1 3 5 7 9
	std::cout << "remove_copy_if�ŃR�s����i_vector8�̒��g�ł�" << std::endl;
	while (it8 != it8_end)
	{
		std::cout << *it8 << " ";

		++it8;
	}
	std::cout << std::endl;

	//�\�����ʁ@1 3 5 7 9 0 0 0 0
	std::cout << "remove_if�̏���������i_vector7���R�s�����̂�i_vector8�̂��܂�͂��̂܂܂ł�" << std::endl;

	it8 = i_vector8.begin();

	while (it8 != i_vector8.end())
	{
		std::cout << *it8 << " ";

		++it8;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	
	//i_vector9�̍쐬
	std::vector<int> i_vector9;
	std::cout << "i_vector9���쐬���܂���" << std::endl;

	//�v�f�̒ǉ�
	i_vector9.push_back(1);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(5);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(9);

	//�\�����ʁ@1 2 2 2 5 7 7 7 9
	std::cout << "i_vector9�̒��g�ł�" << std::endl;
	for (auto it : i_vector9)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//unique���g���܂�
	std::vector<int>::iterator it9_end = unique(i_vector9.begin(), i_vector9.end());
	//unique(x1, x2)�@�Ƃ�
	//x1�`x2�̊Ԃɂ���v�f�ŘA�����ē����l�̂��̂���ɂ��Ă������̂ł�
	//������������ erase �ō폜���Ȃ���Ώ����Ȃ��ł�


	//���x���Ȃ��݂ł�
	std::vector<int>::iterator it9 = i_vector9.begin();

	//�\�����ʁ@1 2 5 7 9
	std::cout << "unique ���g����i_vector9�̒��g�ł�" << std::endl;
	while (it9 != it9_end)
	{
		std::cout << *it9 << " ";

		++it9;
	}
	std::cout << std::endl;

	//���ׂĂ̗v�f���폜���܂�
	i_vector9.erase(i_vector9.begin(), i_vector9.end());

	//����Ȃ����܂�
	i_vector9.push_back(1);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(5);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(9);

	//i_vector10�̍쐬
	std::vector<int> i_vector10;
	std::cout << "i_vector10���쐬���܂���" << std::endl;

	//i_vector10��i_vector9�̃T�C�Y���R�s�[
	i_vector10.resize(i_vector.size());

	//�\�����ʁ@1 2 2 2 5 7 7 7 9
	std::cout << "i_vector9�̒��g�ł�" << std::endl;
	 for (auto i : i_vector9)
	{
		std::cout << i << " ";
	}

	 //unique_copy���g���܂�
	 std::vector<int>::iterator it10_end = unique_copy(i_vector9.begin(), i_vector9.end(), i_vector10.begin());
	 //unique_copy �Ƃ�
	 //remove_copy�ƈꏏ��unique������ɃR�s�邾���ł�

	 //���x������ݍŏ��̗v�f�̎擾�ł�
	 std::vector<int>::iterator it10 = i_vector10.begin();

	 //�\�����ʁ@1 2 5 7 9
	 std::cout << "unique_copy��i_vector9���R�s����i_vector10�̒��g�ł�" << std::endl;
	 while (it10 != it10_end)
	 {
		 std::cout << *it10 << " ";

		 ++it10;
	 }
	 std::cout << std::endl;
	 std::cout << std::endl;
	 std::cout << std::endl;

	return 0;
}