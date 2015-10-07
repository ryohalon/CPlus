#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//�e�L�X�g�쐬
	std::ofstream ofs;
	ofs.open("res/test.txt");
	//���������
	ofs << "testmessage" << 123 << std::endl;
	ofs.close();

	//�e�L�X�g�쐬
	ofs.open("res/test2.txt");
	//���������
	ofs << "testmessage" << 123 << std::endl;
	ofs << "testmessage" << 123 << std::endl;
	ofs.close();

	//�ǉ��ŏ������݂����܂�
	ofs.open("res/test.txt", std::ios::out | std::ios::app);
	ofs << "�ǉ��ŏ������݂܂���\n";
	ofs.close();

	//�ǉ��ŏ������݂����܂�
	ofs.open("res/test.txt", std::ios::out | std::ios::ate);
	ofs << "�ǉ��ŏ������݂܂���\n";
	ofs.close();

	//�ȑO���������e�������ď������݂����܂�
	ofs.open("res/test.txt", std::ios::out | std::ios::trunc);
	ofs << "�ǉ��ŏ������݂܂���\n";
	ofs.close();

	//���i���s���镶���������o���܂�
	ofs.open("res/test.txt", std::ios::out | std::ios::binary);
	ofs << "���s�̓��ꕶ���������Ă����s���Ȃ��Ȃ�܂� \n";
	ofs << "���s�̓��ꕶ���������Ă����s���Ȃ��Ȃ�܂� \n";
	ofs.close();

	//�e�L�X�g�̍쐬
	ofs.open("res/test3.txt");
	for (int i = 1; i < 51; ++i)
	{
		ofs << i << " ";
	}

	ofs.seekp(std::ios::cur);
	ofs << "��������(cur)\n";

	ofs.seekp(std::ios::beg);
	ofs << "��������(beg)\n";

	ofs.seekp(std::ios::end);
	ofs << "��������(end)\n";

	ofs.seekp(15, std::ios::beg);
	ofs << "��������(15, beg)\n";

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