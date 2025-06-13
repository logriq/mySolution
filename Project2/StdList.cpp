#include <iostream>
#include <vector>
#include <list>
#include "Person.h"

void Show(const std::list<int>& container);
void Show(const std::list<Person>& container);

// ������������

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
    // 1. ����������� �� �������������
    std::list<int> list1;
    Show(list1);

    // 2. ����������� �� �������������, ���� ������ �������������� ���������
    std::allocator<int> myAllocator; // �����������, �� �� �������� ��� ���������
    std::list<int> list2(myAllocator);
    Show(list2);

    // 3. �����������, ���������� std::initializer_list
    std::list<int> list3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Show(list3);

    // 4. ����������� ��ﳿ
    std::list<int> list4(list3);


    // 5. ����������� ����������
    std::list<int> list5(std::move(list4));

    // 6. �����������, ���� ������ ������� ��������
    std::list<int> list6(10);

    // 7. �����������, ���� ������ ������� �������� � �� ��������
    std::list<int> list7(3, 100);

    // 8. �����������, ���� ������ 2 ���������
    std::vector<int> vector{ 10, 20, 30 };
    std::list<int> list8(vector.cbegin(), vector.cend());
}

// [ ] ����������

void Destructor()
{
    // � ���������� � ����������, � ����� ��� ���'��� �� ������ �������� �� ����
    // ����������� �����������/�����������. ��� �� ������� ��������� ���������� ����.
    std::list<Person> container(2);
}

// [ ] ������

void Methods()
{
    // 1. front - ������� ��������� �� ������ �������.
    // 2. back - ������� ��������� �� ������� �������.
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

    // 3. get_allocator - ������� ���������, ���� ����'������ �� ����������.
    {
        std::list<int> list;
        std::allocator<int> allocator = list.get_allocator();
    }

    // 4. operator= - �������� ������������ ���� ���������� ������ ����������.
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

    // 5. assign - �������� ������������ ���� ���������� ������ ����������.
    //     ������ �� �������� =, ��� �� ����� �����������, �� ���� ��������
    //     ����� ������ ���������.
    {
        std::cout << "---------- assign ----------\n";

        std::list<int> list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        Show(list);

        list.assign(5, 100);    // 5 ��������, �������� ������� 100
        Show(list);

        list.assign({ 1, 2, 3, 4, 5 }); // std::initializer_list
        Show(list);

        std::vector<int> vector{ 500, 499, 388 };
        list.assign(vector.cbegin(), vector.cend()); // ������� ������� ����� ��������� ������ ����������
        Show(list);
    }

    // 6. begin - ������� �������� �� ������� �������� ����������. ����� �������� ����� ����� ��������.
    // 7. end - ������� �������� �� ����� �������� ����������. ʳ���� - �� �������� �� ������� ���������.
    // 8. cbegin - ������� ����������� �������� �� ������� �������� ����������. ����� �������� �� ����� ����� ��������.
    // 9. cend - ������� ����������� �������� �� ����� �������� ����������. ʳ���� - �� �������� �� ������� ���������.
    // 8. rbegin - ������� ��������� �������� �� ������� �������� ����������. ����� �������� ����� ����� ��������.
    // 9. rend - ������� ��������� �������� �� ����� �������� ����������. ʳ���� - �� �������� �� ������� ���������.
    // 8. crbegin - ������� ��������� ����������� �������� �� ������� �������� ����������. ����� �������� �� ����� ����� ��������.
    // 9. crend - ������� ��������� ����������� �������� �� ����� �������� ����������. ʳ���� - �� �������� �� ������� ���������.

    // 10. empty - ������� true, ���� ��������� ������.
    {
        std::cout << "---------- empty ----------\n";

        std::list<int> list1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::list<int> list2;

        std::cout << (list1.empty() ? "list1 is empty" : "list1 isn't empty") << std::endl;
        std::cout << (list2.empty() ? "list2 is empty" : "list2 isn't empty") << std::endl;
    }

    // 11. size - ������� ����� ���������� (������� ��������).
    {
        std::cout << "---------- size ----------\n";

        std::list<int> list1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::list<int> list2;

        std::cout << "list1.size() = " << list1.size() << std::endl;
        std::cout << "list2.size() = " << list2.size() << std::endl;
    }

    // 12. max_size - ������� ������������ ����� ���������� (����������� ������� ������� ��������)
    {
        std::cout << "---------- max_size ----------\n";

        std::list<int> list1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::list<char> list2;

        std::cout << "list1.max_size() = " << list1.max_size() << std::endl;
        std::cout << "list2.max_size() = " << list2.max_size() << std::endl;
    }

}

// [ ] �������� ���������������� ��������� � �������

void GlobalOperatorsAndFunctions()
{

    // 1. operator== - ������� ���� ����������.
    //                 true - ���� ���������� ����� ��������� ����� � ��
    //                 �� �������� ��� �� �����.
    std::list<int> list1 = { 1, 2, 3 };
    std::list<int> list2 = { 1, 2, 3 };
    std::list<int> list3 = { 1, 2, 3, 4 };
    std::list<int> list4 = { 1, 2, 5 };

    if (list1 == list2)
    {
        std::cout << "list1 = List2\n";
    }
    if (list1 == list3) // �, �� ������ ���
    {
        std::cout << "list1 = List3\n";
    }
    if (list1 == list4) // �, �� �������� ���
    {
        std::cout << "list1 = List4\n";
    }

    // ��������� 2-6 ����� � �������� C++20. ����� �����
  // ����������, �� ���� ��������, ���� ����, �� ������ operator==.
  // 2. operator!=
  // 3. operator<
  // 4. operator<=
  // 5. operator>
  // 6. operator>=

  // � �������� C++20 ������ ��������� 1-6 �������� �������� <=>.
  // ³� �������������. ������ �� ��������� ���� ������ ������ �� ����������
  // �� � ��� ���� ���������� �� ����
  // 7. operator<=>
// 8. std::swap - ���� ������ ���� ���� ����������. �� ������������ �������
//                ������� std::swap, ��� ������� �������� ����� list::swap().
    std::cout << "---------- swap ----------\n";
}

// [ ] ��������� ����������

void ContainerAliases()
{
    // ��������:
    std::list<int>::value_type value = 10;     // int value = 10;
    std::list<int>::const_reference reference = value; // const int& reference = value;
    std::list<int>::pointer pointer = &value; // int* pointer = &value;
}

// [ ] ������������ �������� ����� � List

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

