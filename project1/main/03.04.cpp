#include <iostream>

//асоціативний контейнер
/*Ассоціативні контейнери(Associative containers) :
    [] set
    [] multiset
    [] map
    [] multimap

    Невпорядковані асоціативні контейнери(Unordered associative containers) :
    [] unordered_set
    [] unordered_multiset
    [] unordered_map
    [] unordered_multimap*/
    // Заголовкові файли контейнерів STL
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <set> // <- цей файл треба підключити для роботи з std::set і multiset

#include "Header.h"

//Схема роботи класу set

// ---------------------- Конструктори ----------------------

// 1. set() - конструктор за замовчуванням. Множина пуста.
// 2. set(const set<T>& other) - конструктор копії
// 3. set(const set<T>& other, const Allocator& allocator) - конструктор копії + копіювання готового аллокатору.
// 4. set(set<T>&& other) - конструктор переміщення
// 5. set(set<T>&& other, const Allocator& allocator) - конструктор переміщення + копіювання готового аллокатору

// 6. set(std::initializer_list<T> list) - копіювання списку
// 7. set(std::initializer_list<T> list, const Predicate& predicate) - копіювання списку + копіювання готового предикату. Множина пуста.
// 8. set(std::initializer_list<T> list, const Allocator& allocator) - копіювання списку + копіювання готового аллокатору. Множина пуста.
// 9. set(std::initializer_list<T> list, colocator& allocator) - копіювання списку + копіювання готового предикату і аллокатору. Множина пуста.

// 10. set(const Predicate& predicate) - копіювання готового предикату. Множина пуста.
// 11. set(const Allocator& allocator) - копіювання готового аллокатору. Множина пуста.
// 12. set(const Predicate& predicate, const Allocator& allocator) - копіювання готового предикату і аллокатору. Множина пуста.

// 13. set(Iterator begin, Iterator end) - копіювання послідовності
// 14. set(Iterator begin, Iterator end, const Predicate& predicate) - копіювання послідовності + копіювання готового предикату
// 15. set(Iterator begin, Iterator end, const Allocator& allocator) - копіювання послідовності + копіювання готового аллокатору
// 16. set(Iterator begin, Iterator end, const Predicate& predicate, const Allocator& allocator) - копіювання послідовності + копіювання готового предикату і аллокатору

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

// ---------------------- Деструктор ----------------------
// При знищенні об'єкта множини викликається його деструктор, який в свою чергу
// викликає конструктор всіх елементів множини.

//методи


// 1. std::set<T>& operator=(const std::set<T>& other) - переписати вміст множини, скопіювавши значення
// 1. std::set<T>& operator=(std::set<T>&& other) - переписати вміст множини, перемістивши значення
// 1. std::set<T>& operator=(std::initializer_list<T> list) - переписати вміст множини, скопіювавши значення
// 
// 2. void swap(std::set<T>& other) - поміняти вміст двох множин між собою
// 
// 3. std::set<T>::iterator begin() - повернути ітератор на початок множини (перший елемент)
// 3. std::set<T>::const_iterator begin() const - повернути константний ітератор на початок множини
// 4. std::set<T>::iterator end() - повернути ітератор на кінець множини (місце за останнім елементом)
// 4. std::set<T>::const_iterator end() const - повернути константний ітератор на кінець множини
// 5. std::set<T>::const_iterator cbegin() const - повернути константний ітератор на початок множини
// 6. std::set<T>::const_iterator cend() const - повернути константний ітератор на кінець множини
// 7. std::set<T>::reverse_iterator rbegin() - повернути обернений ітератор на початок множини (останній елемент)
// 7. std::set<T>::const_reverse_iterator rbegin() const - повернути константний обернений ітератор на початок множини
// 8. std::set<T>::reverse_iterator rend() - повернути обернений ітератор на кінець множини (місце за першим елементом)
// 8. std::set<T>::const_reverse_iterator rend() const - повернути константний обернений ітератор на кінець множини
// 9. std::set<T>::const_reverse_iterator crbegin() const - повернути константний обернений ітератор на початок множини

// -------------------- Функції --------------------

    // 1. bool operator==(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на рівність
    // 2. bool operator!=(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на нерівність
    // 3. bool operator>(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "більше"
    // 4. bool operator>=(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "більше або дорівнює"
    // 5. bool operator<(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "менше"
    // 6. bool operator<=(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "менше або дорівнює"
    // 7. **** operator<=>(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на тришляхове порівняння

    // 8. void swap(std::set<T>& left, std::set<T>& right) - міняє місцями елементи двох множин.
    // 9. size_t erase_if(std::set<T>& set, Predicate predicate) - видаляє всі елементи множини, які підходять предикату.


//void MultipleExample()
// - Всі параметри шаблону класу такі ж, як і в std::set
// - Всі псевдоніми-члени такі ж, як і в std::set
// - Всі конструктори такі ж, як і в std::set
// - Всі методи такі ж, як і в std::set
// - Всі функції такі ж, як і в std::set

// АЛЕ
// Деякі методи працюють по-іншому. Розглянемо відмінність:

// 1. Якщо кожний елемент контейнера std::multiset може містити однакові значення,
//    то який тип має сам елемент? Як переміщуються ітератори?

// 2. Метод erase видаляє не одне значення в елементі, а всі значення

// 3. Метод count повертає уже різні значення, а не 1, як було в std::set