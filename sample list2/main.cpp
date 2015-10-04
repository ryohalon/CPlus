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
	//宣言の仕方
	std::list<int> i_list;

	//listに要素を追加します
	// 1
	i_list.push_back(1);
	// 1 2
	i_list.push_back(2);
	// 1 2 3
	i_list.push_back(3);
	// 1 2 3 4
	i_list.push_back(4);
	//以下同文
	i_list.push_back(5);
	i_list.push_back(6);
	i_list.push_back(7);
	i_list.push_back(8);
	i_list.push_back(9);
	//回します
	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_listを作成しました\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//listの末尾の要素を消します
	i_list.pop_back();
	//回します
	//表示結果　1 2 3 4 5 6 7 8
	std::cout << "i_list を pop_back() を使用しました\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//listの最初の要素を消します
	i_list.pop_front();
	//回します
	//表示結果　2 3 4 5 6 7 8
	std::cout << "i_list を pop_front() を使用しました\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//要素の最初に追加します
	i_list.push_front(1);
	//回します
	//表示結果　1 2 3 4 5 6 7 8
	std::cout << "i_list を push_front(1) を使用しました\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//要素の末尾に追加します
	i_list.push_back(9);
	//回します
	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_list を push_back(9) を使用しました\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//removeを使い、5を消します
	i_list.remove(5);
	//remove(値) とは？
	//要素の中から(値)と同じものを消します
	//vectorと違い
	//回します
	//表示結果　1 2 3 4 6 7 8 9
	std::cout << "i_list を remove(5) を使用しました\n";
	for (auto it : i_list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list2を作成、要素を追加します
	std::list<int> i_list2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//回します
	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_list2 を作成しました\n";
	for (auto it : i_list2)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//remove_ifを使います
	i_list2.remove_if(IsErase);
	//reomve_if(関数)とは
	//関数がtrueのときに要素を消します
	//回します
	//表示結果　1 3 5 7 9
	std::cout << "i_list2 を remove_if(IsErase) を使用しました\n";
	for (auto it : i_list2)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//clear()を使います
	i_list2.clear();
	//clear()とは
	//listのすべての要素を消します
	//回します
	//表示結果　なし
	std::cout << "i_list2 を clear() を使用しました\n";
	if (i_list2.empty())
	{
		std::cout << "要素がないですよ（笑）\n";
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



	//i_list3の作成
	std::list<int> i_list3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//回します
	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_list3 を作成しました\n";
	for (auto it : i_list3)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//i_list3のイテレータを作成し、最初のイテレータを代入しました
	std::list<int>::iterator it3_begin = i_list3.begin();
	//erase()を使います
	i_list3.erase(it3_begin);
	//erase() とは
	// () の中には引数を１個か、２個指定できます
	//引数が１個の場合、そのイテレータが指す要素だけを消します
	//引数が２個の場合、それら２個のイテレータが指す要素間にあるすべての要素をまとめて消します
	//要するに範囲指定です
	//回します
	//表示結果　2 3 4 5 6 7 8 9
	std::cout << "i_list3 を erase(it3_begin) を使用しました\n";
	for (auto it : i_list3)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//最初のイテレータを代入し直します
	it3_begin = i_list3.begin();
	std::list<int>::iterator it3_3 = i_list3.begin();
	//advance()を使います
	std::advance(it3_3, 3);
	//advance(イテレータ, 値) とは
	//指定した イテレータ を 値 の分だけずらすものです
	//erase()を使います
	i_list3.erase(it3_begin, it3_3);
	//引数を２個指定しました
	//範囲は最初から3までになります
	//回します
	//表示結果　なし
	std::cout << "i_list3 を erase(it3_begin, it3_3) を使用しました\n";
	if (i_list3.empty())
	{
		std::cout << "要素がないですよ（笑）\n";
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


	//i_list4を作成します
	std::list<int> i_list4 = { 1, 2, 3, 4, 5 };
	//回します
	//表示結果　1 2 3 4 5
	std::cout << "i_list4 を作成しました\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	i_list4.sort(std::greater<int>());
	//回します
	//表示結果　5 4 3 2 1
	std::cout << "i_list4 に sort() を使いました\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	i_list4.sort();
	//回します
	//表示結果　1 2 3 4 5
	std::cout << "i_list4 に sort() を使いました\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//i_list5を作成します
	std::list<int> i_list5 = { 6, 7, 8, 9};
	//回します
	//表示結果　6 7 8 9
	std::cout << "i_list5 を作成しました\n";
	for (auto it : i_list5)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//merge()を使います
	i_list4.merge(i_list5);
	//merge() とは
	// () の中に指定した list を呼び出し元に連結します
	//回します
	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_list4 に merge(i_list5) を使いました\n";
	for (auto it : i_list4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list6を作成しました
	std::list<int> i_list6;
	std::cout << "i_list6を作成しました\n";
	//assign()を使います
	i_list6.assign(5, 1);
	//回します
	//表示結果　1 1 1 1 1
	std::cout << "i_list6 に assign(5, 1) を使いました\n";
	for (auto it : i_list6)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//assign()を使います
	i_list6.assign(5, 2);
	//回します
	//表示結果　2 2 2 2 2
	std::cout << "i_list6 に assign(5, 2) を使いました\n";
	for (auto it : i_list6)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//reverse() を使います
	i_list6.reverse();
	//reverse() とは
	//要素の並びを反転させます
	//回します
	//表示結果　2 2 2 2 2 1 1 1 1 1
	std::cout << "i_list6 に reverse() を使いました\n";
	for (auto it : i_list6)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



	//i_list7, i_list8を作成しました
	std::list<int> i_list7 = { 1, 2, 3, 4, 5 };
	std::list<int> i_list8 = { 0, 0, 0 };
	//回します
	//表示結果　1 2 3 4 5
	std::cout << "i_list7を作成しました\n";
	for (auto it : i_list7)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//回します
	//表示結果　0 0 0
	std::cout << "i_list8を作成しました\n";
	for (auto it : i_list8)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;



	//イテレータを作成します
	std::list<int>::iterator it7 = i_list7.begin();
	//advance()でずらします
	std::advance(it7, 2);
	//splice()を使います
	i_list7.splice(it7, i_list8);
	//splice(イテレータ, リスト) とは
	//イテレータの指す位置から次の要素の間に指定したリストを移動させることができる
	//回します
	//表示結果　1 2 0 0 0 3 4 5
	std::cout << "i_list7 に splice(it7, i_list8) を使いました\n";
	for(auto it : i_list7)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//回します
	//表示結果　なし
	std::cout << "i_list8 は中身を i_list7 に移動させたのでカラです\n";
	if (i_list8.empty())
	{
		std::cout << "要素がないですよ（笑）\n";
	}
	else
	{
		for (auto it : i_list8)
		{
			std::cout << it << " ";
		}
	}
	std::cout << std::endl;


	//要素を追加します
	i_list8.push_back(7);
	i_list8.push_back(8);
	i_list8.push_back(9);
	//advance()でずらします
	std::advance(it7, -2);
	//splice()を使います
	i_list7.splice(it7, i_list8, i_list8.begin());
	//splice(イテレータ1, リスト, イテレータ2) とは
	//イテレータ1の指す位置から次の要素の間に指定したリストのイテレータ2の指す要素を移動させることができる
	//回します
	//表示結果　1 2 0 7 0 0 3 4 5
	std::cout << "i_list7 に splice(it7, i_list8, i_list8.begin()) を使いました\n";
	for (auto it : i_list7)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//回します
	//表示結果　8 9
	std::cout << "i_list8 は i_list7 に 7 を移動させたので 8 9 しかないですです\n";
	if (i_list8.empty())
	{
		std::cout << "要素がないですよ（笑）\n";
	}
	else
	{
		for (auto it : i_list8)
		{
			std::cout << it << " ";
		}
	}
	std::cout << std::endl;


	//要素を追加します
	i_list8.push_front(7);
	i_list8.push_back(10);
	//advance()を使います
	std::list<int>::iterator it8 = i_list8.begin();
	std::advance(it7, 1);
	std::advance(it8, 2);
	//splice()を使います
	i_list7.splice(it7, i_list8, i_list8.begin(), it8);
	//splice(イテレータ1, リスト, イテレータ2, イテレータ3) とは
	//イテレータ1の指す位置から次の要素の間に指定したリストのイテレータ2からイテレータ3の間の要素を移動させることができる
	//回します
	//表示結果　1 2 0 7 0 0 3 4 5
	std::cout << "i_list7 に splice(it7, i_list8, i_list8.begin(), it8) を使いました\n";
	for (auto it : i_list7)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//回します
	//表示結果　8 9
	std::cout << "i_list8 は i_list7 に 7 8 を移動させたので 9 10 しかないですです\n";
	if (i_list8.empty())
	{
		std::cout << "要素がないですよ（笑）\n";
	}
	else
	{
		for (auto it : i_list8)
		{
			std::cout << it << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	
	//i_list9, i_list10を作成しました
	std::list<int> i_list9 = { 1, 2, 3 };
	std::list<int> i_list10 = { 1, 1, 1 };
	//回します
	//表示結果　1 2 3
	std::cout << "i_list9を作成しました\n";
	for (auto it : i_list9)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//回します
	//表示結果　1 1 1
	std::cout << "i_list10を作成しました\n";
	for (auto it : i_list10)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//insert() を使います
	i_list9.insert(i_list9.begin(), 0);
	//insert(イテレータ, 値) とは
	//指定した場所から値を挿入します
	//回します
	//表示結果　0 1 2 3
	std::cout << "i_list9 に insert(i_list9, 0) を使用しました\n";
	for (auto it : i_list9)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//insert() を使います
	i_list9.insert(i_list9.begin(), 3, 9);
	//insert(イテレータ, 値1, 値2) とは
	//指定した場所から値2を値1の数だけ挿入します
	//回します
	//表示結果　9 9 9 0 1 2 3
	std::cout << "i_list9 に insert(i_list9, 3, 9) を使用しました\n";
	for (auto it : i_list9)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;


	//insert() を使います
	i_list9.insert(i_list9.end(), i_list10.begin(), i_list10.end());
	//insert(イテレータ, 値1, 値2) とは
	//指定した場所から値1を値2の範囲にある要素を挿入します
	//回します
	//表示結果　9 9 9 0 1 2 3
	std::cout << "i_list9 に insert(i_list9, i_list10.begin(), i_list10.end()) を使用しました\n";
	for (auto it : i_list9)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	return 0;
}