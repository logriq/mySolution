//#include <iostream>
 // ���/���� ���������� (5)

//#include <Windows.h> ��� ��� ����(9)

//int main()
//{
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

	//(12,13)
	// 
	//int myAge = 23;

	//const double PI = 3.1415;
	//int number = 3;

	//const int a = 13;
	//const int b(13);
	//const int v{ 13 };
	//const int d = { 13 };


	//std::cout << myAge << std::endl;
	//std::cout << "Pi + 3 = " << PI + number << std::endl;



//	int number1, number2;
//	int sum;
//
//	std::cout << "Enter first number: ";
//	std::cin >> number1;
//
//	std::cout << "Enter second number: ";
//	std::cin >> number2;
//
//	sum = number1 + number2;
//
//	std::cout << number1 << " + " << number2 << " = " << sum << std::endl;
//
//
//
//	return 0;
//}


//(15) ˲������

/*#include <iostream>

int main()
{
	short a = 1;
	int b =10;
	long c = 10L;
	long long d = 10LL;

	unsigned short a = 10;
	unsigned int b = 10U;
	unsigned long c = 10UL;
	unsigned long long d = 10ULL;

	float a = 1.5F;
	double b = 1.5;
	long double c = 1.5L;

	char a = 'g'; //�� ���������� ������, � ����� ���� ��������, ���� �������� ������ �� �����
	wchar_t b = L'g';
	char16_t c = u'g';
	char32_t d = U'g';

	bool a = true;

	return 0;
} */
/*
������� �������� 
(16)
*/

#include <iostream>

int main()
{
// = + - / % ��������� ��������� (18)

	//int a, b;

	//std::cout << "Enter two numbers: ";
	//std::cin >> a >> b;
	//
	//a = -a;
	//b = -b;

	//std::cout << "a = " << a << std::endl;
	//std::cout << "b = " << b << std::endl;

	//std::cout << "Enter seconds: ";
	//int userSeconds;
	//std::cin >> userSeconds;

	//const int SEC_IN_MIN = 60;

	//int seconds = userSeconds % SEC_IN_MIN;
	//int minutes = userSeconds / SEC_IN_MIN;

	//std::cout << "It is " << minutes << " minutes and " << seconds << " seconds\n"; 



	//std::cout << "Enter a number: ";
	//int number;
	//std::cin >> number;

	//(21)��������� ���������� ���������
	//std::cout << "Number = " << number << std::endl;
	//number = number + 2;
	//std::cout << "Number = " << number << std::endl;
	//number -= 5;
	//std::cout << "Number = " << number << std::endl;
	//number *= 2;
	//std::cout << "Number = " << number << std::endl;
	//number /= 4;
	//std::cout << "Number = " << number << std::endl;
	//number %= 2;
	//std::cout << "Number = " << number << std::endl;




	// ��������� �� ���������
	int a = 1, b = 2;
	int c = ++a + --b;

	std::cout << c << std::endl;

	return 0;
}