//������������- �� ��������� ���, ��� �������� ��'�������� ��� �� ������ �� ������� � ���� ����� �������-����/���������, � ������ �� �� ���� ��������� ������� ������������� ������� private i protected

//�����������- ��������� ���, ��� �������� ���������� ��� ����� �� ����� ��� ��������.

#include <iostream>


//������� 1.



//��������� �����������:

//class ��'�_����������_����� : �����������_����������� ��'�_������������_�����
//{
//	��������� �����
//}

struct Point
{

};

class Person
{

};

class Vehicle
{
private:
    Point position;
    double height;
    double lenght;
    double width;

protected:
    double weight;

public:
    void Move(Point direction);
    void Rotate(Point direction);
    void Scale(float factor);
};

class Car : public Vehicle
{
private:
    int doors;
    int tankCapacity;
    char model[30];
    char mark[30];
    bool isStarted;

public:
    void FillUp(int points)
    {
        weight += points;
    }
    void Start();
};

class Plane : public Vehicle
{
private:
    int seats;
    Point route[2];

public:
    void AuthorizePeople(const Person* peopleList);
    void Fly();
    void CallDispatcher(Person dispatcher);
};






//������� 2.

// ����������� ������ private - �� ��� ����� ������ ����� ������������ ������ ����� ����������� ���� � ������ ����� �����




class A
{
private:
    int value1;
    void Method1();

public:
    int value2;
    void Method2()
    {
        value1 = 10;
        Method1();
    }
};

int main()
{
    A object;
    object.Method2();
    return 0;
}







