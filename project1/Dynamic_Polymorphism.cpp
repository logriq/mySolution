// ���� 176. ���� �������� �������, ���������� �� ��������� �����


// ��������� ������� � �����

class Parent
{
public:
    const char* sayHi() { return "Hi"; } // �������� ����������� �������

    virtual const char* getName() { return "Parent"; } // �������� ��������� �������

    virtual int getValue() = 0; // ����� ��������� �������

    int doSomething() = 0; // ������� ���������: ���������� ����������� ������������ �������� �������� 0
};

//����� �����, �� ����������� ����������: ����������� ���� ������� ��������� ������ �����.




int main()
{
    Parent parent; // �� �� ������ ���������� ��'���� ������������ �����, ��� ������ ������������ �����, �� �� �������
    parent.getValue(); // ���� ��������� ��������� ����� ����� ����?
}
// ������� �� �� ��������� ����� getValue(), �� ���� ��������� ��������� parent.getValue() ?






//������� ����� ��������� �������


#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // �� ������� ��� ����������� protected, ���� �� �� ������, ��� ����������� ����� ���������� ��'���� ����� Animal �������,
    // ��� ������, ��� �� ��������� ���������� � ������� ������
    Animal(std::string name)
        : m_name(name)
    {
    }

public:
    std::string getName() { return m_name; }
    virtual const char* speak() { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() { return "Woof"; }
};

//
//
//
//

class Lion : public Animal
{
public:
    Lion(std::string name)
        : Animal(name)
    {
    }

    // �� ������ ������������� ����� speak()
};

int main()
{
    Lion lion("John");
    std::cout << lion.getName() << " says " << lion.speak() << '\n';
}