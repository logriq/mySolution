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

//#include <iostream>
//
//int main()
//{
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




	// (22) ��������� �� ��������� (� ����������� �� ����������)
//	int a = 1, b = 2;
//	--b;
//	int c = ++a + b;
//
//	std::cout << c << std::endl;
//
//	return 0;
//}




#include <iostream>

int main()
{
	
	
	
	// (23) ����ղ� ��ϲ� �����
	/*long double
	double
	float
	unsigned long long
	long long
	unsigned int
	int
	char, bool, wchar_t, char_16t, char_32_t, short, unsigned short ( ����������� ���������� -> int)*/



	//int a = 2;
	//char b = 'A';
	//float c = 1.1F;
	//double d = 2.2;
	//
	//std::cout << a + b + c + d;


	// (24) ����, ������ ������������(����������) ���� ����� 
	
	// ��� ����:
	// 1. (�) -> (���)��������
	// 2. (�++) -> ���(��������)
	// 3. (�++) -> ststic_cast<���>(��������)

	//int side1 = 3, side2 = 4;

	//// 1/ double division = (double)side1 / side2;
 //	// 2/ double division = double(side1) / side2;
	//double division = static_cast<double>(side1) / side2;

	//std::cout << division << std::endl;



	//sizeof (25)
	
	//sizeof(���_�����)
	//sizeof(�����/��������)
	//sizeof �����/��������)


	/*std::cout << "--- Characters --- \n";
	std::cout << "char:                " << sizeof(char) << std::endl;
	std::cout << "wchar_t:             " << sizeof(wchar_t) << std::endl;
	std::cout << "char16_t             " << sizeof(char16_t) << std::endl;
	std::cout << "char32_t:            " << sizeof(char32_t) << std::endl;

	std::cout << std::endl;
	
	std::cout << "--- Integers --- \n";
	std::cout << "short:               " << sizeof(short) << std::endl;
	std::cout << "unsigned short:      " << sizeof(unsigned short) << std::endl;
	std::cout << "int:                 " << sizeof(int) << std::endl;
	std::cout << "unsigned int:        " << sizeof(unsigned) << std::endl;
	std::cout << "long:                " << sizeof(long) << std::endl;
	std::cout << "unsigned long:       " << sizeof(unsigned long) << std::endl;
	std::cout << "long long:           " << sizeof(long long) << std::endl;
	std::cout << "unsigned long long:  " << sizeof(unsigned long long) << std::endl;

	std::cout << std::endl;

	std::cout << "--- Floats --- \n";
	std::cout << "float:               " << sizeof(float) << std::endl;
	std::cout << "double:              " << sizeof(double) << std::endl;
	std::cout << "long double:          " << sizeof(long double) << std::endl;*/


	//int number = 10;

	//std::cout << sizeof number << std::endl;
	//std::cout << sizeof (number + 3) << std::endl;


	//��������� ���������(26)
	// >, <, >=, <=, ==, !=   ���������� �������� ���� bool(true/false)
	
	//double a = 1.0 / 3;
	//double b = 2.0 / 6;

	//std::cout << a << " " << b << std::endl;

	//bool expression = (a >= b);

	//std::cout << expression;


	//����� ���������(27) 
	// ||, &&, !  


	// ������ '�' -> &&
	
	// �����1 && �����2
	// 1. true && true -> true
	// 2. true && false -> false
	// 3. false && true -> false
	// 4. false && false -> false

	/*std::cout << "Enter a number: ";
	int number;
	std::cin >> number;

	bool expression = (2 < number && number < 5);

	std::cout << expression;*/



	// ������ '���' -> ||
	// �����1 || �����2
	// 1. true || true -> true
	// 2. true || false -> true
	// 3. false || true -> true
	// 4. false || false -> false

    /*std::cout << "Enter a number: ";
	int number;
	std::cin >> number;

	bool expression = ((number == 10) || (number == 15));

	std::cout << expression;*/

	// ������ '��' -> !
	// ! �����
	// 1. !true = false
	// 2. !false = true


	bool expression = (!strcmp("Hello", "hello"));

	std::cout << expression;





	return 0;
}