//1. ������� �����������

//��������, �� ����������� ���������� ���������� ����� � ���������� ��� :
Derived d;
Base* p = &d;
p->show();




#include <iostream>

class Base {
public:
    virtual ~Base() { // ������� ���������� ����������
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
    Derived d;  // ��� ����������� ������������ ���������

    Base* p = &d;
    p->show();   // ������� "Derived show", �� ����� ����������

    return 0;
}



//���� �������� virtual ����� ~Base(), �� ��� �������� ����� Base* ���������� Derived �� �������.





