#include <iostream>
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




//#include <iostream>
//
//int main()
//{	
	
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


//	bool expression = (!strcmp("Hello", "hello"));
//
//	std::cout << expression;
//
//	return 0;
//}m


//#include <iostream>
//
//int main()
//{
// ��������� ��������� if: (28)

	/*if (�����1 )
		���1
	else
		���2
		 */

	//std::cout << "Enter a number";
	//int number;
	//std::cin >> number;

	//if (number == 1)
	//	std::cout << "One.\n";
	//else if (number == 2)
	//	std::cout << "Two.\n";
	//if (number == 3)
	//	std::cout << "Three.\n";




	//�������� ��������(29)
	//?: 
	// ����� ? �����1 : �����2

	//std::cout << "Enter two numbers: ";
	//int number1, number2;
	//std::cin >> number1 >> number2;

	//int max = (number1 > number2 ? number1 : number2);

	//std::cout << max << std::endl;


	//SWITCH(30)

	/*switch(��'�_�����) 
	{
	 case �������� �1:
			������_�� �1
			break;
	 case �������� �2:
			������_�� �2
			break;	
	 case �������� �3:
			������_�� �3
			break;	
	 case �������� �4:
			������_�� �4
			break;
	 default:
			������_ĳ�_��_�������������
			break;
	 }*/


	//(31)������� �����

	// 1. while
	// 2. do while
	// 3. for (���������� �����)
	// 4. for � ���������
	


	//(32) ��������� ����� while: ���� �� ��'����� � ������

	/*while (�����)
	{
	������ ��
	}
	*/


	/*int sum = 0;
	int number;

	std::cout << "Enter a number (or 0 to stop) ";
	std::cin >> number;
	sum += number;

	while (number != 0)
	{
	std::cout << "Enter a number (or 0 to stop) ";
	std::cin >> number;
	sum += number;
	}

	std::cout << "Sum = " << sum << std::endl;*/



	//(33) ��������� ����� do while: ���� �� ��'����� � ������

	/*do
	{
	������ ��
	 }while (�����);
	*/

	//#include <iostream>

	//int main()
	//{
	
		/*int number;
	do
	{
		std::cout << "Enter a number (or negative to stop): ";
		std::cin >> number;
		if (number >= 0)
			std::cout << "sqare = " << number * number << std::endl;
	} while (number >= 0);*/





		// (34) ��������� ����� for:

		//for (��������_�����������; �����; ��������_����)
		// ��������;

		/*for (int number = 1; number <= 10; number++)
		{
			std::cout << number << " ";
		}*/



		//break (36) 



		// continue(37)


	//int number, sum = 0;

	// while -> �����
	// do while -> �����
	// for -> ����_����������

//	do {
//		std::cout << "Enter next positive number (or 0 to stop): ";
//		std::cin >> number;
//
//		if (number < 0) {
//			std::cout << "You entered negative number.\n";
//			continue;
//		}
//		else {
//			sum += number;
//		}
//	} while (number != 0);
//
//	std::cout << "Sum = " << sum << std::endl;
//
//
//	return 0;
//}






// ������(40)- ��������� ��������� ���������� �����

// ��������� ��������� �����:
// ���_����� ��'�_�����;

// ��������� ��������� ������:
// ���_����� ��'�_������[ʳ������_��������];

// ��������� ��������� �� �������� ������:
// ��'�_������[������_��������];


//#include <iostream>
//
//int main()
//{
//	const int SIZE = 3;
//
//	int arr[SIZE];
//
//	for (int index = 0; index < SIZE; index++)
//		arr[index] = index * index;
//
//	for (int index = 0; index < SIZE; index++)
//		std::cout << "arr[" << index << "] = " << arr[index] << std::endl;
//
//	return 0;
//}





// ����������� ������ (41)

// ��������� ��������� 2-�������� ������:
// ���_����� ��'�_������[ʳ������_ϳ�������][ʳ������_��������]

// ��������� �� ��������� �������� 2-�������� ������:
// ��'�_������[������_ϳ�������][������_��������_ϳ�������]

/*#include <iostream>  

 int main() 
 {
	const int WEEKS = 2, DAYS = 5;

	int temperatures[WEEKS][DAYS];

	for (int i = 0; i < WEEKS; i++) {
		for (int j = 0; j < DAYS; j++) {
			temperatures[i][j] = j + i * j + i;
		}
	}

	for (int i = 0; i < WEEKS; i++) {
		for (int j = 0; j < DAYS; j++) {
			std::cout << "temperatures[" << i << "][" << j << "] = " << temperatures[i][j] << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}*/ 



//����� (42)

//#include <iostream>
//
//int main()
//{
//	std::cout << "Enter two word: ";
//
//	char word[30];
//	char word2[30];
//	
//	std::cin >> word;
//	std::cin >> word2;
//
//	std::cout << "Your word: " << word << std::endl;
//	std::cout << "Your word2: " << word2 << std::endl;
//
//	return 0;
//}




// �������(43)- �� ���������� ���� ����, ���� ���� �������� ����� ���������� �� ��������� ���������.


/*
��������� ���������� �������:
��� ������������ ���������  ��'� ������� (������ ���������)
{
���
}
*/

/*
��������� ������� �������:
��'� ������� (������ ���������);
*/

/*
��� �������� ������� | ��� ������ �������
�������� ���������   | ������� ���������
�������� ���������   | ������� ���������
����������            | ���������
*/

//#include <iostream>

//int Multiple(int a, int b)
//{
//	return a * b;
//}
//
//double ToCube(double number)
//{
//	double cube = number * number * number;
//	return cube;
//}
//
//int main()
//{
//	double number = 2.5;
//	double cube = ToCube(number);
//
//	std::cout << "Number = " << number << std::endl;
//	std::cout << "Cube = " << cube << std::endl;
//
//	return 0;
//}


//void Show(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << arr[1] << " ";
//	}
//	std::cout << std::endl;
//}
//
//
//void Initialize(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = i + i;
//	}
//}
//
//int main()
//{
//	const int SIZE1 = 3;
//	const int SIZE2 = 5;
//
//	int arr1[SIZE1];
//	int arr2[SIZE2];
//
//	Initialize(arr1, SIZE1);
//	Initialize(arr2, SIZE2);
//
//	Show(arr1, SIZE1);
//	Show(arr2, SIZE2);
//
//	return 0;
//}


// �������� �������� ������ � ������

//void A(int arr[], int size)
//{
//	arr[0] = 5;
//}
//
//
//void B(int a)
//{
//	a = 3;
//}
//
//int main()
//{
//	int arr[3] = { 1, 2, 3 };
//	int a = 10;
//
//	A(arr, 3);
//	B(a);
//
//	std::cout << arr[0] << std::endl;
//	std::cout << a << std::endl;
//
//	return 0;
//}


//��������� ��������� ���������:
// ��� ������������ ��������  ��'� �������(������ ����������� ���������);



























//int main() 
//{
	
	// ��������- �� ����, ��� ������ � ��� ������.

//��������� ��������� ���������:
// 1. ���_����� *��'� ���������;
// 2. ���_����� *��'� ��������� * ������ <- �����������


// �������� �� �����:(����� ����� ���� ����� ��������)

/*int a = 5;
int b = 10;
int* p;

p = &a;
*p = 0;

std::cout << "&a = " << &a << std::endl;
std::cout << "p = " << p << std::endl;
std::cout << "a = " << a << std::endl;
std::cout << "*p = " << *p << std::endl;


p = &b;
*p = 0;

std::cout << "&b = "  << &b << std::endl;
std::cout << "p = " << p << std::endl;
std::cout << "b = " << b << std::endl;
std::cout << "*p = " << *p << std::endl;*/



//�������� �� ���������:(�� ����� ����� ��������� ����� ��������)

/*const int a = 5;
const int b = 10;
const int* p;

p = &a;

std::cout << "&a = " << &a << std::endl;
std::cout << "p = " << p << std::endl;
std::cout << "a = " << a << std::endl;
std::cout << "*p = " << *p << std::endl;


p = &b;

std::cout << "&b = " << &b << std::endl;
std::cout << "p = " << p << std::endl;
std::cout << "b = " << b << std::endl;
std::cout << "*p = " << *p << std::endl;*/



//�������� �� ��������:

	/*int a = 10;
	int* p = &a;

	int** pp = &p;

	std::cout << "a = " << a << std::endl;
	std::cout << "&a = " << &a << std::endl;
	//std::cout << "*a = " << *a << std::endl;


	std::cout << "p = " << p << std::endl;
	std::cout << "&p = " << &p << std::endl;
	std::cout << "*p = " << *p << std::endl;


	std::cout << "pp = " << pp << std::endl;
	std::cout << "&pp = " << &pp << std::endl;
	std::cout << "*pp = " << *pp << std::endl;*/





	//�������� �� �����:

	/*const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 3, 4, 5 };

	int* p = arr;

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 10 * 1 + 1 * 3;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		p[i] = 20 * i - 10;
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}*/



//�������� �� ����������� �����:

/*const int SIZE = 5;
 int arr[SIZE] = { 1, 2, 3, 4, 5 };

const int* p = arr;

for (int i = 0; i < SIZE; i++)
{
	arr[i] = 10 * 1 + 1 * 3;
	std::cout << arr[i] << " ";
}
std::cout << std::endl;

for (int i = 0; i < SIZE; i++)
{
	std::cout << p[i] << " ";
}
std::cout << std::endl;*/






	//�������� �� �������:
	/*void Func1();
	void Func2(int a);
	void Func3(int a, int b);
	void Func4(int a, double b);
	int Func5();
	double Func6(int a);
	char Func7(int a, int b);
	long Func(int a, double b);
	void Func9(int arr[], int size);
	void Func10(const int a);
	void Func11(const int arr[], int size);*/



//��������� ��������� ���������:
		// 1. ���_������������_�������� (*��'� ���������)(����_���������_�������);
		// 2. ���_������������_�������� (*��'� ���������)(����_���������_�������) = ������_�������; <- �����������

	/*void (*p1)() = Func1;
	void (*p2)(int) = Func2;
	void (*p3)(int, int)  = Func3;
	void (*p4)(int, double) = Func4;
	int (*p5)() = Func5;
	double (*p6)(int) = Func6;
	char (*p7)(int, int) = Func7;
	long (*p8)(int, double) = Func;
	void (*p9)(int[], int) = Func9;
	void (*p10)(const int) = Func10;
	void (*p11)(const int[], int) = Func11;

	Func1();
	(*p1)();*/

	//std::cout << p1 << " = " << Func1 << std::endl;
	//std::cout << *p1 << " = " << Func1 << std::endl;

	





	//����������� ��������

	//int a = 10;
	//int b = 20;
	//const int c = 20;

	//int* const p1 = &a; //����������� �������� �� �����, ����'������� �� ����� ����� � ��� �������� �� ����� �����, ��� ����� �������� �������� �����
	//const int* p2 = &a; //�������� �� ���������, ���� ��������� �� ��� ���, ��� �� ����� �� �����
	//const int* const p1 = &a; //����������� �������� �� ����������(�� ����� �������� ���� �� ��������(������������ ������)



	//�������� ��������
	
	/*int* a = nullptr */  // ��� 0 ��� NULL ��� nullptr �����





		// void �������� (�� ����� ������������� ��� ����� ��������������� ����������)

	/*int a = 10;
	double b = 1.2;

	void* p;

	p = &a;
	std::cout << "&a = " << &a << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *(static_cast<int*>(p)) << std::endl;

	p = &b;
	std::cout << "&b = " << &b << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *(static_cast<double*>(p)) << std::endl;*/





	//���������� ���������
	//��������� �� ��������=���� ���� �� ������ �� ����� �-��� �����, ������� �� ���� �����

	//const int SIZE = 5;
	//int arr[SIZE] = { 1, 2, 3, 4, 5 };

	//int* p1 = &arr[0];

	//std::cout << "p1 = 0 = " << p1 + 0 << std::endl;
	//std::cout << "&arr[0] = " << &arr[0] << std::endl;  //�� 3 ������ ����� ��������� ����'����
	//std::cout << "&p1[0] = " << &p1[0] << std::endl;


	// г����� ��������� = ������� ������ �� ���� ������� �� ���� �����






	// ������� ������ � ��������� 

	/*const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;



	//��������� �� �������� ������� ����� ������
	for (int i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << ptr[i] << " ";
	std::cout << std::endl;

	//��������� �� ������� �������� ����� ������������
	for (int i = 0; i < SIZE; i++)
		std::cout << *(arr + i) << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << *(ptr + i) << " ";
	std::cout << std::endl;


	//��������� �� ������ �������� ����� ������
	for (int i = 0; i < SIZE; i++)
		std::cout << &arr[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << &ptr[i] << " ";
	std::cout << std::endl;


	//��������� �� ������ �������� 
	for (int i = 0; i < SIZE; i++)
		std::cout << arr + i << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << ptr + i << " ";
	std::cout << std::endl;*/

//return 0;
//}




//���������� �� ������� �� ��������� �������


/*void Initialize(int arr[], int size, int (*initFunction)());
void Show(const int arr[], int size, void (*showFunction)(int element));

int GetVaule1_10();
int GetVaule20_30();

void ShowElement(int element);
void ShowElementInBrackets(int element);
void ShowElementInSqareBrackets(int element);

int main()
{
	const int SIZE = 10;
	int arr[SIZE];
	
	Initialize(arr, SIZE, GetVaule20_30);
	Show(arr, SIZE, ShowElement);
	Show(arr, SIZE, ShowElementInBrackets);
	Show(arr, SIZE, ShowElementInSqareBrackets);

	return 0;
}

void Initialize(int arr[], int size, int (*initFunction)())
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = initFunction();
	}
}

void Show(const int arr[], int size, void (*showFunction)(int element))
{
	for (int i = 0; i < size; i++)
		showFunction(arr[i]);
	std::cout << std::endl;
}

void ShowElement(int element)
{
	std::cout << element << " ";
}

void ShowElementInBrackets(int element)
{
	std::cout << "(" << element << ") ";
}

void ShowElementInSqareBrackets(int element)
{
	std::cout << "[" << element << "] ";
}

int GetVaule1_10()
{
	return rand() % 10 + 1;
}

int GetVaule20_30()
{
	return rand() % (30 - 10) + 20;
}*/










//����,����,����̲��� ���'���


//����.����� ���� ���'��. first in, last out. ����� ��������� ���� ���������� ������� �� ��������
/*int Function2()
{
	int a = 5;
	return a;
}

void Function1(int a, int b)
{
	double c;
	char arr[3];
	char* p;
}

int main()
{
	int variable = 10;
	int arr[3] = { 1, 2, 3 };

	Function1(arr[0], variable);

	variable = Function2();

	return 0;
}*/

//�������� ���'��� - ������� ������� ��� ����� �-��� main,���������� ��� ���� ��������� ��������
//������ �������, ����� ���������� �� ��� �������� ������ ����.



//����,���� - ��� ���������� ���'���. ��������� ����� ������� ���������
// ����� �������� ��������� ��� �������� ���� ���������� ����





// 2 �������: ���������

//#include <iostream>
//#include <ctime>
//#include <cstdlib>

/*int* CreateVariable(int value);
void Func()
{
	std::cout << &"Hello World" << std::endl;
}

void Initialize(int arr[], int size);
void Showww(const int arr[], int size);

int main()
{
	const char* ptr = "Hello World";
	int a = 5;
	std::cout << ptr << '\n';

	int a = 10;
	int b = 20;
	int c = 30;
	int* arr[3] = { &a, &b, &c };
	for (int i = 0; i < 3; i++)
	{
		std::cout << *arr[0] << " ";
	}

	int arr2[3][5] = { 0 };
	int (*ptr)[5] = arr2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
		}
		std::cout << std::endl;
	}

	int arr2[3][5][5] = { 0 };*/




	// new delete



	/*int* a = new int;
	std::cout << a << '\n';
	std::cout << *a << std::endl;
	*a = 10;

	int* ptr1 = new int{ 10 };
	const int* ptr2 = new const int{ 20 };
	int** ptr3 = new int* { nullptr };
	delete ptr1;
	delete ptr2;
	delete ptr3;

	int* ptr = CreateVariable(10);
	delete ptr;

	srand(static_cast<unsigned>(time(nullptr)));
	int size;
	std::cin >> size;
	int* arr = new int[size];

	std::cout << "Enter rows:";
	int rows;
	std::cin >> rows;
	std::cout << "Enter columns: ";
	
int columns;
	std::cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;*/



	// L-value R-value
	/*int var = 10;
	int* bad_addr = &(var + 1); // ������
	int* addr = &var; // ����
	&var = 40;*/




	// ���������
/*int variable = 10;
const int CONST = 20;
int* ptr1 = &variable;
const int* ptr2 = &CONST;
variable = 50;
*ptr1 = 100;
	
std::cout << CONST << std::endl;
std::cout << *ptr2 << std::endl;
	
int& ref1 = variable;

std::cout << "&variable = " << &variable << std::endl;
std::cout << "&ptr1 = " << &ptr1 << std::endl;
std::cout << "&ref1 = " << &ref1 << std::endl;

const int& ref2 = CONST;
const int& ref = 10;
int&& ref3 = 200;

int a = 10;
int* p = &a;
int*& refp = p;
p = (int*)5;

std::cout << refp << " = " << p << std::endl;
std::cout << &refp << " = " << &p << std::endl;

int arr[5] = { 1, 2, 3, 4, 5 };
int(&ref_arr)[5] = arr;
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}

int arr2[] = { 1, 2, 3, 4 };
int size2 = 3;
int& minElement = *Min(arr2, size2);

minElement = 50;

	return 0;
}

int* CreateVariable(int value)
{
	return new int{ value };
}

void Show(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int* Min(int arr[], int size)
{
	int min = arr[0];
	int minindex = 0;
	for (int i = 1; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			minindex = i;
		}
	}
	return arr + minindex;
}*/




