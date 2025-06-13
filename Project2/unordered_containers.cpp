#include <iostream>
#include <fstream>
#include <unordered_map> // тут знаходяться std::unordered_map та std::unordered_multimap
#include <unordered_set> // тут знаходяться std::unordered_set та std::unordered_multiset

void HashTest();

int main()
{
    /*
    Вставка: O(1) в середньому випадку, O(n) в найгіршому випадку (коли треба змінити розмір таблиці)
    Видалення: O(1) в середньому випадку, O(n) в найгіршому випадку (коли треба змінити розмір таблиці)
    Пошук: O(1) в середньому випадку, O(n) в найгіршому випадку (коли всі елементи зливаються в одному bucket).

    Зауважте, що складність середнього випадку передбачає хорошу хеш-функцію та достатній коефіцієнт завантаження,
    тоді як найгірша складність виникає, коли є колізії хешів і велика кількість елементів зберігається в
    одному сегменті.
    */

   
    //- Методи unordered контейнерів -
    // Ось список всіх методів всіх 4 контейнерів, які є в стандарті C++14:
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

    // ----- Приклад використання std::unordered_set -----

{
    std::unordered_set<std::string> uniqueWords;
    std::ifstream FileStream("input.txt"); // My name is Demian. I have a cat, and she is Natty
    std::string word;
    while (FileStream >> word)
    {
    }
    std::cout << "Number of unique words: " << uniqueWords.size() << std::endl;
    // Перевага використання std::unordered_set в тому, що пошук і вставка буде виконуватися
    // швидко навіть для великого набору слів. Також перевага в тому, що порядку
    // в unordered_set немає, а отже не витрачається час на перестановку елементів.
}

return 0;