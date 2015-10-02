#include <iostream>
#include <vector>
#include <algorithm>

bool IsErase(const int& num)
{
	return ( (num % 2) == 0 );
}


int main()
{
	//i_vectorの作成
	std::vector<int> i_vector;
	std::cout << "i_vectorを作成しました" << std::endl;

	//要素の追加
	i_vector.push_back(1);
	i_vector.push_back(2);
	i_vector.push_back(3);
	i_vector.push_back(4);
	i_vector.push_back(5);
	i_vector.push_back(6);
	i_vector.push_back(7);
	i_vector.push_back(8);
	i_vector.push_back(9);

	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_vectorの中身です" << std::endl;
	for (auto i : i_vector)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//消す要素を後続の要素で上書きするだけ
	remove(i_vector.begin(), i_vector.end(), 5);

	//表示結果　1 2 3 4 6 7 8 9 9
	std::cout << "removeしました" << std::endl;
	for (auto i : i_vector)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_vector2の作成
	std::vector<int> i_vector2;
	std::cout << "i_vector2を作成しました" << std::endl;

	//要素の追加
	i_vector2.push_back(1);
	i_vector2.push_back(2);
	i_vector2.push_back(3);
	i_vector2.push_back(4);
	i_vector2.push_back(5);
	i_vector2.push_back(6);
	i_vector2.push_back(7);
	i_vector2.push_back(8);
	i_vector2.push_back(9);

	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_vector2の中身です" << std::endl;
	for (auto i : i_vector2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// remove は戻り値として上書き後の状態として有効な範囲の末尾を返す
	std::vector<int>::iterator it2_end = remove(i_vector2.begin(), i_vector2.end(), 5);

	//最初を獲得
	std::vector<int>::iterator it2 = i_vector2.begin();

	//有効な範囲でi_vector2を回す
	//表示結果　1 2 3 4 6 7 8 9
	std::cout << "iteratorで獲得した範囲で回します" << std::endl;
	while (it2 != it2_end)
	{
		std::cout << *it2 << " ";

		++it2;
	}
	std::cout << std::endl;

	//だから全部の要素を回すとばれる
	//表示結果　1 2 3 4 6 7 8 9 9
	std::cout << "消したわけではないのですべての範囲で回すとばれます" << std::endl;
	for (auto i : i_vector2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//i_vector3の作成
	std::vector<int> i_vector3;
	std::cout << "i_vector3を作成しました" << std::endl;

	//要素の追加
	//次の説明を分かりやすくするため
	// 5を3個に増やしました
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

	//表示結果　1 2 3 4 5 5 5 6 7 8 9
	std::cout << "i_vector3の中身です" << std::endl;
	for (auto i : i_vector3)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//さっきと一緒
	std::vector<int>::iterator it3_end = remove(i_vector3.begin(), i_vector3.end(), 5);

	//erase(x1, x2)はx1～x2の要素を本当の意味での削除をする
	//この場合削除されるのは
	//         it3_end    i_vector.end()
	//              　↓　 ↓
	//1 2 3 4 6 7 8 9 9 9 9
	i_vector3.erase(it3_end, i_vector3.end());

	//これも一緒
	std::vector<int>::iterator it3 = i_vector3.begin();

	//表示結果　1 2 3 4 6 7 8 9
	std::cout << "removeした後にeraseしたのですべて回してもばれません" << std::endl;
	while (it3 != i_vector3.end())
	{
		std::cout << *it3 << " ";

		++it3;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_vector4の作成
	std::vector<int> i_vector4;
	std::cout << "i_vector4を作成しました" << std::endl;

	//要素の追加
	i_vector4.push_back(1);
	i_vector4.push_back(2);
	i_vector4.push_back(3);
	i_vector4.push_back(4);
	i_vector4.push_back(5);
	i_vector4.push_back(6);
	i_vector4.push_back(7);
	i_vector4.push_back(8);
	i_vector4.push_back(9);

	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_vector4の中身です" << std::endl;
	for (auto it : i_vector4)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//remove_ifを使ってやる方法です
	std::vector<int>::iterator it4_end = remove_if(i_vector4.begin(), i_vector4.end(), IsErase);
	//remove_if(x1, x2,　条件式) とは
	//x1～x2の範囲で３個目に指定した条件式が true のときに
	//その要素を remove する
	//＊＊＊ remove するので本当の意味では削除されません,　ご注意を＊＊＊

	//よって今回も erase しなくてはいけません
	i_vector4.erase(it4_end, i_vector4.end());

	//前と一緒です
	std::vector<int>::iterator it4 = i_vector4.begin();

	//表示結果　1 3 5 7 9
	std::cout << "今回もeraseしてるので今回もばれません" << std::endl;
	while (it4 != i_vector4.end())
	{
		std::cout << *it4 << " ";

		++it4;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//i_vector5の作成とi_vector6の作成
	std::vector<int> i_vector5, i_vector6;
	std::cout << "i_vector5とi_veector6を作成しました" << std::endl;

	//要素の追加
	i_vector5.push_back(1);
	i_vector5.push_back(2);
	i_vector5.push_back(3);
	i_vector5.push_back(4);
	i_vector5.push_back(5);
	i_vector5.push_back(6);
	i_vector5.push_back(7);
	i_vector5.push_back(8);
	i_vector5.push_back(9);

	//i_vecotr6をi_vector5と同じサイズに変更する
	i_vector6.resize(i_vector5.size());

	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_vector5の中身です" << std::endl;
	for (auto i : i_vector5)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//表示結果　0 0 0 0 0 0 0 0 0
	std::cout << "i_vector6の中身です" << std::endl;
	for (auto i : i_vector6)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//今回は remove_copy を使います
	std::vector<int>::iterator it6_end = remove_copy(i_vector5.begin(), i_vector5.end(), i_vector6.begin(), 5);
	//remove_copy(x1, x2,　ベクター.begin(), 値) とは
	//remove　したものを
	//３個目に指定したベクターにコピーし
	//戻り値は最後にコピーされた要素になります

	//もう何回もやったベクター最初の取得です
	std::vector<int>::iterator it6 = i_vector6.begin();

	//表示結果　1 2 3 4 6 7 8 9
	std::cout << "remove_copyでコピったi_vector6の中身です" << std::endl;
	while (it6 != it6_end)
	{
		std::cout << *it6 << " ";

		++it6;
	}
	std::cout << std::endl;

	//表示結果　1 2 3 4 6 7 8 9 0
	std::cout << "removeの処理をしたi_vector5をコピったのでi_vector6のあまりはそのままです" << std::endl;
	
	it6 = i_vector6.begin();

	while (it6 != i_vector6.end())
	{
		std::cout << *it6 << " ";

		++it6;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	//i_vector7の作成とi_vector8の作成
	std::vector<int> i_vector7, i_vector8;
	std::cout << "i_vector7とi_veector8を作成しました" << std::endl;

	//要素の追加
	i_vector7.push_back(1);
	i_vector7.push_back(2);
	i_vector7.push_back(3);
	i_vector7.push_back(4);
	i_vector7.push_back(5);
	i_vector7.push_back(6);
	i_vector7.push_back(7);
	i_vector7.push_back(8);
	i_vector7.push_back(9);

	//i_vecotr8をi_vector7と同じサイズに変更する
	i_vector8.resize(i_vector7.size());

	//表示結果　1 2 3 4 5 6 7 8 9
	std::cout << "i_vector7の中身です" << std::endl;
	for (auto i : i_vector7)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//表示結果　0 0 0 0 0 0 0 0 0
	std::cout << "i_vector8の中身です" << std::endl;
	for (auto i : i_vector8)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//今回は remove_copy_if を使います
	std::vector<int>::iterator it8_end = remove_copy_if(i_vector7.begin(), i_vector7.end(), i_vector8.begin(), IsErase);
	//remove_copy_if(x1, x2,　ベクター.begin(),条件式) とは
	//remove_if　したものを
	//３個目に指定したベクターにコピーし
	//戻り値は最後にコピーされた要素のになります

	//もう何回もやったベクター最初の取得です
	std::vector<int>::iterator it8 = i_vector8.begin();

	//表示結果　1 3 5 7 9
	std::cout << "remove_copy_ifでコピったi_vector8の中身です" << std::endl;
	while (it8 != it8_end)
	{
		std::cout << *it8 << " ";

		++it8;
	}
	std::cout << std::endl;

	//表示結果　1 3 5 7 9 0 0 0 0
	std::cout << "remove_ifの処理をしたi_vector7をコピったのでi_vector8のあまりはそのままです" << std::endl;

	it8 = i_vector8.begin();

	while (it8 != i_vector8.end())
	{
		std::cout << *it8 << " ";

		++it8;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	
	//i_vector9の作成
	std::vector<int> i_vector9;
	std::cout << "i_vector9を作成しました" << std::endl;

	//要素の追加
	i_vector9.push_back(1);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(5);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(9);

	//表示結果　1 2 2 2 5 7 7 7 9
	std::cout << "i_vector9の中身です" << std::endl;
	for (auto it : i_vector9)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	//uniqueを使います
	std::vector<int>::iterator it9_end = unique(i_vector9.begin(), i_vector9.end());
	//unique(x1, x2)　とは
	//x1～x2の間にある要素で連続して同じ値のものを一つにしてくれるものです
	//＊＊＊こいつも erase で削除しなければ消えないです


	//毎度おなじみです
	std::vector<int>::iterator it9 = i_vector9.begin();

	//表示結果　1 2 5 7 9
	std::cout << "unique を使ったi_vector9の中身です" << std::endl;
	while (it9 != it9_end)
	{
		std::cout << *it9 << " ";

		++it9;
	}
	std::cout << std::endl;

	//すべての要素を削除します
	i_vector9.erase(i_vector9.begin(), i_vector9.end());

	//入れなおします
	i_vector9.push_back(1);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(2);
	i_vector9.push_back(5);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(7);
	i_vector9.push_back(9);

	//i_vector10の作成
	std::vector<int> i_vector10;
	std::cout << "i_vector10を作成しました" << std::endl;

	//i_vector10にi_vector9のサイズをコピー
	i_vector10.resize(i_vector.size());

	//表示結果　1 2 2 2 5 7 7 7 9
	std::cout << "i_vector9の中身です" << std::endl;
	 for (auto i : i_vector9)
	{
		std::cout << i << " ";
	}

	 //unique_copyを使います
	 std::vector<int>::iterator it10_end = unique_copy(i_vector9.begin(), i_vector9.end(), i_vector10.begin());
	 //unique_copy とは
	 //remove_copyと一緒でuniqueした後にコピるだけです

	 //毎度お馴染み最初の要素の取得です
	 std::vector<int>::iterator it10 = i_vector10.begin();

	 //表示結果　1 2 5 7 9
	 std::cout << "unique_copyでi_vector9をコピったi_vector10の中身です" << std::endl;
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