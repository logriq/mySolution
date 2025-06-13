#include <iostream>
#include <vector>
#include <list>
#include "Person.h"

void Show(const std::list<int>& container);
void Show(const std::list<Person>& container);

// Конструктори

void AllContainers();
void Constructors();
void Destructor();
void Methods();
void GlobalOperatorsAndFunctions();
void ContainerAliases();
void OwnClassInContainer();
void PointersInContainer();

int main()
{
    //Constructors();
    //Destructor();
    //Methods();
    //GlobalOperatorsAndFunctions();
    //ContainerAliases();
    //OwnClassInContainer();
    //PointersInContainer();

    return 0;
}

void Show(const std::list<int>& container)
{
    if (container.empty())
    {
        std::cout << "Container is empty:\n";
    }
    else
    {
        std::cout << "Elements: ";
        for (int value : container)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Size = " << container.size() << "\n\n";
}
void Show(const std::list<Person>& container)
{
    if (container.empty())
    {
        std::cout << "Container is empty:\n";
    }
    else
    {
        std::cout << "People:\n";
        for (const Person& person : container)
        {
            std::cout << "\t";
            person.ShowInfo();
        }
    }

    std::cout << "Size = " << container.size() << "\n\n";
}

void AllContainers() {}
void Constructors()
{
    // 1. Конструктор за замовчуванням
    std::list<int> list1;
    Show(list1);

    // 2. Конструктор за замовчуванням, який приймає користувацький аллокатор
    std::allocator<int> myAllocator; // Представимо, що ви написали свій аллокатор
    std::list<int> list2(myAllocator);
    Show(list2);

    // 3. Конструктор, приймаючий std::initializer_list
    std::list<int> list3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Show(list3);

    // 4. Конструктор копії
    std::list<int> list4(list3);


    // 5. Конструктор переміщення
    std::list<int> list5(std::move(list4));

    // 6. Конструктор, який приймає кількість елементів
    std::list<int> list6(10);

    // 7. Конструктор, який приймає кількість елементів і їх значення
    std::list<int> list7(3, 100);

    // 8. Конструктор, який приймає 2 ітератори
    std::vector<int> vector{ 10, 20, 30 };
    std::list<int> list8(vector.cbegin(), vector.cend());
}

// [ ] Деструктор

void Destructor()
{
    // У контейнера є деструктор, в якому вся пам'ять під виділені елементи на кучі
    // автоматично звільняється/видаляється. Вам не потрібно викликати деструктор явно.
    std::list<Person> container(2);
}

// [ ] Методи

void Methods()
{
    // 1. front - повертає посилання на перший елемент.
    // 2. back - повертає посилання на останній елемент.
    {
        std::cout << "---------- front & back ----------\n";

        std::list<int> list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::cout << "list.front() = " << list.front() << std::endl;
        std::cout << "list.back() = " << list.back() << std::endl;

        list.front() = 100;
        list.back() = 100;

        std::cout << "list.front() = " << list.front() << std::endl;
        std::cout << "list.back() = " << list.back() << std::endl;

    }

    // 3. get_allocator - повертає аллокатор, який прив'язаний до контейнера.
    {
        std::list<int> list;
        std::allocator<int> allocator = list.get_allocator();
    }

    // 4. operator= - дозволяє переписувати вміст контейнера новими значеннями.
    {
        std::cout << "---------- operator= ----------\n";

        std::list<int> list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        Show(list);

        list = { 1, 2, 3, 4, 5 }; // std::initializer_list
        Show(list);

        list = std::list<int>(10, 1); // move =
        Show(list);


        std::list<int> otherList{ 200, 100, 0 };
        list = otherList; // copy =
        Show(list);
    }

    // 5. assign - дозволяє переписувати вміст контейнера новими значеннями.
    //     Схожий на оператор =, але має більше можливостей, бо може приймати
    //     більше одного параметру.
    {
        std::cout << "---------- assign ----------\n";

        std::list<int> list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        Show(list);

        list.assign(5, 100);    // 5 елементів, значення кожного 100
        Show(list);

        list.assign({ 1, 2, 3, 4, 5 }); // std::initializer_list
        Show(list);

        std::vector<int> vector{ 500, 499, 388 };
        list.assign(vector.cbegin(), vector.cend()); // діапазон значень через ітератори любого контейнера
        Show(list);
    }

    // 6. begin - повертає ітератор на початок діапазону контейнера. Через ітератор можна міняти значення.
    // 7. end - повертає ітератор на кінець діапазону контейнера. Кінець - це значення ЗА останнім елементом.
    // 8. cbegin - повертає константний ітератор на початок діапазону контейнера. Через ітератор НЕ можна міняти значення.
    // 9. cend - повертає константний ітератор на кінець діапазону контейнера. Кінець - це значення ЗА останнім елементом.
    // 8. rbegin - повертає обернений ітератор на початок діапазону контейнера. Через ітератор можна міняти значення.
    // 9. rend - повертає обернений ітератор на кінець діапазону контейнера. Кінець - це значення ЗА останнім елементом.
    // 8. crbegin - повертає обернений константний ітератор на початок діапазону контейнера. Через ітератор НЕ можна міняти значення.
    // 9. crend - повертає обернений константний ітератор на кінець діапазону контейнера. Кінець - це значення ЗА останнім елементом.

    // 10. empty - повертає true, якщо контейнер пустий.
    {
        std::cout << "---------- empty ----------\n";

        std::list<int> list1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::list<int> list2;

        std::cout << (list1.empty() ? "list1 is empty" : "list1 isn't empty") << std::endl;
        std::cout << (list2.empty() ? "list2 is empty" : "list2 isn't empty") << std::endl;
    }

    // 11. size - повертає розмір контейнера (кількість елементів).
    {
        std::cout << "---------- size ----------\n";

        std::list<int> list1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::list<int> list2;

        std::cout << "list1.size() = " << list1.size() << std::endl;
        std::cout << "list2.size() = " << list2.size() << std::endl;
    }

    // 12. max_size - повертає максимальний розмір контейнера (максимально можливу кількість елементів)
    {
        std::cout << "---------- max_size ----------\n";

        std::list<int> list1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::list<char> list2;

        std::cout << "list1.max_size() = " << list1.max_size() << std::endl;
        std::cout << "list2.max_size() = " << list2.max_size() << std::endl;
    }

}

// [ ] Глобальні перезавантаження операторів і функцій

void GlobalOperatorsAndFunctions()
{

    // 1. operator== - порівнює вміст контейнерів.
    //                 true - якщо контейнери мають однаковий розмір і всі
    //                 їх елементи рівні між собою.
    std::list<int> list1 = { 1, 2, 3 };
    std::list<int> list2 = { 1, 2, 3 };
    std::list<int> list3 = { 1, 2, 3, 4 };
    std::list<int> list4 = { 1, 2, 5 };

    if (list1 == list2)
    {
        std::cout << "list1 = List2\n";
    }
    if (list1 == list3) // ні, бо розміри різні
    {
        std::cout << "list1 = List3\n";
    }
    if (list1 == list4) // ні, бо значення різні
    {
        std::cout << "list1 = List4\n";
    }

    // Оператори 2-6 убрані в стандарті C++20. можна самму
  // догадатися, як вони працюють, якщо знаєш, як працює operator==.
  // 2. operator!=
  // 3. operator<
  // 4. operator<=
  // 5. operator>
  // 6. operator>=

  // В стандарті C++20 замість операторів 1-6 появився оператор <=>.
  // Він продуктивніший. Блоган не показував його роботу окремо від контейнеру
  // то й тут його показувати не буде
  // 7. operator<=>
// 8. std::swap - міняє місцями вміст двох контейнерів. Це спеціалізація шаблону
//                функції std::swap, яка викликає всередині метод list::swap().
    std::cout << "---------- swap ----------\n";
}

// [ ] Псевдоніми контейнеру

void ContainerAliases()
{
    // Приклади:
    std::list<int>::value_type value = 10;     // int value = 10;
    std::list<int>::const_reference reference = value; // const int& reference = value;
    std::list<int>::pointer pointer = &value; // int* pointer = &value;
}

// [ ] Використання власного класу у List

void OwnClassInContainer()
{
    std::list<Person> people;
    people.push_back(Person());
    people.cbegin()->ShowInfo();

    std::cout << "--------------------\n";

    people.emplace_back(25, "Demian");
    people.back().ShowInfo();

    std::cout << "--------------------\n";

    for (auto iterator = people.cbegin(); iterator != people.cend(); ++iterator)
    {
        iterator->ShowInfo();
    }
}

