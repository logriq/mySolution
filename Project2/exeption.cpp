//#include <iostream>
//#include <exception>

//Проблема обробки помилок


//class Array
//{
//private:
//    int* arr;
//    size_t size;
//
//public:
//    Array(size_t size)
//        : size(size),
//        arr(new int[size]{})
//    {
//        /*...*/
//    } 

    /*size_t Size() const { return size; }

    int& operator[](size_t index)
    {
        if (index >= size)
        {
        
        }
        return arr[index];
    }*/



/*int main()
{
    Array array(10);

    for (size_t i = 0; i < array.Size(); ++i)
    {
        array[i + 100] = 10;
        std::cout << array[i + 100];
    }
    std::cout << std::endl;

    return 0;
}*/





//що таке виключення?





//class Array
//{
//private:
//    int* arr;
//    size_t size;
//
//public:
//    Array(size_t size)
//        : size(size),
//        arr(new int[size] {})
//    {
//        /*...*/
//    }
//
//    size_t Size() const { return size; }
//
//    int& operator[](size_t index)
//    {
//        if (index >= size)
//        {
//            bool error = true;
//            throw error;
//        }
//        return arr[index];
//    }
//}
//
//
//    size_t Size() const { return size; }
//
//    int& operator[](size_t index)
//    {
//        if (index >= size)
//        {
//            bool error = true;
//            throw error;
//        }
//        return arr[index];
//    }
//
//int main()
//{
//    try
//    {
//        int arr[] = { 1, 2, 3 };
//        for (size_t i = 0; i < 5; ++i)
//        {
//            if (i >= 3)
//            {
//                int errorCode = 1;
//                throw errorCode;
//            }
//            std::cout << arr[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//    catch (int ec)
//    {
//        std::cout << "ERROR: Error code = ";
//
//        std::cout << std::endl;
//    }


    /*try
{
    for (size_t i = 0; i < array.Size(); ++i)
    {
        std::cout << array[i + 10] << " ";
    }
}
catch (bool)
{
    std::cout << "Error. Division by zero!\n";
}

    return 0;
}*/





//Декілька catch



//class Array
//{
//private:
//    int* arr;
//    size_t size;
//
//public:
//    Array(size_t size)
//        : size(size),
//        arr(new int[size] {})
//    {
//        /*...*/
//    }
//
//    size_t Size() const { return size; }
//
//    int& operator[](size_t index)
//    {
//        if (index >= size)
//        {
//            bool error = true;
//            throw error;
//        }
//        return arr[index];
//    }
//   
//}
//
//
//void InterestingFunction()
//{
//     code
//
//    std::srand(std::time(nullptr));
//
//    int randomNumber = std::rand() % 3;
//    if (randomNumber == 0)
//
//    {
//        throw 10;
//    }
//    else if (randomNumber == 1)
//    {
//        throw '$';
//    }
//    else if (randomNumber == 2)
//    {
//        throw 2.5;
//    }
//}
//
//
//int main()
//{
//    try
//    {
//        InterestingFunction();
//    }
//catch (int errorNumber)
//    {  
//    std::cout << errorNumber;
//    }
//catch (char errorCharacter)
//    {
//    std::cout << errorCharacter;
//    }
//catch (double errorValue)
//    {
//    std::cout << errorValue;
//    }
//return 0;
//
//    }







/*struct MyException
{
    int errorCode;
    char errorMessage[30];
};

void InterestingFunction()
{
    std::srand(std::time(nullptr));

    int randomNumber = std::rand() % 3;

    try
    {
        if (randomNumber == 0)
        {
            throw 10;
        }
        else if (randomNumber == 1)
        {
            throw 'a';
        }
        else if (randomNumber == 2)
        {
            throw 2.5;
        }
    }
    catch (const MyException exc)
    {
        std::cout << "Function name: " << func << std::endl;
        std::cout << "Error code = " << exc.errorCode << '\n\n';
    }
}



int main()
{
    try
    {
        InterestingFunction();
    }
    catch (const MyException& exc)
    {
        std::cout << "Function name: " << func << std::endl;
        std::cout << "Error message = " << exc.errorMessage << "\n\n";
    }
    catch (char errorCharacter)
    {
        std::cout << errorCharacter;
    }
}*/




//Ієрархія виключень

int main()
{
   /* A <- B <- C
    
    try
    {
        code
    }
    catch (C)
    {
    }
    catch (B)
    {
    }
    catch (A)
    {
    }
    */
}




//Специфікація виключень throw(...)

//
//class Exception
//{
//public:
//    Exception()
//    {
//        std::cout << "Default Constructor\n";
//    }
//    Exception(const Exception& other)
//    {
//        std::cout << "Copy Constructor\n";
//    }
//};
//
//void Func1() throw () // функція не кидає ніяких виключень
//{
//    std::cout << "Func1\n";
//    throw 10;
//}
//
//void Func2() throw(...) // функція може кидати виключення якихось типів
//{
//    std::cout << "Func2\n";
//    throw 10;
//}
//
//// функція може кидати виключення вказаних типів
//void Func3() throw(Exception, std::exception, std::bad_alloc)
//{
//    std::cout << "Func3\n";
//    throw Exception();
//}
//
//int main()
//{
//    try
//    {
//        //Func1();
//        //Func2();
//        Func3();
//    }
//    catch (const Exception& e)
//    {
//
//    }
//    return 0;
//}
//
//
//
//
//
//
