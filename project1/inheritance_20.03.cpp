//Інкапсуляція- це концепція ООП, яка дозволяє об'єднувати дані та методи їх обробки в одну єдину сутність-клас/структура, і захищає їх від зовн втручання завдяки модифікаторам доступу private i protected

//Наслідування- концепція ООП, яка дозволяє створювати нові класи на основі вже існуючих.

#include <iostream>
//Синтаксис наслідування:

//class Ім'я_Дочірнього_Класу : Модифікатор_Наслудівання Ім'я_Батьківського_Класу
//{
//	Реалізвція Класу
//}

struct Point
{

};

class Person
{

};

class Vehicle
{
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
    void FillUp(int points);
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

int main()
{
    Car car;
    Plane plane;

    plane.Move();
    return 0;
}


