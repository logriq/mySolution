#include <iostream>
#include <queue>

int main()
{
 /*  ������������
 1. queue() - ����������� �� �������������.
 2. queue(const Alloc& alloc) - ����������� �� ������������� � ��������� ���������.

 3. queue(const std::queue<T>& other) - ����������� ��ﳿ.
 4. queue(const std::deque<T>& other) - ����������� ��ﳿ deque.
 5. queue(const std::queue<T>& other, const Alloc& alloc) - ����������� ��ﳿ � ��������� ���������.
 6. queue(const std::deque<T>& other, const Alloc& alloc) - ����������� ��ﳿ deque � ��������� ���������.

 7. queue(std::queue<T>&& other) - ����������� ����������.// 8. queue(std::deque<T>&& other) - ����������� ���������� deque.
 9. queue(std::queue<T>&& other, const Alloc& alloc) - ����������� ���������� � ��������� ���������.
 10. queue(std::deque<T>&& other, const Alloc& alloc) - ����������� ���������� deque � ��������� ���������.




                          ����������

 ����: ������� std::queue ������ ���� ���� ���� - ��������� std::deque, �� ���������� �����
 std::queue ������� ���������� ����� std::deque.




                          ������

 1. bool empty() const - ������� true, ���� ��'��� queue ������, � false, ���� �� ��������.
 2. void push(const T& value) - ����� �������� � ����� �����.
 3. void push(T&& value) - ������� �������� � ����� �����.
 4. T& front() - ������� ��������� �� ������ ������� �����.
    const T& front() const - ������� ��������� �� ������ ������� �����.

 5. T& back() - ������� ��������� �� ������� ������� �����.
    const T& back() const - ������� ��������� �� ������� ������� �����.

 6. void pop() - ������� ������� ������� � ����� (������� ����������).

 7. size_t size() const - ������� ����� �����.

 8. void swap(std::queue<T>& other) - ���� ���� ���� ����.

 9. const std::deque<T>& Get_Container() const - ������� ��������� �� �������� ���������.

 10. void operator=(const std::queue<T>& other) - �������� ���� �����, ������� �������� ���� �����
     void operator=(std::queue<T>&& other) - ������� ���� �����, ���������� �������� ���� �����



                          �������

 1. bool operator==(const std::queue<T>& s1, const std::queue<T>& s2) - ������� 2 ����� (�� ��� �� ��������).
 2. bool operator>(const std::queue<T>& s1, const std::queue<T>& s2) - ����� (��������� � C++20).
 3. bool operator>=(const std::queue<T>& s1, const std::queue<T>& s2) - ����� ��� ������� (��������� � C++20).
 4. bool operator<(const std::queue<T>& s1, const std::queue<T>& s2) - ����� (��������� � C++20).
 5. bool operator<=(const std::queue<T>& s1, const std::queue<T>& s2) - ����� ��� ������� (��������� � C++20).
 6. bool operator!=(const std::queue<T>& s1, const std::queue<T>& s2) - �� ������� (��������� � C++20).

 7. std::compare_three_way_result_t<Container> operator<=>(const std::queue<T>& s1, const std::queue<T>& s2)
 - �� ������i��� ��� �������� <=>(���� ����� � �i�� �����i�� ��� �������� � C++20).

 8. void swap(std::queue<T>& s1, std::queue<T>& s2) - �i��� ��i�� ���� ����. */ 

// --- ������� ---

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