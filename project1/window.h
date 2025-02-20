#pragma once
class Window
{
private:
	int x = 0;
	int y = 0;
	int height = 5;
	int width = 5;
	const int maxHeight = 600;
	const int maxWidth = 500;


public:
	Window(int originX = 0, int originY = 0, int originHeight = 5, int originWidth = 5);


	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetHeight() const { return height; }
	int GetWidth() const { return width; }

	void SetX(int newX);
	void SetY(int newY);
	void SetHeight(int newHeight);
	void SetWidth(int newWidth);

	void Show() const;
}
	/*Синтаксис створення конструктору :

	1. Прототип:
	Ім'я_Класу(Список_Параметрів)

	2. Визначення:
	Ім'я_Класу::Ім'я_Класу(Список_Параметрів)
	{
		Код
	}

*/