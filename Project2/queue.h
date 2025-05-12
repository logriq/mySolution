#pragma once
#include <list>

template <typename T>
class Queue
{
private:
    List<T> list;

public:
    Queue() = default;
    Queue(const Queue& other) = default;
    Queue(Queue&& other) noexcept = default;
    ~Queue() = default;
    Queue& operator=(const Queue& other) = default;
    Queue& operator=(Queue&& other) noexcept = default;

    void Pop();
    void Push(const T& value);
    size_t Size() const;
    void Swap(Queue& other) noexcept;
    bool IsEmpty() const;

    T& Front();
    const T& Front() const;

    T& Back();
    const T& Back() const;

    template <typename T>
    void Queue<T>::Pop()
    {
        list.PopFront();
    }

    template <typename T>
    void Queue<T>::Push(const T& value)
    {
        list.PushBack(value);
    }

    template <typename T>
    size_t Queue<T>::Size() const
    {
        return list.Size();
    }
};