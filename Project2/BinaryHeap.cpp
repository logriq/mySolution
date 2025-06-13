#include<iostream>
#include<climits>
using namespace std;

//прототип допоміжної функції для обміну двох цілих чимел
void swap(int* x, int* y);

//клас для мінімальної купи(Min Heap)
class MinHeap
{
    int* harr; //вказівник на масив елементів у купі
    int capacity; //максимально можливий розмір мінімальної купи
    int heap_size; //поточна кількість елементів у мінімальній купі
public:
    //це конструктор
    MinHeap(int capacity);

    //для перетворення піддерева на купу з коренем за заданим індексом
    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    //щоб отримати індекс лівого дочірнього елемента вузла з індексом i
    int left(int i) { return (2 * i + 1); }

    //щоб отримати індекс правого дочірнього елемента вузла з індексом i
    int right(int i) { return (2 * i + 2); }

    //щоб витягти корінь, який є мінімальним елементом
    int extractMin();

    //зменшує значення ключа за індексом i до new_val
    void decreaseKey(int i, int new_val);

    //повертає мінімальний ключ (ключ у корені) з мінімальної купи
    int getMin() { return harr[0]; }

    //видаляє ключ, що зберігається за індексом i
    void deleteKey(int i);

    //вставляє новий кллюч 'k'
    void insertKey(int k);
};

//конструктор: Будує купу з даного масиву a[] заданого розміру
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

//вставляється новий ключ 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nПереповнення: Не вдалося вставити ключ\n";
        return;
    }

    //с/початку вставляємо новий ключ в кінець
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    //виправляємо властивість мінімальної купи, якщо вона порушена
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

//зменшує значення ключа за індексом 'i' до new_val - передбачається, що
//new_val менше ніж harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

//метод для видалення мінімального елемента (або кореня) з мінімальної купи
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return 2147483647;

    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    //тепер зберігаємо мінімальне значення та видаляємо його з купи
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


//ця функція видаляє ключ за індексом i. Вона спочатку зменшує значення до мінус
//нескінченності, а потім викликає extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

//рекурсивний метод для перетворення піддерева на купу з коренем за заданим індексом
//цей метод передбачвє, що піддерева вже перетворені на купу
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;

    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

//допоміжна функція для обміну двох елементів
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//головна програма для тестування вищезазначених функцій
int main()
{
    MinHeap h(11);

    h.insertKey(3);

    h.insertKey(2);

    h.deleteKey(1);

    h.insertKey(15);

    h.insertKey(5);

    h.insertKey(4);

    h.insertKey(45);

    cout << h.extractMin() << " ";

    cout << h.getMin() << " ";

    h.decreaseKey(2, 1);

    cout << h.getMin();

    return 0;
}