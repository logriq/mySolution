/*
� �������� STL � ������ ����������.
���� ���������� �� �������:

    �������� ���������� (Sequence containers): -
    1. [+] vector
    2. [ ] list
    3. [ ] forward_list
    4. [ ] deque
    5. [ ] array

    ���������� ���������� (Associative containers): -������ ������
    6. [ ] set
    7. [ ] map
    8. [ ] multiset
    9. [ ] multimap

    ������������� ���������� ���������� (Unordered associative containers):
    10. [ ] unordered_set
    11. [ ] unordered_map
    12. [ ] unordered_multiset
    13. [ ] unordered_multimap

    �������� ���������� (Container adaptors): -��������� �����
    14. [ ] stack
    15. [ ] queue
    16. [ ] priority_queue

    17.span(C++20)
*/


void Show(const std::vector<int>& vector)
{
    std::cout << "----- VECTOR INFO -----\n";
    std::cout << "Elements: ";
    if (vector.empty())
    {
        std::cout << "None";
    }
    else
    {
        for (size_t i = 0; i < vector.size(); i++)
        {
            std::cout << vector[i] << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "----------------------\n";
}


//������������



void Constructors()
{

    // 1. ����������� �� �������������
    std::vector<int> v1;
    Show(v1);

    // 2. ����������� �� �������������, ���� ������ �������������� ��������
    std::allocator<int> myAllocator; // �����������, �� �� �������� ��� ��������
    std::vector<int> v2(myAllocator);
    Show(v2);

    // 3. �����������, ���������� std::initializer_list
    std::vector<int> v3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Show(v3);

    // 4. ����������� ��ﳿ
    std::vector<int> v4(v3);
    Show(v4);

    // 5. ����������� ����������
    std::vector<int> v5(std::move(v4));
    Show(v4);
    Show(v5);

    // 6. �����������, ���� ������ ������� ��������
    std::vector<int> v6(10);
    Show(v6);

    // 7. �����������, ���� ������ ������� �������� � �� ��������
    std::vector<int> v7(3, 100);
    Show(v7);

    // 8. �����������, ���� ������ 2 ���������
    std::vector<int> v8(v5.begin(), v5.begin() + 4);
    Show(v8);

}




//������


std::vector<int> vector{10, 20, 500, 5, 0};

// 1. front - ������� ��������� �� ������ �������.
std::cout << "vector[0] = " << vector.front() << std::endl;
vector.front() = 100;
std::cout << "vector[0] = " << vector.front() << std::endl;

// 2. back - ������� ��������� �� ������� �������.
std::cout << "vector[4] = " << vector.back() << std::endl;
vector.back() = 123;
std::cout << "vector[4] = " << vector.back() << std::endl;

// 3. data - ������� �������� �� �������� ����� ����������.
int* ptr = vector.data();
std::cout << "vector[2] = " << vector[2] << std::endl;
ptr[2] = -5;
std::cout << "vector[2] = " << vector[2] << std::endl;

// 4. operator[] - ������� ��������� �� ������� �� ������� ��������.
std::cout << "vector[3] = " << vector[3] << std::endl;

// 5. at - ������� ��������� �� ������� �� ������� ��������. 
// ���� ���������� ���� std::out_of_range, ���� ������ �������� �� ������� ������.
try
{
    vector.at(100) = 1000;
}
catch (const std::out_of_range& exc)
{
    std::cout << exc.what() << std::endl;
}

// 6. get_allocator - ������� ��������, ���� ����'������ �� ����������.
auto allocator = vector.get_allocator();

// 7. operator= - �������� ������������ ���� ������� ������ ����������.
vector = { 1, 2, 3, 4, 5 };  // std::initializer_list
vector = std::vector<int>(10, 1);  // copy =
vector = vector;  // move =

// 8. assign - �������� ������������ ���� ������� ������ ����������.
// ������ �� �������� =, ��� �� ����� �����������, �� ���� �������� ����� ������ ���������.
vector.assign(5, 100);  // 5 ��������, �������� ������� 100
vector.assign({ 1, 2, 3, 4, 5 });  // std::initializer_list

// 9. begin ������� �������� �� ������ ������� ����������. ������� ����� ����� ����� ��������.
std::cout << " * vector.begin() = " << *vector.begin() << std::endl;

*vector.begin() = 1000;

std::cout << " * vector.begin() = " << *vector.begin() << std::endl;

// 10. cbegin - ������� ����������� �������� �� ������ ������� ����������. ������� �� ����� ����� ����� ��������
std::cout << " * vector.cbegin() = " << *vector.cbegin() << std::endl;

// *vector.cbegin() = 1000;

// 11. end - ������� �������� �� ����� �������� ��������.
//     �������� ������� �� ���� ���� ����������� ��������.
for (auto iter = vector.begin(); iter != vector.end(); ++iter)
{
    *iter = 2;
    std::cout << *iter << " ";
}
std::cout << std::endl;

// 12. cend - ������� ����������� �������� �� ����� �������� ��������.
for (auto iter = vector.cbegin(); iter != vector.cend(); ++iter)
{
    // *iter = 2; // �������: ��������� ������ ������� ����� ����������� ��������
}

// 13. rbegin - ������� ��������� �������� �� ������� ������� ����������. ³������� �� begin ��������:
//     ���� �������� ++ �� ���������, ���� ������� ����� begin, �� �������� ������������ ������,
//     ��� ���� �������� ++ �� ���������, ���� ������� ����� rbegin, �� �������� ������������ ����.
// 14. rend - ���� � �������, �� � rbegin �� begin, ����� �� ������ end.
for (auto iter = vector.rbegin(); iter != vector.rend(); ++iter)
{
    *iter = 100;
    std::cout << *iter << " ";
}
std::cout << std::endl;

// 15. crbegin - ����������� rbegin.
// 16. crend - ����������� rend.
for (auto iter = vector.crbegin(); iter != vector.crend(); ++iter)
{
    // *iter = 2; // �������: ��������� ������ ������� ����� ����������� ��������
    std::cout << *iter << " ";
}
std::cout << std::endl;

// 17. empty - ������� true, ���� ������ ������.
std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;

// 18. size - ������� ����� ������� (������� ��������, � ���� � ��������).
std::cout << "Size = " << vector.size() << std::endl;

// 19. capacity - ������� ������ ������� (������� ��������, ��� ���� � �������� ���'�� �������
std::cout << "Capacity = " << vector.capacity() << std::endl;

// 20. max_size - ������� ����������� ������� ������� ��������
std::cout << "Max size = " << vector.max_size() << std::endl;

// 21. reverse - ������ (�������) ��'�� ������ �������.
std::cout << "Capacity = " << vector.capacity() << std::endl;
vector.reserve(101);
std::cout << "Capacity = " << vector.capacity() << std::endl;

// 22. shrink_to_fit - ������ (�������) ��'�� ������ ������� �������� �� ������.
vector.shrink_to_fit();
std::cout << "Capacity = " << vector.capacity() << std::endl;

// 23. clear - ����� ������, ��������� ���'��� (���������� �����������) ��������.
vector.clear();
std::cout << "Size = " << vector.size() << std::endl;
std::cout << "Capacity = " << vector.capacity() << std::endl;
std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;

// 24. insert - �������� ��� �������� � ������ � ������ ����.
// vector = {1, 2, 3, 4, 5}; // ����������, ������ ��� ������������� �����
vector.insert(vector.cbegin(), { 100, 200 }); // � 5 ���������������
// Show(vector); // ����������, �� ������� Show ��������� ����

// 25. emplace - ������ ������ ������ insert. ��� ������ insert �������� ����� ���� �������
//             � ���'�� �� �� ���������� � ������. � � emplace �������� ����� ��������
//             ����� � ������. ����� � ���������� ��������.
// vector.emplace(vector.cend(), 1000);
// Show(vector);

// 26. push_back - �������� ����� ������� � ����� �������.
// 27. pop_back - �������� ������� ������� � ������.
vector.push_back(-111);
Show(vector);

vector.pop_back();
Show(vector);

// 28. resize - ����� ����� ������� (�� ������).
//     ���� ����� ����� ������ �� ���������, �� ������ ����������� �� ������ ������.
//     ���� ����� ����� ������ �� ���������, �� � ������ ��������� ��� �������� � ���������
std::cout << "Size = " << vector.size() << std::endl;
std::cout << "Capacity = " << vector.capacity() << std::endl;
Show(vector);

// 29. swap - ������� ���� ���� ������� (����� �� ������)
std::vector<int> vector1 = { 1, 2, 3 };
std::vector<int> vector2 = { 5, 6, 7, 8, 9, 0 };
Show(vector1);
Show(vector2);
vector1.swap(vector2);
Show(vector1);
Show(vector2);

// 30. erase - �������� �������/������� ������� �� ����������.
 std::vector<int> evenNumbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 Show(evenNumbers);
 evenNumbers.erase(evenNumbers.cend() - 2); // �������� 9
 Show(evenNumbers);
 for (auto iter = evenNumbers.cbegin(); iter != evenNumbers.cend(); ) // �������� �� ������ ��������
 {
     if (*iter % 2 != 0) // ���� ����� �� �����
     {
         iter = evenNumbers.erase(iter);
     }
     else
     {
         ++iter;
     }
 }
 Show(evenNumbers);

 31. emplace_back - ���������� �� emplace, ����� �������� � ����� (������ ������ ������ push_back).
 evenNumbers.emplace_back(10);
 evenNumbers.emplace_back(20);
 Show(evenNumbers);