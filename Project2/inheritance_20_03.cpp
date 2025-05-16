////������������- �� ��������� ���, ��� �������� ��'�������� ��� �� ������ �� ������� � ���� ����� �������-����/���������, � ������ �� �� ���� ��������� ������� ������������� ������� private i protected
//
////�����������- ��������� ���, ��� �������� ���������� ��� ����� �� ����� ��� ��������.
//
#include <iostream>
//
//
////������� 1.
//
//
//
////��������� �����������:
//
////class ��'�_����������_����� : �����������_����������� ��'�_������������_�����
////{
////	��������� �����
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
////������� 2.
//
//// ����������� ������ private - �� ��� ����� ������ ����� ������������ ������ ����� ����������� ���� � ������ ����� �����
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








//����������� ������� protected
    //����������� ������� - �����������, ���� ���������� �������� ������� ������� �� ������� ����� �����
//class A {
//private: //���� ��� ������ ����� �� ���� ����������� �� ����� ������ �����
//    int value1;
//    void method1();
//
//protected: //�� ���� ������� ����� ���� ����������� �� ��� ���� ��� � ������ �����
//    double weight;
//
//public: //����-��: � ������ ����� � �� ������ �����������
//    int value2;
//    void method2();
//};
//
////����������� � �������������
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
// ������������ �����������:
//               A -> private member | A -> protected member | A -> public member
// private A   : private member      | private member        | private member
// protected A : private member      | protected member      | protected member
// public A    : private member      | protected member      | public member


//³������� ��� ���������� � ������
#include <stdio.h>

struct Point
{
private:
    double x = double();
    double y = double();
public:
    Point(int x = 0, int y = 0);
};
//� struct ��� ����������� ��� � public, � � class ��� ���������� � private
int main(void)
{
    struct Point origin { 10, 20 };

    printf("Hello orld");
    return 0;
}

//��������� ���������� �����������
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