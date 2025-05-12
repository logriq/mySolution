#include <iostream>
#include "Stack.h"

int main()
{
    std::cout << "Enter size of stack: ";
    int size;
    std::cin >> size;
    Stack myStack;

    std::cout << (myStack.IsEmpty() ? "Stack is empty" : "Stack is not empty");
    std::cout << "Max size" << myStack.MaxSize() << std::endl;

    for (int value = 0; value < 10; value++)
    {
        if (myStack.Push(value))
        {
            std::cout << value << "was pushed\n";
        }
        else
        {
            std::cout << value << "wasn`t pushed\n";
        }
    }

    std::cout << "Size = " << myStack.Size() << std::endl;

    while (!myStack.IsEmpty())
    {
        std::cout << myStack.Top() << " ";
        myStack.Pop();
    }
}