#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>
bool LinearSearch(const T arr[], int sizw, const T key);

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	const int SIZE = 10;
	int arr[SIZE];

	Initialize(arr, SIZE);
	Show(arr, SIZE);

	std::cout << "Enter value that you want to find: ";
	int value;
	std::cin >> value;

	if (LinearSearch(arr, SIZE, value))
	{
		std::cout << "The array has your vaule!\n";
	}

	else
	{
		std::cout << "The array doesn`t have your value :(\n";
	}

	return 0;
}

void Initialize(int arr[], int size)
{
	if (arr == nullptr)
		return;

	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void Show(const int arr[], int size)
{
	if (arr == nullptr)
		return;

	for(int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
 }

bool LinearSearch(const int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
		if (key == arr[i])
			return true;

	return false;
}