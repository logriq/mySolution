#include <iostream>
 // ���/���� ���������� (5)

//#include <Windows.h> ��� ��� ����(9)

int main()
{
	//std::cout << "Hello World!" << std::endl;  //endl-����� ������, ������� (7)
	//std::cout << std::endl;
	////  (6) std-������ ���� �����������,    character output-���� �������
	//std::cout << "my name is Arina"; 

	// /n-������� ������

	//setlocale(LC_ALL, "rus"); //��� �������� ��������(9)

	//SetConsoleOutputCP(1251); // ��� ������ ���������� (9)
	//SetConsoleCP(1251); // (9)���������� ������ ������� ��� ����� ����������


	//std::cout << "�����, ���!\n";
	//std::cout << "������, ���!\n";





	/*std::cout << R"(Hello
 World
!)";  (10) RAW �����: 1) ������ ����������� �� ��������. ����� ���������� ������ ��������� �� �������� ����.*/

	//int number;

	//std::cout << "Enter a number: ";
	//std::cin >> number;
	//std::cout << "You entered " << number << std::endl;

	int number1, number2;
	int sum;

	std::cout << "Enter first number: ";
	std::cin >> number1;

	std::cout << "Enter second number: ";
	std::cin >> number2;

	sum = number1 + number2;

	std::cout << number1 << " + " << number2 << " = " << sum << std::endl;

	return 0;
}
