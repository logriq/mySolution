////Інкапсуляція- це концепція ООП, яка дозволяє об'єднувати дані та методи їх обробки в одну єдину сутність-клас/структура, і захищає їх від зовн втручання завдяки модифікаторам доступу private i protected
//
////Наслідування- концепція ООП, яка дозволяє створювати нові класи на основі вже існуючих.
//
#include <iostream>
//
//
////ЧАСТИНА 1.
//
//
//
////Синтаксис наслідування:
//
////class Ім'я_Дочірнього_Класу : Модифікатор_Наслудівання Ім'я_Батьківського_Класу
////{
////	Реалізвція Класу
////}
//
//struct Point
//{
//
//};
//
//class Person
//{
//
//};
//
//class Vehicle
//{
//private:
//    Point position;
//    double height;
//    double lenght;
//    double width;
//
//protected:
//    double weight;
//
//public:
//    void Move(Point direction);
//    void Rotate(Point direction);
//    void Scale(float factor);
//};
//
//class Car : public Vehicle
//{
//private:
//    int doors;
//    int tankCapacity;
//    char model[30];
//    char mark[30];
//    bool isStarted;
//
//public:
//    void FillUp(int points)
//    {
//        weight += points;
//    }
//    void Start();
//};
//
//class Plane : public Vehicle
//{
//private:
//    int seats;
//    Point route[2];
//
//public:
//    void AuthorizePeople(const Person* peopleList);
//    void Fly();
//    void CallDispatcher(Person dispatcher);
//};
//
//
//
//
//
//
////ЧАСТИНА 2.
//
//// Модифікатор досупу private - до всіх членів ниижче цього модифікатора досупу можна доступатися лише з методів цього класу
//
//
//
//
//class A
//{
//private:
//    int value1;
//    void Method1();
//
//public:
//    int value2;
//    void Method2()
//    {
//        value1 = 10;
//        Method1();
//    }
//};
//
//int main()
//{
//    A object;
//    object.Method2();
//    return 0;
//}








//Модифікатор доступу protected
    //модифікатор доступу - модифікатор, який встановлює відповідно правила доступу до певного члену класу
//class A {
//private: //ніхто крім нашого класу не може поступиться до членів нашого класу
//    int value1;
//    void method1();
//
//protected: //до цієї частини класу може поступиться як цей клас так і дочірні класи
//    double weight;
//
//public: //будь-які: і методи класи і тд можуть посутпиться
//    int value2;
//    void method2();
//};
//
////Наслідування і конструуктори
//#include "Array.h"
//
//class A
//{
//public:
//    A() { std::cout << "A::A() \n"; }
//    A(int a) { std::cout << "A::A(int a) \n"; }
//    A(int a, int b) { std::cout << "A::A(int a, int b) \n"; }
//    A(const A& other) { std::cout << "A::A(const A& other) \n"; }
//};
//class B : public A
//{
//
//public:
//    B() : A() { std::cout << "B::B() \n"; }
//    B(int a) : A(a) { std::cout << "B::B(int a) \n"; }
//    B(int a, int b) : A(a, b) { std::cout << "B::B(int a, int b) \n"; }
//    B(const B& other) : A(other) { std::cout << "B::B(const B& other) \n"; }
//};
//
//int main()
//{
//    A object;
//
//
//    Array myArray(5);
//    for (size_t i = 0; i < myArray.Size(); i++)
//    {
//        std::cout << myArray[i] << " ";
//    }
//
//    B object;
//
//
//    std::cout << "Hello World!\n";
//}




int main()
{
    A objectA;
    B objectB;
    C objectC;

    objectA.A_Private_Method();
    objectA.A_Protected_Method();
    objectA.A_Public_Method();

    objectB.B_Private_Method();
    objectB.B_Protected_Method();
    objectB.B_Public_Method();

    objectC.C_Private_Method();
    objectC.C_Protected_Method();
    objectC.C_Public_Method();
}
// Модифікатори наслідування:
//               A -> private member | A -> protected member | A -> public member
// private A   : private member      | private member        | private member
// protected A : private member      | protected member      | protected member
// public A    : private member      | protected member      | public member


//Відмінність муж структурою і класом
#include <stdio.h>

struct Point
{
private:
    double x = double();
    double y = double();
public:
    Point(int x = 0, int y = 0);
};
//в struct при замовчуванні йде в public, а у class при замовучанні у private
int main(void)
{
    struct Point origin { 10, 20 };

    printf("Hello orld");
    return 0;
}

//Реалізація множинного наслідування
class Student
{
private:
    int course;
    double scholarship;
    int subjects;

public:
    Student(int curse, double scholarship, int subjects)
        :curse(curse), scholarship(scholarship), subjects(subjects)
    {
    }

    int GetCourse() const { return course; }
};

class Suit {};

class Waiter
{
private:
    Suit suit;
    double salary;
    const char* company;

public:
    Waiter(double salary, const char* company)
        : salary(salary), company(company)
    {
    }
    double Salary() const { return salary; }

};

class StudentWaiter : public Student, public Waiter
{
private:
    int daysToDeath;

public:
    StudentWaiter(int daysToDeath, int curse, double scholarship, int subjects)
        :daysToDeath(daysToDeath)
    {
    }
};