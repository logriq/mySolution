#include <iostream>

	//struct - користувацький тип данних, що об'єднує інші типи даних

/*
Синтаксис опису структури:
struct Ім'я структури
{
	Дані№1
	Дані№2
	Дані№3
	......
};
*/
	// найменший тпи даних розміщати зверху

	/*struct MyStruct
	{
		char a;
		int b;
		double c;
};*/


	//Синтаксис створення змінної структури 

 /*
	MyStruct Variable{};    // a = '\0', b = 0, c = 0.0
	MyStruct Variable = {}; // a = '\0', b = 0, c = 0.0

	MyStruct Variable{ 'G', 10, 23.4 }; // a = 'G', b = 10, c = 23.4
	MyStruct Variable = { 'G', 10, 23.4 }; // a = 'G', b = 10, c = 23.4

	MyStruct Variable( 'G', 10, 23.4 ); // не можна круглі дужки
*/



// Синтаксис зверненняя до поля структури:
	//Ім'я_Змінної.Іь'я_Поля



//Копіювання і присвоєння структур
/*struct Student
{
	char name[30];
	int age = 0;
};
	
int main()
{
	Student demien{ "Demien", 23 };

	Student copyDemien;

	copyDemien.age = demien.age;

	int i;
	for (i = 0; i < demien.name[i] != '\0'; i++)
		copyDemien.name[i] = demien.name[i];
	copyDemien.name[i] = '\0';
	return 0;
}*/

//Проблеми з полями-вказівниками

/*struct DynamicArray
{
	int* arr = nullptr;
	int size = 0;
};

int main()
{

	DynamicArray array1;

	array1.size = 5;
	array1.arr = new int[array1.size];

	for (int i = 0; 1 < array1.size; i++)
	{
		array1.arr[i] = 1 + 1;
		std::cout << array1.arr[i] << " ";
	}

	DynamicArray array2;

	array2.size = array1.size;

	if (array1.arr != nullptr)
	{
		array2.arr = new int[array2.size];

		for (int i = 0; 1 < array2.size; i++)
			array2.arr[i] = array1.arr[i];
	}
	else
		array2.arr = nullptr;

	delete[] array1.arr;
	delete[] array1.arr;

	return 0;*/




//Вказівники на структури

/*struct Point
{
	int x;
	int y;
};

int main()
{
	Point point1{ 10, 20 };

	Point* ptr = &point1; //вказівник на тип поінт змінний бо без конст
	Point& ref = point1;

	point1.x = 100;
	point1.y = 200;
	std::cout << "x = " << point1.x << endl;
	std::cout << "y = " << point1.y << endl;

	point1.x = 50;
	point1.y = 30;
	std::cout << "x = " << (*ptr).x << endl; 
	std::cout << "y = " << (*ptr).y << endl;
	// другй та третій записи одакові,але частіше використовують третій.

	point1.x = 100;
	point1.y = 200;
	std::cout << "x = " << ptr->x << endl;
	std::cout << "y = " << ptr->y << endl;



// Посилання на структури
	point1.x = 1000;
	point1.y = 2000;
	std::cout << "x = " << ref.x << endl;
	std::cout << "y = " << ref.y << endl;

	return 0;
}*/




//Масиви структур

/*struct Point
{
	int x;
	int y;
};

int main()
{
	const int SIZE = 3;
	
	Point arr[SIZE] =
	{
		Point{ 10, 20 },
		Point{ 30, 20 },
		Point{ 50, 60 }
	};

	Point* pointers[SIZE] =
	{
		&arr[0],
		&arr[1],
		&arr[2],
	};

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Struct #" << i + 1 << "; [" << pointers[i]->y << "|\n";
	}

	return 0;

}*/




//Структури в структурах

struct Point
{
	int x;
	int y;
};

struct Triangle
{
	Point a;
	Point b;
	Point c;
};

struct Piramide
{
	Triangle mainSide;
	double height;
};

int main()
{
	Piramide piramide;

	piramide.mainSide.a.x = 10;

	return 0;
}

