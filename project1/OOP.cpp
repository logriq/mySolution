#include <iostream>
#include "Window.h"

// Виклик конструктора за замовчуванням (в статичній пам'яті):
Window window5;
Window window6{};

// Виклик конструктора з параметрами (в статичній пам'яті):
Window window11(1, 2, 3, 4);
Window window12{ 1, 2, 3, 4 };


int main()
{

	int size = 1;
	Window* arr = new Window[size]
	{
		Window(),
		Window(1, 5, 6)
	};


	// Виклик конструктора за замовчуванням (на стеку):
	Window window1;
	Window window2{}; 

	// Виклик конструктора з параметрами (на стеку):
	Window window7(1, 2, 3, 4);
	Window window8{ 1, 2, 3, 4 };

	// Виклик конструктора за замовчуванням (на кучі):
	Window* window3 = new Window;
	Window* window4 = new Window();

	// Виклик конструктора з параметрами (на кучі):
	Window* window9 = (1, 2, 3, 4);
	Window* window10 = { 1, 2, 3, 4 };

	window11.Show();

	// конструктор-метод,який автоматично викликається при своренні об'єкту

}