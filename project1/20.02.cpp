#include <iostream>

/*����� ���*/
// C++ -> ��'�����-��������� �������������
//����� � ��'����


 //����������� �������������
//������� ������� / ������� �����

//���������� ������
//���������� ������ - ������ �� �� ������ ��� �����

#include "Rectangle.h"

void Show(const Rectangle& rectangle);

//����/��'��� 
//���� ���� ����� � ��������, ��� �� ���� ��� ������� � �������
/*class ��'������
{
    ����� �����
};
*/
#include <cstring>
class Student1
{
private: //���������� �������
    char name[20];
    int age;

public: //����������� ������� 
    void Show()
    {
        std::cout << "Name :" << name << std::endl;
        std::cout << "Age :" << age << std::endl;
    }
    void ChangeAge(int newAge)
    {
        age = newAge;
    }
    void ChangeName(const char* newName)
    {
        strcpy_s(name, 20, newName);
        if (newAge > 0)
        {
            age = newAge;
        }
        else
        {
            std::cout << "New Age is incorrect.\n";
        }
    }
};

int main()
{

    /*Rectangle one;
    one.setHeight(20);
    one.setWidth(30);
    Show(one);*/
    Rectangle one1;
    Rectangle& ref1 = one1;
    Rectangle* ptr1 = &one1;
    Rectangle arr1[3];


    const Rectangle one1;
    const Rectangle& ref1 = one1;
    const Rectangle* ptr1 = &one1;
    const Rectangle arr1[3];

    const Rectangle one;
    Show(one);

    return 0;

    std::cout << "Hello World!\n";

    //��'����/�����
    Student1 Demien;
    Student1 olga;

    Demien.ChangeAge(24);
    Demien.ChangeName("Demien");

    olga.ChngeAge(25);
    olga.ChangeName("Olga");

}

void Show(const Rectangle& rectangle)
{
    std::cout << "Height = " << rectangle.getHeight() << std::endl;
    //std::cout << "Width = " << rectangle.getWidth() << std::endl;
}