#pragma once
#include <string>

class Person
{
public:
    Person()
        : age(1), name("Unknown")
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
    }

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            std::cout << "copy operator=\n";
            age = other.age;
            name = other.name;
        }
        return *this;
    }

    Person& operator=(Person&& other) noexcept
    {
        if (this != &other)
        {
            std::cout << "move operator=\n";
            age = std::move(other.age);
            name = std::move(other.name);
        }
        return *this;
    }

    ~Person()
    {
        std::cout << "Destructor\n";
    }

    void ShowInfo() const
    {
        std::cout << "(age = " << age << ", name = " << name << ")\n";
    }

    const std::string& Name() const
    {
        return name;
    }

private:
    int age;
    std::string name;
};