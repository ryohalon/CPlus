#include <iostream>

//クラスの作成
class Point
{
private:

	int x, y;

public:

	//コンストラクタ
	Point(int, int);

	//オペレータ ＋演算子
	//　Point型 + Point型
	Point operator+(Point);

	//オペレータ ＋演算子
	// point型 + int型
	friend Point operator+(Point, int);

	//オペレータ 前置++演算子
	// ++Point型;
	Point operator++();

	//オペレータ 後置++演算子
	// Point型++
	Point operator++(int);

	//オペレータ +=演算子
	// Point型 += Point型
	void operator+=(Point);

	//オペレータ ==演算子
	// Point型 == Point型
	bool operator==(Point);

	//出力するために作った関数
	void Draw();
};


//コンストラクタ
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

//***********************************
//オペレータの内容の記述
//***********************************

Point Point::operator+(Point p)
{
	std::cout << "Point + Point を行います\n";

	Point tmp(0, 0);

	tmp.x = x + p.x;
	tmp.y = y + p.y;

	return tmp;
}


Point operator+(Point p, int num)
{
	std::cout << "Point + int を行います\n";

	Point tmp(0, 0);

	tmp.x = num + p.x;
	tmp.y = num + p.y;

	return tmp;
}


Point Point::operator++()
{
	std::cout << "++Point を行います\n";

	x++;
	y++;

	return *this;
}


Point Point::operator++(int d)
{
	std::cout << "Point++ を行います\n";

	Point p(0, 0);
	p = *this;

	x++;
	y++;

	return p;
}


void Point::operator+=(Point p)
{
	std::cout << "Point += Point を行います\n";

	Point tmp(0, 0);

	x += p.x;
	y += p.y;
}


bool Point::operator==(Point p)
{
	std::cout << "Point == Point を行います\n";

	if (x == p.x)
	{
		if (y == p.y)
			return true;
		else
			return false;
	}
	
	return false;
}


//出力する関数
void Point::Draw()
{
	std::cout << '(' << x << ',' << y << ")\n";
}


int main()
{
	//p1 の作成
	Point p1(1, 5);
	p1.Draw();

	//p2 の作成
	Point p2(3, 2);
	p2.Draw();

	//足し算 Point型 + Point型
	p1 = p1 + p2;
	p1.Draw();

	//足し算 Point型 + int型
	p1 = p1 + 10;
	p1.Draw();

	//前置インクリメント ++Point型
	++p1;
	p1.Draw();

	//後置インクリメント Point型++
	p2 = p1++;
	p1.Draw();
	p2.Draw();

	//足し算と代入 Point型 += Point型
	p1 += p2;
	p1.Draw();


	bool flag;
	//比較計算 Point型 == Point型
	flag = p1 == p2;
	std::cout << flag << std::endl;

	p2 = ++p1;
	flag = p1 == p2;
	std::cout << flag << std::endl;

	return 0;
}