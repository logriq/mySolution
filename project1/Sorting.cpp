
//Сортування вибіркою

/*#include <iostream>
#include <ctime>
void Initialize(int arr[], int size);
void Show(const int arr[], int size);

template <typename T>
void SelectionSort(T arr[], int size);

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	const int SIZE = 10;
	int arr[SIZE];

	const int SIZE2 = 20;
	int arr2[SIZE2];

	Initialize(arr, SIZE);
	Show(arr, SIZE);

	Initialize(arr, SIZE);
	Show(arr2, SIZE2);

	SelectionSort(arr, SIZE);
	SelectionSort(arr2, SIZE2);

	Show(arr, SIZE);
	Show(arr2, SIZE2);

	return 0;

}


void Initialize(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void Show(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T> 
void SelectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[i])
				std::swap(arr[i], arr[j]);
}*/






//Сортування бульбашкою

#include <iostream>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    const int SIZE = 10;
    int arr[SIZE];

    Initialize(arr, SIZE);
    Show(arr, SIZE);
    BubbleSort(arr, SIZE);
    //Bubble Sort
    //Сортування
    Show(arr, SIZE);
    return 0;

    for (int i = 0; i < SIZE - 1; i++)
        for (int j = SIZE - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                std::swap(arr[j], arr[j - 1]);

    std::cout << "Hello World!\n";

    //Insertion Sort

}

void Initialize(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

void Show(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j > i; j--)
            if (arr[j] > arr[j - 1])
                std::swap(arr[j], arr[j - 1]);
}
template <typename T>
void InsertionSort(T arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = key;
    }
}