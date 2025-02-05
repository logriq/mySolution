//#include <iostream>
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

#include <iostream>

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

void A(int arr[], int size)
{
	arr[0] = 5;
}


void B(int a)
{
	a = 3;
}

int main()
{
	int arr[3] = { 1, 2, 3 };
	int a = 10;

	A(arr, 3);
	B(a);

	std::cout << arr[0] << std::endl;
	std::cout << a << std::endl;

	return 0;
}