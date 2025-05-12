#pragma once


class Stack
{
private:
    static const size_t MAX_SIZE = 10;
    int stack[MAX_SIZE] = {};
    int top = -1;

public:
    bool Push(const int& value);
    void Pop();
    int& Top();
    bool IsFull() const;
    bool IsEmpty() const;
    size_t MaxSize() const;
    size_t Size() const;

    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();
};