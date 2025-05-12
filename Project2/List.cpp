#include "List.h"
#include <iostream>

void List::Copy(const List& other)
{
    if (other.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else
    {
        head = new Node{ other.head->data, nullptr };

        Node* current = head;
        Node* otherCurrent = other.head;

        while (otherCurrent->next != nullptr)
        {
            current->next = new Node{ otherCurrent->next->data, nullptr };
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        tail = current;
        size = other.size;
    }
}

List::List()
    : head(nullptr), tail(nullptr), size(0)
{
}

List::List(const List& other)
    : head(nullptr), tail(nullptr), size(0)
{
    Copy(other);
}

List::List(List&& other) noexcept
    : head(other.head), tail(other.tail), size(other.size)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

List::~List()
{
    Clear();
}

void List::PushBack(const int& value)
{
    if (head == nullptr)
    {
        head = new Node{ value, nullptr };
        tail = head;
    }
    else
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node{ value, nullptr };
    }

    size++;
}

void List::PopBack()
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* previous = head;
        Node* current = head->next;
        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        delete current;
        previous->next = nullptr;
        tail = previous;
    }

    size--;
}

void List::PopFront()
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* newHead = head->next;
        delete head;
        head = newHead;
    }
}

void List::Remove(const int& value)
{
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (previous == nullptr)
            {
                head = head->next;

                //the beginning of the list
                if (head == nullptr)
                {
                    tail = nullptr;
                }
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            current = (previous == nullptr) ? head : previous->next;
        }
        else
        {
            previous = current;

            //the end of lisr
            if (current == tail)
            {
                tail = previous;
            }
            current = current->next;
        }
    }

}

void List::Clear()
{
    while (head != nullptr)
    {
        Node* current = head;
        head = head->next;

        delete current;
    }

    tail = nullptr;

}

bool List::Find(const int& value) const
{
    if (head == nullptr)
    {
        return false;
    }

    Node* current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool List::IsEmpty() const
{
    return head == nullptr;
}

size_t List::Size() const
{
    size_t size = 0;
    Node* current = head;
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }
    return size;
}

List& List::operator=(const List& other)
{
    if (this != &other)
    {
        Clear();
        Copy(other);
    }

    return *this;
}

List& List::operator=(List&& other) noexcept
{
    if (this != &other)
    {
        Clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

int& List::operator[](size_t index)
{
    if (index >= Size())
    {
        throw std::out_of_range("Incorrect index int List::operator[]");
    }

    Node* current = head;
    for (size_t i = 0; i < index; ++i)
    {
        current = current->next;
    }

    return current->data;
}

const int& List::operator[](size_t index) const
{
    if (index >= Size())
    {
        throw std::out_of_range("Incorrect index int List::operator[]");
    }

    Node* current = head;
    for (size_t i = 0; i < index; ++i)
    {
        current = current->next;
    }


    bool List::Iterator::operator!=(const Iterator & other) const
    {
        return node != other.node;
    }

    List::Iterator& List::Iterator::operator++()
    {
        node = node->next;
        return *this;
    }

    List::Iterator List::Iterator::operator++(int)
    {
        Iterator temp(*this);
        node = node->next;
        return temp;
    }


    return current->data;
}

void List::Show() const
{
    if (head == nullptr)
    {
        std::cout << "List is empty\n";
    }
    else
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
}

void List::Copy(const List& other)
{
    if (other.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new Node{ other.head->data, nullptr };
        Node* current = head;
        Node* otherCurrent = other.head;

        while (otherCurrent->next != nullptr)
        {
            current->next = new Node{ otherCurrent->next->data, nullptr };
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        tail = current;
    }
}








