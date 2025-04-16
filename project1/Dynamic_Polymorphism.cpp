

//���� 170. ���������, ��������� � �����������


#include <iostream>
class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    const char* getName() { return "Parent"; }
    int getValue() { return m_value; }
};

class Child : public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }

    const char* getName() { return "Child"; }
    int getValueDoubled() { return m_value * 2; }
};

#include <iostream> 
#include <string>

class Animal
{
protected:
    std::string m_name;

    // �� ������ ��� ����������� protected, ���� �� �� ������, ��� ����������� ���������� ��'���� ����� Animal �������,
    // ��� ������, ��� � ������� ����� ������ ��� ��������
    Animal(std::string name)
        : m_name(name)
    {
    }

public:
    std::string getName() { return m_name; }
    const char* speak() { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {
    }

    const char* speak() { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {
    }

    const char* speak() { return "Woof"; }
};

int main()
{
    Cat cat("Matros");
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    Dog dog("Barsik");
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    Animal* pAnimal = &cat;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    return 0;
}

//���������, ��������� � ��������� �����
void report(Cat& cat)
{
    std::cout << cat.getName() << " says " << cat.speak() << '\n';
}

void report(Dog& dog)
{
    std::cout << dog.getName() << " says " << dog.speak() << '\n';
}
void report(Animal& rAnimal)
{
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}




//���� 171. ³������� ������� � ����������

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // �� ������ ��� ����������� protected, ���� �� �� ������, ��� ����������� ���� ��������� ���������� ��'���� ����� Animal �������,
    // ��� ������, ��� � ������� ������ ������ ��� ��������
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

void report(Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat("Matros");
    Dog dog("Barsik");

    report(cat);
    report(dog);
}



//���� 172. ������������ override � final




#include <iostream>

class A
{
public:
    virtual const char* getName1(int x) { return "A"; }
    virtual const char* getName2(int x) { return "A"; }
    virtual const char* getName3(int x) { return "A"; }
};

class B : public A
{
public:
    virtual const char* getName1(short int x) override { return "B"; }  // ������� ���������, ����� �� � ���������������
    virtual const char* getName2(int x) const override { return "B"; }  // ������� ���������, ����� �� � ���������������
    virtual const char* getName3(int x) override { return "B"; }  // ��� �����, ����� � ��������������� A::getName3(int)

};

int main()
{
    return 0;
}


//����������� final


class A
{
public:
    virtual const char* getName() { return "A"; }
};

class B : public A
{
public:
    // ������� final � ����? �� ������, �� ����� ������������� ��� �� �����
    virtual const char* getName() override final { return "B"; } // ��� �����, �������������� A::getName()
};

class C : public B
{
public:
    virtual const char* getName() override { return "C"; } // ������� ���������: �������������� ������ B::getName(), ���� � final
};




//����������� ��� ����������



#include <iostream>

class Parent
{
public:
    // ��� ����� getThis() ������� �������� �� ���� Parent
    virtual Parent* getThis() { std::cout << "called Parent::getThis()\n"; return this; }
    void printType() { std::cout << "returned a Parent\n"; }
};

class Child : public Parent
{
public:
    // ��������, ���� ���������� ������������� � ���������� ������� ������������ ����� ������ ���������.
    // �����, ������� Child ������ ���� Parent, ��������� ����� ���� ��������� Child* ������ Parent*
    virtual Child* getThis() { std::cout << "called Child::getThis()\n";  return this; }
    void printType() { std::cout << "returned a Child\n"; }
};

int main()
{
    Child ch;
    Parent* p = &ch;
    ch.getThis()->printType(); // ����������� Child::getThis(), ����������� Child*, ����������� Child::printType()
    p->getThis()->printType(); // ����������� Child::getThis(), ����������� Parent*, ����������� Parent::printType()
}





//���� 173. ³������� ����������� � ³�������� ������������



//³������� �����������


#include <iostream>

class Parent
{
public:
    ~Parent() // �������: ���������� �� ����������
    {
        std::cout << "Calling ~Parent()" << std::endl;
    }
};

class Child : public Parent
{
private:
    int* m_array;

public:
    Child(int length)
    {
        m_array = new int[length];
    }

    ~Child() // �������: ���������� �� ����������
    {
        std::cout << "Calling ~Child()" << std::endl;
        delete[] m_array;
    }
};

int main()
{
    Child* child = new Child(7);
    Parent* parent = child;
    delete parent;

    return 0;
}




//³�������� ������������



//class Parent
//{
//public:
//    virtual const char* getName() { return "Parent"; }
//};
//
//class Child : public Parent
//{
//public:
//    virtual const char* getName() { return "Child"; }
//};



#include <iostream>

int main()
{
    Child child;
    Parent& parent = child;

    // ������ Parent::GetName() ������ �������������� Child::GetName()
    std::cout << parent.Parent::getName() << std::endl;
}


//���� 174. ���� � ϳ�� ����������


void printValue(int value)
{
    std::cout << value;
}

void example1()
{
    printValue(7);
}

int add1(int a, int b) { return a + b; }
int subtract1(int a, int b) { return a - b; }
int multiply1(int a, int b) { return a * b; }

void example2()
{
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;

    int b;
    std::cout << "Enter another number: ";
    std::cin >> b;

    int op;
    do
    {
        std::cout << "Enter an operation (0 = add, 1 = subtract, 2 = multiply): ";
        std::cin >> op;
    } while (op < 0  op > 2);

    int result = 0;
    switch (op)
    {
    case 0: result = add1(a, b); break;
    case 1: result = subtract1(a, b); break;
    case 2: result = multiply1(a, b); break;
    }

    std::cout << "The answer is: " << result << std::endl;
}

int add2(int a, int b) { return a + b; }

void example3()
{
    int (*pFcn)(int, int) = add2;
    std::cout << pFcn(4, 5) << std::endl;
}

int add3(int a, int b) { return a + b; }
int subtract3(int a, int b) { return a - b; }
int multiply3(int a, int b) { return a * b; }

void example4()
{
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;

    int b;
    std::cout << "Enter another number: ";
    std::cin >> b;

    int op;
    do
    {
        std::cout << "Enter an operation (0 = add, 1 = subtract, 2 = multiply): ";
        std::cin >> op;
    } while (op < 0 op > 2);

    int (*pFcn)(int, int) = nullptr;

    switch (op)
    {
    case 0: pFcn = add3; break;
    case 1: pFcn = subtract3; break;
    case 2: pFcn = multiply3; break;
    }

    std::cout << "The answer is: " << pFcn(a, b) << std::endl;
}

//���� 175. ³������� �������

class Base
{
public:
    virtual void function1() {}
    virtual void function2() {}
};
class Derived1 : public Base
{
public:
    virtual void function1() {}
};

class Derived2 : public Base
{
public:
    virtual void function2() {}
};

void example1()
{
    Derived1 objDerived1;
}

void example2()
{
    Derived1 objDerived1;
    Base* basePtr = &objDerived1;
    basePtr->function1();
}

void example3()
{
    Base objBase;
    Base* basePtr = &objBase;
    basePtr->function1();
}

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

//
//
//


//г����� � ����������� ����� ��������� ������� :

#include <iostream>
#include <string>

class Animal // ��� Animal � ����������� ����������� ������
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // ������� �����, speak() � ������ ���������� ��������
};

//
//

class Lion : public Animal
{
public:
    Lion(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() { return "RAWRR!"; }
};

int main()
{
    Lion lion("John");
    std::cout << lion.getName() << " says " << lion.speak() << '\n';
}




//���� �������� ������� � ������������


#include <iostream>
#include <string>

class Animal // �� ����������� ����������� ����
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // ������� �����, speak() � ������ ���������� ��������
};

const char* Animal::speak()
{
    return "buzz"; // ��������� �� �������������
}

class Dragonfly : public Animal
{

public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() // ��� ���� ��� �� � �����������, ���� �� �� ������������� ������� speak()
    {
        return Animal::speak(); // ��������������� ��������� �� ������������� ����� Animal
    }
};

int main()
{
    Dragonfly dfly("Barbara");
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
}





//����������

//��������� � �� ����, ���� �� �� ������ - ����� � �� ������ ����� � ������� ����������� ���������!
//���������� �� ��������� �������� - ������������ ��� �������������� �������. �������� ��������� � '�'


#include <cmath> // ��� sqrt()

double mySqrt(double value, IErrorLog& log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0");
        return 0.0;
    }
    else
        return sqrt(value);
}








//���� 177. ³��������� ������� ����

//����� �����


class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power)
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power)
    {
    }
};




//³������� ����� �����

#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice // �������: PoweredDevice ����� ���������� ������� ����
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // ��� ����� ���������� ��� ��������� ��'���� ����� Scanner, ��� � ��� ������� �� ����������
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice // �������: PoweredDevice ����� ���������� ������� ����
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // ��� ����� ���������� ��� ��������� ��'���� ����� Printer, ��� � ��� ������� �� ����������
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PoweredDevice(power) // �������� PoweredDevice ���������� ���
    {
    }
};

int main()
{
    Copier copier(1, 2, 3);
}





//���� 178. ������ �ᒺ���


#include <iostream>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual const char* getName() const { return "Parent"; }
    int getValue() const { return m_value; }
};

class Child : public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }

    virtual const char* getName() const { return "Child"; }
};

int main()
{
    Child child(7);
    std::cout << "child is a " << child.getName() << " and has value " << child.getValue() << '\n';

    Parent& ref = child;
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Parent* ptr = &child;
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    return 0;
}



//������ �ᒺ��� � �������



void printName(const Parent& parent) // �������: �������� �� ���������
{
    std::cout << "I am a " << parent.getName() << '\n';
}

int main()
{
    Child ch(7);
    printName(ch);

    return 0;
}



//������ �������



#include <vector>

//int main()
//{
//    std::vector<Parent*> v;
//    v.push_back(new Parent(7)); // ������ ��'��� ����� Parent � ��� ������
//    v.push_back(new Child(8)); // ������ ��'��� ����� Child � ��� ������
//
//    // �������� �� �������� ������ �������
//    for (int count = 0; count < v.size(); ++count)
//        std::cout << "I am a " << v[count]->getName() << " with value " << v[count]->getValue() << "\n";
//
//    for (int count = 0; count < v.size(); ++count)
//        delete v[count];
//
//    return 0;
//}

#include <vector>
#include <functional> // ��� std::reference_wrapper

int main()
{
    std::vector<std::reference_wrapper<Parent> > v;
    Parent p(7); // p � ch �� ������ ���� ��������� ��'������
    Child ch(8);
    v.push_back(p); // ������ ��'��� ����� Parent � ��� ������
    v.push_back(ch); // ������ ��'��� ����� Child � ��� ������

    // �������� �� �������� ������ �������
    for (int count = 0; count < v.size(); ++count)
        std::cout << "I am a " << v[count].get().getName() << " with value " << v[count].get().getValue() << "\n"; // ������������� .get() ��� ��������� �������� � std::reference_wrapper


    return 0;
}




//���� 179. �������� ���������� ����. �������� dynamic_cast

#include <iostream>
#include <string>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual ~Parent() {}
};

class Child : public Parent
{
protected:
    std::string m_name;

public:
    Child(int value, std::string name)
        : Parent(value), m_name(name)
    {
    }

    const std::string& getName() { return m_name; }
};

Parent* getObject(bool bReturnChild)
{
    if (bReturnChild)
        return new Child(1, "Banana");
    else
        return new Parent(2);
}

int main()
{
    Parent* p = getObject(true);

    // �� �� �������� ��'� ��'���� ����� Child ���, ����� ���� ���� �������� ����� Parent?

    delete p;

    return 0;
}

//����������� ����������� ����� dynamic_cast


int main()
{
    Parent* p = getObject(true);

    Child* ch = dynamic_cast<Child*>(p); // ������������� dynamic_cast ��� ����������� ��������� ����� Parent � �������� ����� Child

    if (ch) // �������� �������� ch �� �������� ��������
        std::cout << "The name of the Child is: " << ch->getName() << '\n';

    delete p;

    return 0;
}

///�������: ������ ��������� �������� ���������� ���������� ���������� �� �������� ��������.



//��������� ���������� � �������� static_cast


#include <iostream>
#include <string>

// �������������� �����
enum ClassID
{
    PARENT,
    CHILD
    // ��� ����� ������ �� ����� �����
};

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual ~Parent() {}
    virtual ClassID getClassID() { return PARENT; }
};

class Child : public Parent
{
protected:
    std::string m_name;

public:
    Child(int value, std::string name)
        : Parent(value), m_name(name)
    {
    }

    std::string& getName() { return m_name; }
    virtual ClassID getClassID() { return CHILD; }

};

Parent* getObject(bool bReturnChild)
{
    if (bReturnChild)
        return new Child(1, "Banana");
    else
        return new Parent(2);
}

int main()
{
    Parent* p = getObject(true);

    if (p->getClassID() == CHILD)
    {
        // �� ��� ������, �� p ����� �� ��'��� ����� Child, ���� ����� ������� ��� �� ������� ����
        Child* ch = static_cast<Child*>(p);
        std::cout << "The name of the Child is: " << ch->getName() << '\n';
    }

    delete p;

    return 0;
}



//�������� dynamic_cast � ���������


#include <iostream>
#include <string>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual ~Parent() {}
};

class Child : public Parent
{
protected:
    std::string m_name;

public:
    Child(int value, std::string name)
        : Parent(value), m_name(name)
    {
    }

    const std::string& getName() { return m_name; }
};

int main()
{
    Child banana(1, "Banana");
    Parent& p = banana;
    Child& ch = dynamic_cast<Child&>(p); // ������������� �������� dynamic_cast ��� ����������� ��������� ����� Parent � ��������� ����� Child

    std::cout << "The name of the Child is: " << ch.getName() << '\n';

    return 0;
}#include <iostream>
#include <string>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual ~Parent() {}
};

class Child : public Parent
{
protected:
    std::string m_name;

public:
    Child(int value, std::string name)
        : Parent(value), m_name(name)
    {
    }

    const std::string& getName() { return m_name; }
};

int main()
{
    Child banana(1, "Banana");
    Parent& p = banana;
    Child& ch = dynamic_cast<Child&>(p); // ������������� �������� dynamic_cast ��� ����������� ��������� ����� Parent � ��������� ����� Child

    std::cout << "The name of the Child is: " << ch.getName() << '\n';

    return 0;
}


//������� � ��� C++ �� ���� ���������� ����������, �� dynamic_cast �� ���� ��������� �������� ���������� ��� ���. 
// ������ �����, dynamic_cast ������ ������� ���� std::bad_cast 






//���� 180.���� �ᒺ��� ����� ����� �������� ������

//�������� � ��������������� operator<<

#include <iostream>

class Parent
{
public:
    Parent() {}

    virtual void print() const { std::cout << "Parent"; }
};

class Child : public Parent
{
public:
    Child() {}

    virtual void print() const override { std::cout << "Child"; }
};

int main()
{
    Child ch;
    Parent& p = ch;
    p.print(); // ����������� Child::print()

    return 0;
}


//����� ����� ������ ���������, ��� � std::cout �� ���� ����� ��������� :

int main()
{
    Child ch;
    Parent& p = ch;

    std::cout << "p is a ";
    p.print(); // ��������� ��������� cout ������ ������� print(). ���������!
    std::cout << '\n';

    return 0;
}






//�� ������ �� ������� operator<< ����������?


include <iostream>

class Parent
{
public:
    Parent() {}

    // �������������� ��������� ������ <<
    friend std::ostream& operator<<(std::ostream& out, const Parent& p)
    {
        // �������� ��������� �������� ������ ������ print()
        return p.print(out);
    }

    // ������ ����� print() ����������
    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Parent";
        return out;
    }
};

class Child : public Parent
{
public:
    Child() {}

    // �������������� ������ print() ��� ������ � ��'������ ����� Child
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Child";
        return out;
    }
};

int main()
{
    Parent p;
    std::cout << p << '\n';

    Child ch;
    std::cout << ch << '\n'; // ������� �����, ��� ������ ����� ��� �������� �������������� ��������� ������ � ���� Child

    Parent& pref = ch;
    std::cout << pref << '\n';

    return 0;
}