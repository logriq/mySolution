#include <iostream>
#include <fstream>
#include <unordered_map> // ��� ����������� std::unordered_map �� std::unordered_multimap
#include <unordered_set> // ��� ����������� std::unordered_set �� std::unordered_multiset

void HashTest();

int main()
{
    /*
    �������: O(1) � ���������� �������, O(n) � ��������� ������� (���� ����� ������ ����� �������)
    ���������: O(1) � ���������� �������, O(n) � ��������� ������� (���� ����� ������ ����� �������)
    �����: O(1) � ���������� �������, O(n) � ��������� ������� (���� �� �������� ���������� � ������ bucket).

    ��������, �� ��������� ���������� ������� ��������� ������ ���-������� �� �������� ���������� ������������,
    ��� �� ������� ��������� ������, ���� � ���糿 ����� � ������ ������� �������� ���������� �
    ������ �������.
    */

   
    //- ������ unordered ���������� -
    // ��� ������ ��� ������ ��� 4 ����������, �� � � �������� C++14:
    // unordered_map | unordered_multimap | unordered_set | unordered_multiset |
    // begin        | begin            | begin         | begin            |
    // cbegin       | cbegin           | cbegin        | cbegin           |
    // end          | end              | end           | end              |
    // cend         | cend             | cend          | cend             |
    // clear        | clear            | clear         | clear            |
    // empty        | empty            | empty         | empty            |
    // count        | count            | count         | count            |
    // insert       | insert           | insert        | insert           |
    // emplace      | emplace          | emplace       | emplace          |
    // emplace_hint | emplace_hint     | emplace_hint  | emplace_hint     |
    // upper_bound  | upper_bound      | upper_bound   | upper_bound      |
    // lower_bound    | lower_bound      | lower_bound   | lower_bound      |
    // equal_range    | equal_range      | equal_range   | equal_range      |
    // erase          | erase            | erase         | erase            |
    // find           | find             | find          | find             |
    // max_size       | max_size         | max_size        | max_size          |
    // reserve        | reserve          | reserve         | reserve           |
    // size           | size             | size            | size              |
    // get_allocator  | get_allocator    | get_allocator   | get_allocator     |
    // key_eq         | key_eq           | key_eq          | key_eq            |
    // swap           | swap             | swap            | swap              |
    // operator=      | operator=        | operator=       | operator=         |
    // at             |                  |                 |                   |
    // operator[]     | operator[]       |                 |                   |
    //                |                  |                 |                   |
    //----------------+------------------+-----------------+-------------------|
    // bucket         | bucket           | bucket          | bucket            |
    // bucket_count   | bucket_count     | bucket_count    | bucket_count      |
    // bucket_size    | bucket_size      | bucket_size     | bucket_size       |
    // hash_function  | hash_function    | hash_function   | hash_function     |
    // load_factor    | load_factor      | load_factor     | load_factor       |
    // max_bucket_count | max_bucket_count | max_bucket_count| max_bucket_count  |
    // max_load_factor  | max_load_factor  | max_load_factor | max_load_factor   |
    // rehash           | rehash           | rehash          | rehash            |
    //------------------+------------------+-----------------+-------------------|

    // ----- ������� ������������ std::unordered_set -----

{
    std::unordered_set<std::string> uniqueWords;
    std::ifstream FileStream("input.txt"); // My name is Demian. I have a cat, and she is Natty
    std::string word;
    while (FileStream >> word)
    {
    }
    std::cout << "Number of unique words: " << uniqueWords.size() << std::endl;
    // �������� ������������ std::unordered_set � ����, �� ����� � ������� ���� ������������
    // ������ ����� ��� �������� ������ ���. ����� �������� � ����, �� �������
    // � unordered_set ����, � ���� �� ����������� ��� �� ������������ ��������.
}

return 0;