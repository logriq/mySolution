#include <iostream>
#include <queue>

int main()
{
 /*  Конструктори
 1. queue() - конструктор за замовчуванням.
 2. queue(const Alloc& alloc) - конструктор за замовчуванням з указанням алокатора.

 3. queue(const std::queue<T>& other) - конструктор копії.
 4. queue(const std::deque<T>& other) - конструктор копії deque.
 5. queue(const std::queue<T>& other, const Alloc& alloc) - конструктор копії з указанням алокатора.
 6. queue(const std::deque<T>& other, const Alloc& alloc) - конструктор копії deque з указанням алокатора.

 7. queue(std::queue<T>&& other) - конструктор переміщення.// 8. queue(std::deque<T>&& other) - конструктор переміщення deque.
 9. queue(std::queue<T>&& other, const Alloc& alloc) - конструктор переміщення з указанням алокатора.
 10. queue(std::deque<T>&& other, const Alloc& alloc) - конструктор переміщення deque з указанням алокатора.




                          Деструктор

 Опис: оскільки std::queue містить лише одне поле - контейнер std::deque, то деструктор класу
 std::queue викликає деструктор класу std::deque.




                          Методи

 1. bool empty() const - повертає true, якщо об'єкт queue пустий, і false, якщо має елементи.
 2. void push(const T& value) - копіює значення в кінець черги.
 3. void push(T&& value) - переміщує значення в кінець черги.
 4. T& front() - повертає посилання на перший елемент черги.
    const T& front() const - повертає посилання на перший елемент черги.

 5. T& back() - повертає посилання на останній елемент черги.
    const T& back() const - повертає посилання на останній елемент черги.

 6. void pop() - видаляє останній елемент з черги (викликає деструктор).

 7. size_t size() const - повертає розмір черги.

 8. void swap(std::queue<T>& other) - міняє вміст двох черг.

 9. const std::deque<T>& Get_Container() const - повертає посилання на внутрішній контейнер.

 10. void operator=(const std::queue<T>& other) - переписує вміст черги, копіюючи значення нової черги
     void operator=(std::queue<T>&& other) - переміщує вміст черги, переміщаючи значення нової черги



                          Функції

 1. bool operator==(const std::queue<T>& s1, const std::queue<T>& s2) - порівнює 2 черги (чи рівні їх елементи).
 2. bool operator>(const std::queue<T>& s1, const std::queue<T>& s2) - більше (видалений в C++20).
 3. bool operator>=(const std::queue<T>& s1, const std::queue<T>& s2) - більше або дорівнює (видалений в C++20).
 4. bool operator<(const std::queue<T>& s1, const std::queue<T>& s2) - менше (видалений в C++20).
 5. bool operator<=(const std::queue<T>& s1, const std::queue<T>& s2) - менше або дорівнює (видалений в C++20).
 6. bool operator!=(const std::queue<T>& s1, const std::queue<T>& s2) - не дорівнює (видалений в C++20).

 7. std::compare_three_way_result_t<Container> operator<=>(const std::queue<T>& s1, const std::queue<T>& s2)
 - не розповiдав про оператор <=>(який разом з цiєю функцiєю був добавлен в C++20).

 8. void swap(std::queue<T>& s1, std::queue<T>& s2) - мiняє вмiст двох черг. */ 

// --- Приклад ---

    std::queue<int> queue;

    for (int number = 0; number < 5; number++)
    {
        queue.push(number);
    }

    for (size_t i = 0; !queue.empty(); i++)
    {
        int value = queue.front();
        queue.pop();
        std::cout << value << " ";
    }
    std::cout << std::endl;

    if (queue.empty())
    {
        std::cout << "Queue is empty.\n";
    }
}