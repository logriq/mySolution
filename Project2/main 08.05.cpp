#include <iostream>
#include <string>
#include <queue>
#include "Queue.h"

int main()
{
    Queue<double> myQueue;

    for (double value = 1.0; value < 3.0; value += 0.2)
    {
        myQueue.Push(value);
    }

    double& value = myQueue.Back();

    while (!myQueue.IsEmpty())
    {
        double value = myQueue.Front();
        std::cout << value << " ";
        myQueue.Pop();
    }

    Queue<double> myQueue2;
    for (double value = 5.0; value < 6.0; value += 0.3)
    {
        myQueue2.Push(value);
    }

    std::cout << "Size = " << myQueue2.Size();

    return 0;
    std::cout << "Hello World!\n";
}