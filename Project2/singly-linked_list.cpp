#include <iostream>
#include "List.h"

int main()
{
    List list1;

    for (size_t i = 0; i < 10; i++)
    {
        list1.PushFront(i);
    }

    for (List::Iterator iterator = list1.Begin(); iterator != list1.End(); ++iterator)
    {
        std::cout << *iterator << std::endl;
    }

    return 0;
}