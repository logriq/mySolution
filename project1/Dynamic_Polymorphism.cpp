

//Урок 170. Вказівники, Посилання і Спадкування


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

    // Ми робимо цей конструктор protected, тому що не хочемо, щоб користувачі створювали об'єкти класу Animal напряму,
    // але хочемо, щоб у дочірніх класів доступ був відкритий
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

//Вказівники, посилання і батьківські класи
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




//Урок 171. Віртуальні функції і Поліморфізм

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // Ми робимо цей конструктор protected, тому що не хочемо, щоб користувачі мали можливість створювати об'єкти класу Animal напряму,
    // але хочемо, щоб в дочірніх класах доступ був відкритий
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



//Урок 172. Модифікатори override і final




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
    virtual const char* getName1(short int x) override { return "B"; }  // помилка компіляції, метод не є перевизначенням
    virtual const char* getName2(int x) const override { return "B"; }  // помилка компіляції, метод не є перевизначенням
    virtual const char* getName3(int x) override { return "B"; }  // все добре, метод є перевизначенням A::getName3(int)

};

int main()
{
    return 0;
}


//Модифікатор final


class A
{
public:
    virtual const char* getName() { return "A"; }
};

class B : public A
{
public:
    // Помітили final в кінці? Це означає, що метод перевизначити вже не можна
    virtual const char* getName() override final { return "B"; } // все добре, перевизначення A::getName()
};

class C : public B
{
public:
    virtual const char* getName() override { return "C"; } // помилка компіляції: перевизначення методу B::getName(), який є final
};




//Коваріантний тип повернення



#include <iostream>

class Parent
{
public:
    // Цей метод getThis() повертає вказівник на клас Parent
    virtual Parent* getThis() { std::cout << "called Parent::getThis()\n"; return this; }
    void printType() { std::cout << "returned a Parent\n"; }
};

class Child : public Parent
{
public:
    // Зазвичай, типи повернення перевизначень і віртуальних функцій батьківського класу повинні співпадати.
    // Однак, оскільки Child наслідує клас Parent, наступний метод може повертати Child* замість Parent*
    virtual Child* getThis() { std::cout << "called Child::getThis()\n";  return this; }
    void printType() { std::cout << "returned a Child\n"; }
};

int main()
{
    Child ch;
    Parent* p = &ch;
    ch.getThis()->printType(); // викликається Child::getThis(), повертається Child*, викликається Child::printType()
    p->getThis()->printType(); // викликається Child::getThis(), повертається Parent*, викликається Parent::printType()
}





//Урок 173. Віртуальні деструктори і Віртуальне присвоювання



//Віртуальні деструктори


#include <iostream>

class Parent
{
public:
    ~Parent() // примітка: Деструктор не віртуальний
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

    ~Child() // примітка: Деструктор не віртуальний
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




//Віртуальне присвоювання



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

    // Виклик Parent::GetName() замість перевизначення Child::GetName()
    std::cout << parent.Parent::getName() << std::endl;
}


//Урок 174. Раннє і Пізнє зв’язування


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

//Урок 175. Віртуальні таблиці

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

//
//
//


//Рішення — використати чисту віртуальну функцію :

#include <iostream>
#include <string>

class Animal // цей Animal є абстрактним батьківським класом
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // зверніть увагу, speak() є чистою віртуальною функцією
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




//Чисті віртуальні функції з визначеннями


#include <iostream>
#include <string>

class Animal // це абстрактний батьківський клас
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // зверніть увагу, speak() є чистою віртуальною функцією
};

const char* Animal::speak()
{
    return "buzz"; // реалізація за замовчуванням
}

class Dragonfly : public Animal
{

public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() // цей клас вже не є абстрактним, тому що ми перевизначили функцію speak()
    {
        return Animal::speak(); // використовується реалізація за замовчуванням класу Animal
    }
};

int main()
{
    Dragonfly dfly("Barbara");
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
}





//Інтерфейси

//Інтерфейс — це клас, який не має змінних - членів і всі методи якого є чистими віртуальними функціями!
//Інтерфейси ще називають «класами - інтерфейсами» або «інтерфейсними класами». зазвичай називають з 'І'


#include <cmath> // для sqrt()

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








//Урок 177. Віртуальний базовий клас

//Алмаз смерті


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




//Віртуальні базові класи

#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice // примітка: PoweredDevice тепер віртуальний базовий клас
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // цей рядок необхідний для створення об'єктів класу Scanner, але в цій програмі він ігнорується
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice // примітка: PoweredDevice тепер віртуальний базовий клас
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // цей рядок необхідний для створення об'єктів класу Printer, але в цій програмі він ігнорується
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PoweredDevice(power) // побудова PoweredDevice виконується тут
    {
    }
};

int main()
{
    Copier copier(1, 2, 3);
}





//Урок 178. Обрізка об’єктів


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



//Обрізка об’єктів і функції



void printName(const Parent& parent) // примітка: Передача по посиланню
{
    std::cout << "I am a " << parent.getName() << '\n';
}

int main()
{
    Child ch(7);
    printName(ch);

    return 0;
}



//Обрізка векторів



#include <vector>

//int main()
//{
//    std::vector<Parent*> v;
//    v.push_back(new Parent(7)); // додаємо об'єкт класу Parent в наш вектор
//    v.push_back(new Child(8)); // додаємо об'єкт класу Child в наш вектор
//
//    // Виводимо всі елементи нашого вектора
//    for (int count = 0; count < v.size(); ++count)
//        std::cout << "I am a " << v[count]->getName() << " with value " << v[count]->getValue() << "\n";
//
//    for (int count = 0; count < v.size(); ++count)
//        delete v[count];
//
//    return 0;
//}

#include <vector>
#include <functional> // для std::reference_wrapper

int main()
{
    std::vector<std::reference_wrapper<Parent> > v;
    Parent p(7); // p і ch не можуть бути анонімними об'єктами
    Child ch(8);
    v.push_back(p); // додаємо об'єкт класу Parent в наш вектор
    v.push_back(ch); // додаємо об'єкт класу Child в наш вектор

    // Виводимо всі елементи нашого вектора
    for (int count = 0; count < v.size(); ++count)
        std::cout << "I am a " << v[count].get().getName() << " with value " << v[count].get().getValue() << "\n"; // використовуємо .get() для отримання елементів з std::reference_wrapper


    return 0;
}




//Урок 179. Динамічне приведення типів. Оператор dynamic_cast

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

    // Як ми виведемо ім'я об'єкта класу Child тут, маючи лише один вказівник класу Parent?

    delete p;

    return 0;
}

//Неможливість конвертації через dynamic_cast


int main()
{
    Parent* p = getObject(true);

    Child* ch = dynamic_cast<Child*>(p); // використовуємо dynamic_cast для конвертації вказівника класу Parent у вказівник класу Child

    if (ch) // виконуємо перевірку ch на нульовий вказівник
        std::cout << "The name of the Child is: " << ch->getName() << '\n';

    delete p;

    return 0;
}

///Правило: Завжди виконуйте перевірку результату динамічного приведення на нульовий вказівник.



//Понижуюче приведення і оператор static_cast


#include <iostream>
#include <string>

// Ідентифікатори класів
enum ClassID
{
    PARENT,
    CHILD
    // Тут можна додати ще кілька класів
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
        // Ми вже довели, що p вказує на об'єкт класу Child, тому ніяких проблем тут не повинно бути
        Child* ch = static_cast<Child*>(p);
        std::cout << "The name of the Child is: " << ch->getName() << '\n';
    }

    delete p;

    return 0;
}



//Оператор dynamic_cast і Посилання


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
    Child& ch = dynamic_cast<Child&>(p); // використовуємо оператор dynamic_cast для конвертації посилання класу Parent в посилання класу Child

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
    Child& ch = dynamic_cast<Child&>(p); // використовуємо оператор dynamic_cast для конвертації посилання класу Parent в посилання класу Child

    std::cout << "The name of the Child is: " << ch.getName() << '\n';

    return 0;
}


//Оскільки в мові C++ не існує «нульового посилання», то dynamic_cast не може повернути «нульове посилання» при збої. 
// Замість цього, dynamic_cast генерує виняток типу std::bad_cast 






//Урок 180.Вивід об’єктів класів через оператор виводу

//Проблема з перевизначенням operator<<

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
    p.print(); // викликається Child::print()

    return 0;
}


//Такий спосіб виводу непоганий, але з std::cout не дуже добре поєднується :

int main()
{
    Child ch;
    Parent& p = ch;

    std::cout << "p is a ";
    p.print(); // розриваємо стейтмент cout заради функції print(). Непорядок!
    std::cout << '\n';

    return 0;
}






//Чи можемо ми зробити operator<< віртуальним?


include <iostream>

class Parent
{
public:
    Parent() {}

    // Перевантаження оператора виводу <<
    friend std::ostream& operator<<(std::ostream& out, const Parent& p)
    {
        // Делегуємо виконання операції виводу методу print()
        return p.print(out);
    }

    // Робимо метод print() віртуальним
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

    // Перевизначення методу print() для роботи з об'єктами класу Child
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
    std::cout << ch << '\n'; // зверніть увагу, все працює навіть без наявності перевантаження оператора виводу в класі Child

    Parent& pref = ch;
    std::cout << pref << '\n';

    return 0;
}