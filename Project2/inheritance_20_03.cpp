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
class A {
private: //���� ��� ������ ����� �� ���� ����������� �� ����� ������ �����
    int value1;
    void method1();

protected: //�� ���� ������� ����� ���� ����������� �� ��� ���� ��� � ������ �����
    double weight;

public: //����-��: � ������ ����� � �� ������ �����������
    int value2;
    void method2();
};

//����������� � �������������
#include "Array.h"

class A
{
public:
    A() { std::cout << "A::A() \n"; }
    A(int a) { std::cout << "A::A(int a) \n"; }
    A(int a, int b) { std::cout << "A::A(int a, int b) \n"; }
    A(const A& other) { std::cout << "A::A(const A& other) \n"; }
};
class B : public A
{

public:
    B() : A() { std::cout << "B::B() \n"; }
    B(int a) : A(a) { std::cout << "B::B(int a) \n"; }
    B(int a, int b) : A(a, b) { std::cout << "B::B(int a, int b) \n"; }
    B(const B& other) : A(other) { std::cout << "B::B(const B& other) \n"; }
};

int main()
{
    A object;


    Array myArray(5);
    for (size_t i = 0; i < myArray.Size(); i++)
    {
        std::cout << myArray[i] << " ";
    }

    B object;


    std::cout << "Hello World!\n";
}