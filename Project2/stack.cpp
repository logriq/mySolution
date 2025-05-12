#include "Stack.h"

bool Stack::Push(const int& value)
{
    if (!IsFull()) {
        top++;
        stack[top] = value;
        return true;
    }
    return false;
}

void Stack::Pop() {
    if (!IsEmpty()) {
        top--;
    }
}

int& Stack::Top() {
    return stack[top];
}

bool Stack::IsFull() const {
    return top == MAX_SIZE - 1;
}

bool Stack::IsEmpty() const {
    return top == -1;
}

size_t Stack::MaxSize() const {
    return MAX_SIZE;
}

size_t Stack::Size() const
{
    return top + 1;
}