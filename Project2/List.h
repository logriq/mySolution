#pragma once

class List
{

private:
    void Copy(const List& other);

    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    class Iterator
    {
    public:
        Iterator(Node* node);
        bool operator!=(const Iterator& other) const;
        Iterator& operator++();
    private:
        Node* node;
    };

    // --- Constructors ---
    List();
    List(const List& other);
    List(List&& other) noexcept;

    // --- Destructor ---
    ~List();


    // --- Insert methods ---
    void PushBack(const int& value);
    void PushFront(const int& value);

    // --- Remove methods ---
    void PopBack();
    void PopFront();
    void Remove(const int& value);
    void Clear();

    // --- Find methods ---
    bool Find(const int& value) const;

    // --- Check size methods ---
    bool IsEmpty() const;
    size_t Size() const;

    // --- Assignment operators ---
    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;

    // --- Index operators ---
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    // --- Iterators methods ---
    Iterator Begin();
    Iterator End();

    // --- Extra methods ---
    void Show() const;
};

