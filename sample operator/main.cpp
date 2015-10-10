#include <iostream>

//�N���X�̍쐬
class Point
{
private:

	int x, y;

public:

	//�R���X�g���N�^
	Point(int, int);

	//�I�y���[�^ �{���Z�q
	//�@Point�^ + Point�^
	Point operator+(Point);

	//�I�y���[�^ �{���Z�q
	// point�^ + int�^
	friend Point operator+(Point, int);

	//�I�y���[�^ �O�u++���Z�q
	// ++Point�^;
	Point operator++();

	//�I�y���[�^ ��u++���Z�q
	// Point�^++
	Point operator++(int);

	//�I�y���[�^ +=���Z�q
	// Point�^ += Point�^
	void operator+=(Point);

	//�I�y���[�^ ==���Z�q
	// Point�^ == Point�^
	bool operator==(Point);

	//�o�͂��邽�߂ɍ�����֐�
	void Draw();
};


//�R���X�g���N�^
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

//***********************************
//�I�y���[�^�̓��e�̋L�q
//***********************************

Point Point::operator+(Point p)
{
	std::cout << "Point + Point ���s���܂�\n";

	Point tmp(0, 0);

	tmp.x = x + p.x;
	tmp.y = y + p.y;

	return tmp;
}


Point operator+(Point p, int num)
{
	std::cout << "Point + int ���s���܂�\n";

	Point tmp(0, 0);

	tmp.x = num + p.x;
	tmp.y = num + p.y;

	return tmp;
}


Point Point::operator++()
{
	std::cout << "++Point ���s���܂�\n";

	x++;
	y++;

	return *this;
}


Point Point::operator++(int d)
{
	std::cout << "Point++ ���s���܂�\n";

	Point p(0, 0);
	p = *this;

	x++;
	y++;

	return p;
}


void Point::operator+=(Point p)
{
	std::cout << "Point += Point ���s���܂�\n";

	Point tmp(0, 0);

	x += p.x;
	y += p.y;
}


bool Point::operator==(Point p)
{
	std::cout << "Point == Point ���s���܂�\n";

	if (x == p.x)
	{
		if (y == p.y)
			return true;
		else
			return false;
	}
	
	return false;
}


//�o�͂���֐�
void Point::Draw()
{
	std::cout << '(' << x << ',' << y << ")\n";
}


int main()
{
	//p1 �̍쐬
	Point p1(1, 5);
	p1.Draw();

	//p2 �̍쐬
	Point p2(3, 2);
	p2.Draw();

	//�����Z Point�^ + Point�^
	p1 = p1 + p2;
	p1.Draw();

	//�����Z Point�^ + int�^
	p1 = p1 + 10;
	p1.Draw();

	//�O�u�C���N�������g ++Point�^
	++p1;
	p1.Draw();

	//��u�C���N�������g Point�^++
	p2 = p1++;
	p1.Draw();
	p2.Draw();

	//�����Z�Ƒ�� Point�^ += Point�^
	p1 += p2;
	p1.Draw();


	bool flag;
	//��r�v�Z Point�^ == Point�^
	flag = p1 == p2;
	std::cout << flag << std::endl;

	p2 = ++p1;
	flag = p1 == p2;
	std::cout << flag << std::endl;

	return 0;
}