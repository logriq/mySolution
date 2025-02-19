#include <iostream>
 // ввід/вивід інформації (5)

//#include <Windows.h> для укр мови(9)

//int main()
//{
	//std::cout << "Hello World!" << std::endl;  //endl-кінець строки, перенос (7)
	//std::cout << std::endl;
	////  (6) std-простір імен стандартний,    character output-вивід символів
	//std::cout << "my name is Arina"; 

	// /n-перенос строки

	//setlocale(LC_ALL, "rus"); //для переводу російської(9)

	//SetConsoleOutputCP(1251); // для виводу інформації (9)
	//SetConsoleCP(1251); // (9)встановлює кодову сторінку для вводу інформації


	//std::cout << "Привіт, світ!\n";
	//std::cout << "Привет, мир!\n";





	/*std::cout << R"(Hello
 World
!)";  (10) RAW рядок: 1) ескейп послідовності не працюють. можна переносити просто переносом на наступну стор.*/

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


//(15) ЛІТЕРАЛИ

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

	char a = 'g'; //це символьний літерал, а слово буде рядковим, його значення змінити не можна
	wchar_t b = L'g';
	char16_t c = u'g';
	char32_t d = U'g';

	bool a = true;

	return 0;
} */
/*
Блочний коментар 
(16)
*/

//#include <iostream>
//
//int main()
//{
// = + - / % оператори присвоєння (18)

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

	//(21)комбіновані арифметичні оператори
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




	// (22) інкремент та декремент (є постфіксний та префіксний)
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
	
	// (23) ІЄРАХІЯ ТИПІВ ДАНИХ
	/*long double
	double
	float
	unsigned long long
	long long
	unsigned int
	int
	char, bool, wchar_t, char_16t, char_32_t, short, unsigned short ( Автоматичне приведення -> int)*/



	//int a = 2;
	//char b = 'A';
	//float c = 1.1F;
	//double d = 2.2;
	//
	//std::cout << a + b + c + d;


	// (24) Явне, неявне перетворення(приведення) типів даних 
	
	// явні типи:
	// 1. (С) -> (Тип)Значення
	// 2. (С++) -> Тип(Значення)
	// 3. (С++) -> ststic_cast<Тип>(Значення)

	//int side1 = 3, side2 = 4;

	//// 1/ double division = (double)side1 / side2;
 //	// 2/ double division = double(side1) / side2;
	//double division = static_cast<double>(side1) / side2;

	//std::cout << division << std::endl;



	//sizeof (25)
	
	//sizeof(Тип_даних)
	//sizeof(Вираз/Значення)
	//sizeof Вираз/Значення)


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


	//Оператори порівняння(26)
	// >, <, >=, <=, ==, !=   Повертають значення типу bool(true/false)
	
	//double a = 1.0 / 3;
	//double b = 2.0 / 6;

	//std::cout << a << " " << b << std::endl;

	//bool expression = (a >= b);

	//std::cout << expression;


	//Логічні оператори(27) 
	// ||, &&, !  


	// Логічне 'і' -> &&
	
	// умова1 && умова2
	// 1. true && true -> true
	// 2. true && false -> false
	// 3. false && true -> false
	// 4. false && false -> false

	/*std::cout << "Enter a number: ";
	int number;
	std::cin >> number;

	bool expression = (2 < number && number < 5);

	std::cout << expression;*/



	// Логічне 'або' -> ||
	// умова1 || умова2
	// 1. true || true -> true
	// 2. true || false -> true
	// 3. false || true -> true
	// 4. false || false -> false

    /*std::cout << "Enter a number: ";
	int number;
	std::cin >> number;

	bool expression = ((number == 10) || (number == 15));

	std::cout << expression;*/

	// Логічне 'не' -> !
	// ! умова
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
// Синтаксис оператора if: (28)

	/*if (умова№1 )
		дія№1
	else
		дія№2
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




	//ТЕРНАРИЙ ОПЕРАТОР(29)
	//?: 
	// Умова ? Вираз1 : Вираз2

	//std::cout << "Enter two numbers: ";
	//int number1, number2;
	//std::cin >> number1 >> number2;

	//int max = (number1 > number2 ? number1 : number2);

	//std::cout << max << std::endl;


	//SWITCH(30)

	/*switch(ім'я_змінної) 
	{
	 case Значення №1:
			Перелік_дій №1
			break;
	 case Значення №2:
			Перелік_дій №2
			break;	
	 case Значення №3:
			Перелік_дій №3
			break;	
	 case Значення №4:
			Перелік_дій №4
			break;
	 default:
			Перелік_Дій_За_Замовчуванням
			break;
	 }*/


	//(31)ПОНЯТТЯ ЦИКЛУ

	// 1. while
	// 2. do while
	// 3. for (стандартна форма)
	// 4. for з діапазоном
	


	//(32) Синтаскис циклу while: коли дія зв'язана з умовою

	/*while (умова)
	{
	Перелік дій
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



	//(33) Синтаскис циклу do while: коли дія зв'язана з умовою

	/*do
	{
	Перелік дій
	 }while (умова);
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





		// (34) Синтаксис циклу for:

		//for (Оператор_ініціалізації; Вираз; Оператор_Зміни)
		// Оператор;

		/*for (int number = 1; number <= 10; number++)
		{
			std::cout << number << " ";
		}*/



		//break (36) 



		// continue(37)


	//int number, sum = 0;

	// while -> умова
	// do while -> умова
	// for -> блок_інкременту

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






// МАСИВИ(40)- іменована сукупність однотипних даних

// Синтаксис створення змінної:
// Тип_Даних Ім'я_Змінної;

// Синтаксис створення масиву:
// Тип_Даних Ім'я_Масиву[Кількість_Елементів];

// Синтаксис звернення до елементу масиву:
// Ім'я_Масиву[Індекс_Елементу];


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





// Багатовимірні масиви (41)

// Синтаксис створення 2-вимірного масиву:
// Тип_Даних Ім'я_Масиву[Кількість_Підмасивів][Кількість_Елементів]

// Синтаксис до звернення елемента 2-вимірного масиву:
// Ім'я_Масиву[Індекс_Підмасиву][Індекс_Елементу_Підмасиву]

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



//Рядки (42)

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




// Функція(43)- це іменований набір коду, який може приймати якусь інформацію та повертати результат.


/*
Синтаксис визначення функції:
Тип Повертаючого значенняя  Ім'я функції (список параметрів)
{
Код
}
*/

/*
Синтаксис виклику функції:
Ім'я функції (список параметрів);
*/

/*
При створенні функції | При виклик функції
Формальні параметри   | Фактичні параметри
Формальні аргументи   | Фактичні аргументи
Парамкетри            | Аргументи
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


// відмінність відправки масивів і змінних

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


//Синтаксис створення прототипу:
// Тип повертаючого значення  Ім'я функції(список формальнихх параметрів);



























//int main() 
//{
	
	// Вказівник- це зміна, яка зберігає в собі адресу.

//Синтаксис створення вказівника:
// 1. Тип_Даних *Ім'я Вказівника;
// 2. Тип_Даних *Ім'я Вказівника * Адреса <- Ініціалізація


// Вказівник на змінну:(можна міняти данні через вказівник)

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



//Вказівник на константу:(не можна міняти константу через вказівник)

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



//Вказівник на вказівник:

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





	//Вказівник на масив:

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



//Вказівник на константний масив:

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






	//Вказівник на функції:
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



//Синтаксис створення вказівника:
		// 1. Тип_Повертаючого_Значення (*Ім'я Вказівника)(Типи_Параметрів_функції);
		// 2. Тип_Повертаючого_Значення (*Ім'я Вказівника)(Типи_Параметрів_функції) = Адреса_Функції; <- Ініціалізація

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

	





	//Константний вказівник

	//int a = 10;
	//int b = 20;
	//const int c = 20;

	//int* const p1 = &a; //Константний вказівник на змінну, прив'язується до одних даних і сам вказівник не можна мінять, але можна змінювати значення даних
	//const int* p2 = &a; //Вказівник на константу, може вказувати на любі дані, але не можна їх міняти
	//const int* const p1 = &a; //Константний вквзівник на консатанту(не можна змінювати данні та значення(максимальний захист)



	//Нульовий вказівник
	
	/*int* a = nullptr */  // або 0 або NULL але nullptr краще





		// void вказівник (не можна розіменовувати але можна використовувати приведення)

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





	//Арифметика вказівників
	//додавання та віднімання=зсув вліво та вправо на певну к-сть байтів, залежно від типу даних

	//const int SIZE = 5;
	//int arr[SIZE] = { 1, 2, 3, 4, 5 };

	//int* p1 = &arr[0];

	//std::cout << "p1 = 0 = " << p1 + 0 << std::endl;
	//std::cout << "&arr[0] = " << &arr[0] << std::endl;  //ці 3 строки мають однаковий розв'язок
	//std::cout << "&p1[0] = " << &p1[0] << std::endl;


	// Різниця вказівників = кількість комірок між ними залежно від типу даних






	// Схожість масивів і вказівників 

	/*const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;



	//Звернення до елементів значень через індекс
	for (int i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << ptr[i] << " ";
	std::cout << std::endl;

	//Звернення до значень елементів через розіменування
	for (int i = 0; i < SIZE; i++)
		std::cout << *(arr + i) << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << *(ptr + i) << " ";
	std::cout << std::endl;


	//Звернення до адреси елементів через індекс
	for (int i = 0; i < SIZE; i++)
		std::cout << &arr[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << &ptr[i] << " ";
	std::cout << std::endl;


	//Звернення до адреси елементів 
	for (int i = 0; i < SIZE; i++)
		std::cout << arr + i << " ";
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << ptr + i << " ";
	std::cout << std::endl;*/

//return 0;
//}




//Вказівникки на функції як параметри функції


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










//СТЕК,КУПА,ДИНАМІЧНА ПАМ'ЯТЬ


//Стек.займає мало пам'яті. first in, last out. змінна знищується коли закінчується область її видимості
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

//Статична пам'ять - створює статичні дані перед ф-ією main,знищуються дані після закінчення програми
//Завжди існують, можна звертатись до них протягом всього коду.



//Купа,Куча - вся оперативна пам'ять. створення даних повертає вказівники
// треба видаляти самостійно або знищення після завершення коду





// 2 частина: Вказівники

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
	int* bad_addr = &(var + 1); // невірно
	int* addr = &var; // вірно
	&var = 40;*/




	// Посилання
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




