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





