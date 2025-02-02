#include <iostream>
 // ввід/вивід інформації (5)

//#include <Windows.h> для укр мови(9)

int main()
{
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
