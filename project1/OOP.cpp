#include <iostream>
#include "Window.h"

// ������ ������������ �� ������������� (� �������� ���'��):
Window window5;
Window window6{};

// ������ ������������ � ����������� (� �������� ���'��):
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


	// ������ ������������ �� ������������� (�� �����):
	Window window1;
	Window window2{}; 

	// ������ ������������ � ����������� (�� �����):
	Window window7(1, 2, 3, 4);
	Window window8{ 1, 2, 3, 4 };

	// ������ ������������ �� ������������� (�� ����):
	Window* window3 = new Window;
	Window* window4 = new Window();

	// ������ ������������ � ����������� (�� ����):
	Window* window9 = (1, 2, 3, 4);
	Window* window10 = { 1, 2, 3, 4 };

	window11.Show();

	// �����������-�����,���� ����������� ����������� ��� ������� ��'����

}