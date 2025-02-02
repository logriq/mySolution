#include <iostream>
 // ввід/вивід інформації (5)

#include <Windows.h> //для укр мови(9)

int main()
{
	//std::cout << "Hello World!" << std::endl;  //endl-кінець строки, перенос (7)
	//std::cout << std::endl;
	////  (6) std-простір імен стандартний,    character output-вивід символів
	//std::cout << "my name is Arina"; 

	// /n-перенос строки

	setlocale(LC_ALL, "rus"); //для переводу російської(9)

	SetConsoleCP(1251); // (9)встановлює кодову сторінку для вводу інформації
	SetConsoleOutputCP(1251); // для виводу інформації (9)


	std::cout << "Привіт, світ!\n";
	std::cout << "Привет, мир!\n";
	return 0;
}


