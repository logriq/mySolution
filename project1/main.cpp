#include <iostream>
 // ���/���� ���������� (5)

#include <Windows.h> //��� ��� ����(9)

int main()
{
	//std::cout << "Hello World!" << std::endl;  //endl-����� ������, ������� (7)
	//std::cout << std::endl;
	////  (6) std-������ ���� �����������,    character output-���� �������
	//std::cout << "my name is Arina"; 

	// /n-������� ������

	setlocale(LC_ALL, "rus"); //��� �������� ��������(9)

	SetConsoleCP(1251); // (9)���������� ������ ������� ��� ����� ����������
	SetConsoleOutputCP(1251); // ��� ������ ���������� (9)


	std::cout << "�����, ���!\n";
	std::cout << "������, ���!\n";
	return 0;
}


