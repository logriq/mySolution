#include <iostream>

//int Sum(int a, int b)
//{
// return a + b;
//}





//class SDFSD
//{
//public:
//    void operator()(int num1, int num2)
//    {
//        return num1 + num2;
//    }
//};
//
//
//int main()
//{
//    int num1 = 10, num2 = 20;
//    //int sum = Sum(num1, num2);
//    //int sum = Sum()(num1, num2);
//    [](int num1, int num2)
//        {
//            return num1 + num2;
//        };
//    return 0;
//}









//int main()
//{
//    int num1 = 10, num2 = 20;
//    std::cout << "sum = " << sum << std::endl;
//    return 0;
//}







    // [](Список_параметрів) -> double { Код_функції }








template <typename T, typename Func>
void ForAllElements(T arr[], size_t size, Func func)
{
    for (size_t i = 0; i < size; ++i)
    {
        func(arr[i]);
    }
}

int main()
{
    const size_t SIZE2 = 3;
    int arr1[SIZE1] = { 10, 20, 30 };

    const size_t SIZE2 = 5;
    double arr2[SIZE2] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    const size_t SIZE3 = 2;
    char arr3[SIZE3] = { 'A', 'B' };

    auto showCube = [](int number) { std::cout << std::pow(number, 3) << " "; };
    auto showSquareRoot = [](double number) { std::cout << std::sqrt(number) << " "; };

    ForAllElements(arr1, SIZE1, showCube);
    std::cout << std::endl;

    ForAllElements(arr2, SIZE2, showCube);
    std::cout << std::endl;

    ForAllElements(arr1, SIZE1, showSquareRoot);
    std::cout << std::endl;

    ForAllElements(arr2, SIZE2, showSquareRoot);
    std::cout << std::endl;