//Інкапсуляція- це концепція ООП, яка дозволяє об'єднувати дані та методи їх обробки в одну єдину сутність-клас/структура, і захищає їх від зовн втручання завдяки модифікаторам доступу private i protected

//Наслідування- концепція ООП, яка дозволяє створювати нові класи на основі вже існуючих.

#include <iostream>


//ЧАСТИНА 1.



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






//ЧАСТИНА 2.

// Модифікатор досупу private - до всіх членів ниижче цього модифікатора досупу можна доступатися лише з методів цього класу




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







