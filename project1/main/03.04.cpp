#include <iostream>

//������������ ���������
/*����������� ����������(Associative containers) :
    [] set
    [] multiset
    [] map
    [] multimap

    ������������� ���������� ����������(Unordered associative containers) :
    [] unordered_set
    [] unordered_multiset
    [] unordered_map
    [] unordered_multimap*/
    // ���������� ����� ���������� STL
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <set> // <- ��� ���� ����� ��������� ��� ������ � std::set � multiset

#include "Header.h"

//����� ������ ����� set

// ---------------------- ������������ ----------------------

// 1. set() - ����������� �� �������������. ������� �����.
// 2. set(const set<T>& other) - ����������� ��ﳿ
// 3. set(const set<T>& other, const Allocator& allocator) - ����������� ��ﳿ + ��������� �������� ����������.
// 4. set(set<T>&& other) - ����������� ����������
// 5. set(set<T>&& other, const Allocator& allocator) - ����������� ���������� + ��������� �������� ����������

// 6. set(std::initializer_list<T> list) - ��������� ������
// 7. set(std::initializer_list<T> list, const Predicate& predicate) - ��������� ������ + ��������� �������� ���������. ������� �����.
// 8. set(std::initializer_list<T> list, const Allocator& allocator) - ��������� ������ + ��������� �������� ����������. ������� �����.
// 9. set(std::initializer_list<T> list, colocator& allocator) - ��������� ������ + ��������� �������� ��������� � ����������. ������� �����.

// 10. set(const Predicate& predicate) - ��������� �������� ���������. ������� �����.
// 11. set(const Allocator& allocator) - ��������� �������� ����������. ������� �����.
// 12. set(const Predicate& predicate, const Allocator& allocator) - ��������� �������� ��������� � ����������. ������� �����.

// 13. set(Iterator begin, Iterator end) - ��������� �����������
// 14. set(Iterator begin, Iterator end, const Predicate& predicate) - ��������� ����������� + ��������� �������� ���������
// 15. set(Iterator begin, Iterator end, const Allocator& allocator) - ��������� ����������� + ��������� �������� ����������
// 16. set(Iterator begin, Iterator end, const Predicate& predicate, const Allocator& allocator) - ��������� ����������� + ��������� �������� ��������� � ����������

int main()
{
    std::set<int> set1;
    // empty
    Show(set1);

    std::set<int> set2 = { 10, 1, 9, 2, 3, 6 };
    Show(set2); // 1 2 3 6 9 10

    std::set<int, std::greater<int>> set3 = { 10, 1, 9, 2, 3, 6 };
    Show(set3); // 10 9 6 3 2 1

    auto lambdaComp = [](int value1, int value2) { return value1 > value2; };
    std::set<int, decltype(lambdaComp)> set4({ 1, 2, 3, 4, 5 }, lambdaComp);
    Show(set4); // 5 4 3 2 1

    std::vector<int> vector = { 100, 5, 200, 3 };
    std::set<int> set5(vector.cbegin(), vector.cend());
    Show(set5); // 3 5 100 200

    std::cout << std::endl;
    std::cout << "Hello World!\n";




    std::set<Person> people
    {
        Person(25, "Demian"),
        Person(26, "Anya"),
        Person(20, "Victoria"),
    };

    Show(people); // [Name: Anya, Age: 26]
    // [Name: Demian, Age: 25]
    // [Name: Victoria, Age: 20]

    people.insert(Person(30, "David"));

    Show(people); // [Name: Anya, Age: 26]
    // [Name: David, Age: 30]
    // [Name: Demian, Age: 25]
    // [Name: Victoria, Age: 20]

    people.emplace(8, "Clementine");

    Show(people); // [Name: Anya, Age: 26]
    // [Name: Clementine, Age: 8]
    // [Name: David, Age: 30]
    // [Name: Demian, Age: 25]
    // [Name: Victoria, Age: 20]
}

// ---------------------- ���������� ----------------------
// ��� ������� ��'���� ������� ����������� ���� ����������, ���� � ���� �����
// ������� ����������� ��� �������� �������.

//������


// 1. std::set<T>& operator=(const std::set<T>& other) - ���������� ���� �������, ���������� ��������
// 1. std::set<T>& operator=(std::set<T>&& other) - ���������� ���� �������, ����������� ��������
// 1. std::set<T>& operator=(std::initializer_list<T> list) - ���������� ���� �������, ���������� ��������
// 
// 2. void swap(std::set<T>& other) - ������� ���� ���� ������ �� �����
// 
// 3. std::set<T>::iterator begin() - ��������� �������� �� ������� ������� (������ �������)
// 3. std::set<T>::const_iterator begin() const - ��������� ����������� �������� �� ������� �������
// 4. std::set<T>::iterator end() - ��������� �������� �� ����� ������� (���� �� ������� ���������)
// 4. std::set<T>::const_iterator end() const - ��������� ����������� �������� �� ����� �������
// 5. std::set<T>::const_iterator cbegin() const - ��������� ����������� �������� �� ������� �������
// 6. std::set<T>::const_iterator cend() const - ��������� ����������� �������� �� ����� �������
// 7. std::set<T>::reverse_iterator rbegin() - ��������� ��������� �������� �� ������� ������� (������� �������)
// 7. std::set<T>::const_reverse_iterator rbegin() const - ��������� ����������� ��������� �������� �� ������� �������
// 8. std::set<T>::reverse_iterator rend() - ��������� ��������� �������� �� ����� ������� (���� �� ������ ���������)
// 8. std::set<T>::const_reverse_iterator rend() const - ��������� ����������� ��������� �������� �� ����� �������
// 9. std::set<T>::const_reverse_iterator crbegin() const - ��������� ����������� ��������� �������� �� ������� �������

// -------------------- ������� --------------------

    // 1. bool operator==(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ������
    // 2. bool operator!=(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ��������
    // 3. bool operator>(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "�����"
    // 4. bool operator>=(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "����� ��� �������"
    // 5. bool operator<(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "�����"
    // 6. bool operator<=(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "����� ��� �������"
    // 7. **** operator<=>(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���������� ���������

    // 8. void swap(std::set<T>& left, std::set<T>& right) - ���� ������ �������� ���� ������.
    // 9. size_t erase_if(std::set<T>& set, Predicate predicate) - ������� �� �������� �������, �� �������� ���������.


//void MultipleExample()
// - �� ��������� ������� ����� ��� �, �� � � std::set
// - �� ���������-����� ��� �, �� � � std::set
// - �� ������������ ��� �, �� � � std::set
// - �� ������ ��� �, �� � � std::set
// - �� ������� ��� �, �� � � std::set

// ���
// ���� ������ �������� ��-������. ���������� ��������:

// 1. ���� ������ ������� ���������� std::multiset ���� ������ ������� ��������,
//    �� ���� ��� �� ��� �������? �� ������������ ���������?

// 2. ����� erase ������� �� ���� �������� � �������, � �� ��������

// 3. ����� count ������� ��� ��� ��������, � �� 1, �� ���� � std::set