#pragma once
#include <iostream>
class Person {
private:
    int age;
    std::string name;

public:
    Person()
        : age(0), name("")
    {
        std::cout << "Default constructor\n";
    }

    Person(int age, const std::string& name)
        : age(age), name(name)
    {
        std::cout << "2param constructor\n";
    }

    Person(const Person& other)
        : age(other.age), name(other.name)
    {
        std::cout << "Copy constructor\n";
    }

    Person(Person&& other) noexcept
        : age(other.age), name(other.name)
    {
        std::cout << "Move constructor\n";
    }

    ~Person()
    {
        std::cout << "Destructor\n";
    }

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            std::cout << "Copy operator=\n";
            age = other.age;
            name = other.name;
        }

        return *this;
    }

    Person& operator=(Person&& other) noexcept
    {
        std::cout << "Move operator=\n";
        if (this != &other)
        {
            age = other.age;
            name = other.name;
        }

        return *this;
    }
};