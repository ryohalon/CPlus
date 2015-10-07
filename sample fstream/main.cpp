#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//テキスト作成
	std::ofstream ofs;
	ofs.open("res/test.txt");
	//文字を入力
	ofs << "testmessage" << 123 << std::endl;
	ofs.close();

	//テキスト作成
	ofs.open("res/test2.txt");
	//文字を入力
	ofs << "testmessage" << 123 << std::endl;
	ofs << "testmessage" << 123 << std::endl;
	ofs.close();

	//追加で書き込みをします
	ofs.open("res/test.txt", std::ios::out | std::ios::app);
	ofs << "追加で書き込みました\n";
	ofs.close();

	//追加で書き込みをします
	ofs.open("res/test.txt", std::ios::out | std::ios::ate);
	ofs << "追加で書き込みました\n";
	ofs.close();

	//以前書いた内容を消して書き込みをします
	ofs.open("res/test.txt", std::ios::out | std::ios::trunc);
	ofs << "追加で書き込みました\n";
	ofs.close();

	//普段改行する文字も書き出します
	ofs.open("res/test.txt", std::ios::out | std::ios::binary);
	ofs << "改行の特殊文字を書いても改行しなくなります \n";
	ofs << "改行の特殊文字を書いても改行しなくなります \n";
	ofs.close();

	//テキストの作成
	ofs.open("res/test3.txt");
	for (int i = 1; i < 51; ++i)
	{
		ofs << i << " ";
	}

	ofs.seekp(std::ios::cur);
	ofs << "書き込み(cur)\n";

	ofs.seekp(std::ios::beg);
	ofs << "書き込み(beg)\n";

	ofs.seekp(std::ios::end);
	ofs << "書き込み(end)\n";

	ofs.seekp(15, std::ios::beg);
	ofs << "書き込み(15, beg)\n";

	std::ifstream ifs("res/test3.txt");
	std::string str[55];

	for (int i = 0; i < 55; ++i)
	ifs >> str[i];
	for (int i = 0; i < 55; ++i)
		std::cout << str[i];

	char ch;
	while (ifs.get(ch))
		std::cout << ch;
	ifs.close();


	return 0;
}