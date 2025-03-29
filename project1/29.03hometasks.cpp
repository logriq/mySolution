//1. Виклики деструкторів

//Дослідити, чи викликається деструктор дочірнього класу у наступному коді :
Derived d;
Base* p = &d;
p->show();




#include <iostream>

class Base {
public:
    virtual ~Base() { // Зробимо деструктор віртуальним
        std::cout << "Base destructor\n";
    }
    virtual void show() {
        std::cout << "Base show\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
    void show() override {
        std::cout << "Derived show\n";
    }
};

int main() {
    Derived d;  // Тут деструктори викликаються нормально

    Base* p = &d;
    p->show();   // Викличе "Derived show", бо метод віртуальний

    return 0;
}



//Якщо прибрати virtual перед ~Base(), то при видаленні через Base* деструктор Derived не спрацює.








//2.Як заборонити копіювання та переміщення для класу?  Підказка: як використовувтаи  "= delete"?


class NonCopyable {
public:
    NonCopyable() = default;

    // Забороняємо копіювання
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    // Забороняємо переміщення
    NonCopyable(NonCopyable&&) = delete;
    NonCopyable& operator=(NonCopyable&&) = delete;
};
