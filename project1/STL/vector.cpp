/*
В бібліотеці STL є багато контейнерів.
Вони поділяються на категорії:

    Послідовні контейнери (Sequence containers): -
    1. [+] vector
    2. [ ] list
    3. [ ] forward_list
    4. [ ] deque
    5. [ ] array

    Асоціативні контейнери (Associative containers): -бінарне дерево
    6. [ ] set
    7. [ ] map
    8. [ ] multiset
    9. [ ] multimap

    Невпорядковані асоціативні контейнери (Unordered associative containers):
    10. [ ] unordered_set
    11. [ ] unordered_map
    12. [ ] unordered_multiset
    13. [ ] unordered_multimap

    Адаптори контейнерів (Container adaptors): -щбмеження даних
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


//Конструктори



void Constructors()
{

    // 1. Конструктор за замовчуванням
    std::vector<int> v1;
    Show(v1);

    // 2. Конструктор за замовчуванням, який приймає користувацький алокатор
    std::allocator<int> myAllocator; // Представимо, що ви написали свій алокатор
    std::vector<int> v2(myAllocator);
    Show(v2);

    // 3. Конструктор, приймаючий std::initializer_list
    std::vector<int> v3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Show(v3);

    // 4. Конструктор копії
    std::vector<int> v4(v3);
    Show(v4);

    // 5. Конструктор переміщення
    std::vector<int> v5(std::move(v4));
    Show(v4);
    Show(v5);

    // 6. Конструктор, який приймає кількість елементів
    std::vector<int> v6(10);
    Show(v6);

    // 7. Конструктор, який приймає кількість елементів і їх значення
    std::vector<int> v7(3, 100);
    Show(v7);

    // 8. Конструктор, який приймає 2 ітератори
    std::vector<int> v8(v5.begin(), v5.begin() + 4);
    Show(v8);

}




//МЕТОДИ


std::vector<int> vector{10, 20, 500, 5, 0};

// 1. front - повертає посилання на перший елемент.
std::cout << "vector[0] = " << vector.front() << std::endl;
vector.front() = 100;
std::cout << "vector[0] = " << vector.front() << std::endl;

// 2. back - повертає посилання на останній елемент.
std::cout << "vector[4] = " << vector.back() << std::endl;
vector.back() = 123;
std::cout << "vector[4] = " << vector.back() << std::endl;

// 3. data - повертає вказівник на внутрішній масив контейнеру.
int* ptr = vector.data();
std::cout << "vector[2] = " << vector[2] << std::endl;
ptr[2] = -5;
std::cout << "vector[2] = " << vector[2] << std::endl;

// 4. operator[] - повертає посилання на елемент за заданим індексом.
std::cout << "vector[3] = " << vector[3] << std::endl;

// 5. at - повертає посилання на елемент за заданим індексом. 
// Кидає виключення типу std::out_of_range, якщо індекс виходить за границі масиву.
try
{
    vector.at(100) = 1000;
}
catch (const std::out_of_range& exc)
{
    std::cout << exc.what() << std::endl;
}

// 6. get_allocator - повертає алокатор, який прив'язаний до контейнера.
auto allocator = vector.get_allocator();

// 7. operator= - дозволяє переписувати вміст вектора новими значеннями.
vector = { 1, 2, 3, 4, 5 };  // std::initializer_list
vector = std::vector<int>(10, 1);  // copy =
vector = vector;  // move =

// 8. assign - дозволяє переписувати вміст вектора новими значеннями.
// Схожий на оператор =, але має більше можливостей, бо може приймати більше одного параметру.
vector.assign(5, 100);  // 5 елементів, значення кожного 100
vector.assign({ 1, 2, 3, 4, 5 });  // std::initializer_list

// 9. begin повертає ітератор на перший елемент контейнеру. Елемент можна міняти через ітератор.
std::cout << " * vector.begin() = " << *vector.begin() << std::endl;

*vector.begin() = 1000;

std::cout << " * vector.begin() = " << *vector.begin() << std::endl;

// 10. cbegin - повертає константний ітератор на перший елемент контейнеру. Елемент НЕ можна міняти через ітератор
std::cout << " * vector.cbegin() = " << *vector.cbegin() << std::endl;

// *vector.cbegin() = 1000;

// 11. end - повертає ітератор на кінець діапазону елементів.
//     Простими словами це мітка кінця послідовності елементів.
for (auto iter = vector.begin(); iter != vector.end(); ++iter)
{
    *iter = 2;
    std::cout << *iter << " ";
}
std::cout << std::endl;

// 12. cend - повертає константний ітератор на кінець діапазону елементів.
for (auto iter = vector.cbegin(); iter != vector.cend(); ++iter)
{
    // *iter = 2; // Помилка: неможливо змінити елемент через константний ітератор
}

// 13. rbegin - повертає обернений ітератор на останній елемент контейнеру. Відмінність від begin наступна:
//     якщо написати ++ до ітератора, який повертає метод begin, то ітератор переміститься вправо,
//     але якщо написати ++ до ітератора, який повертає метод rbegin, то ітератор переміститься вліво.
// 14. rend - така ж аналогія, як в rbegin до begin, тільки до методу end.
for (auto iter = vector.rbegin(); iter != vector.rend(); ++iter)
{
    *iter = 100;
    std::cout << *iter << " ";
}
std::cout << std::endl;

// 15. crbegin - константний rbegin.
// 16. crend - константний rend.
for (auto iter = vector.crbegin(); iter != vector.crend(); ++iter)
{
    // *iter = 2; // Помилка: неможливо змінити елемент через константний ітератор
    std::cout << *iter << " ";
}
std::cout << std::endl;

// 17. empty - повертає true, якщо вектор пустий.
std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;

// 18. size - повертає розмір вектору (кількість елементів, в яких є значення).
std::cout << "Size = " << vector.size() << std::endl;

// 19. capacity - повертає ємність вектору (кількість елементів, для яких в динамічній пам'яті виділено
std::cout << "Capacity = " << vector.capacity() << std::endl;

// 20. max_size - повертає максимально можливу кількість елементів
std::cout << "Max size = " << vector.max_size() << std::endl;

// 21. reverse - збільшує (резервує) об'єм ємності вектору.
std::cout << "Capacity = " << vector.capacity() << std::endl;
vector.reserve(101);
std::cout << "Capacity = " << vector.capacity() << std::endl;

// 22. shrink_to_fit - зменшує (скорочує) об'єм ємності вектору поближче до розміру.
vector.shrink_to_fit();
std::cout << "Capacity = " << vector.capacity() << std::endl;

// 23. clear - очищає вектор, звільняючи пам'ять (викликаючи деструктори) елементів.
vector.clear();
std::cout << "Size = " << vector.size() << std::endl;
std::cout << "Capacity = " << vector.capacity() << std::endl;
std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;

// 24. insert - вставляє нові значення у вектор в задане місце.
// vector = {1, 2, 3, 4, 5}; // Припустимо, вектор був ініціалізований раніше
vector.insert(vector.cbegin(), { 100, 200 }); // є 5 перезавантажень
// Show(vector); // Припустимо, що функція Show визначена десь

// 25. emplace - кращий варіант методу insert. Для методу insert значення мають бути створені
//             в пам'яті ще до вставлення у вектор. А в emplace значення можна будувати
//             прямо у векторі. Метод є варіативним шаблоном.
// vector.emplace(vector.cend(), 1000);
// Show(vector);

// 26. push_back - вставити новий елемент в кінець вектору.
// 27. pop_back - видалити кінцевий елемент з масиву.
vector.push_back(-111);
Show(vector);

vector.pop_back();
Show(vector);

// 28. resize - змінює розмір вектору (НЕ ємність).
//     Якщо новий розмір менший за попередній, то вектор скорочується до нового розміру.
//     Якщо новий розмір більший за попередній, то у вектор додаються нові елементи зі значенням
std::cout << "Size = " << vector.size() << std::endl;
std::cout << "Capacity = " << vector.capacity() << std::endl;
Show(vector);

// 29. swap - поміняти вміст двох векторів (розмір та ємність)
std::vector<int> vector1 = { 1, 2, 3 };
std::vector<int> vector2 = { 5, 6, 7, 8, 9, 0 };
Show(vector1);
Show(vector2);
vector1.swap(vector2);
Show(vector1);
Show(vector2);

// 30. erase - видалити елемент/діапазон значень із контейнеру.
 std::vector<int> evenNumbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 Show(evenNumbers);
 evenNumbers.erase(evenNumbers.cend() - 2); // видалити 9
 Show(evenNumbers);
 for (auto iter = evenNumbers.cbegin(); iter != evenNumbers.cend(); ) // видалити всі непарні значення
 {
     if (*iter % 2 != 0) // якщо число не парне
     {
         iter = evenNumbers.erase(iter);
     }
     else
     {
         ++iter;
     }
 }
 Show(evenNumbers);

 31. emplace_back - аналогічний до emplace, тільки вставляє в кінець (кращий аналог методу push_back).
 evenNumbers.emplace_back(10);
 evenNumbers.emplace_back(20);
 Show(evenNumbers);