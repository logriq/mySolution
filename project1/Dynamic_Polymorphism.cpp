// Урок 176. Чисті віртуальні функції, Інтерфейси та Абстрактні класи


// Абстрактні функції і класи

class Parent
{
public:
    const char* sayHi() { return "Hi"; } // звичайна невіртуальна функція

    virtual const char* getName() { return "Parent"; } // звичайна віртуальна функція

    virtual int getValue() = 0; // чиста віртуальна функція

    int doSomething() = 0; // помилка компіляції: заборонено присвоювати невіртуальним функціям значення 0
};

//Таким чином, ми повідомляємо компілятору: «Реалізацією цієї функції займуться дочірні класи».




int main()
{
    Parent parent; // ми не можемо створювати об'єкти абстрактного класу, але заради експерименту уявіть, що це можливо
    parent.getValue(); // який результат виконання цього рядка коду?
}
// Оскільки ми не визначали метод getValue(), то який результат виконання parent.getValue() ?






//Приклад чистої віртуальної функції


#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // Ми зробили цей конструктор protected, тому що не хочемо, щоб користувачі могли створювати об'єкти класу Animal напряму,
    // але хочемо, щоб ця можливість залишалася в дочірніх класах
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

    // Ми забули перевизначити метод speak()
};

int main()
{
    Lion lion("John");
    std::cout << lion.getName() << " says " << lion.speak() << '\n';
}