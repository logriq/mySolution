////Як виглядають шляхи до файлів?
//
//int main()
//{
//    // Як указуються шляхи до файлів?
//    {
//        // Шлях до файлу - це текст наступних видів:
//        // 1. "Папка\\Папка\\Папка\\Папка\\Файл.Розширення"
//        // Наприклад: R"(D:\Documents\Visual Studio 2022\MyFile.txt)"
//        // 2. "Папка/Папка/Папка/Папка/Файл.Розширення"
//        // Наприклад: "D:/Documents/Visual Studio 2022/MyFile.txt"
//    }
//    
//
//    // Створення папок:
//    CreateFolder();
//
//    // Перейменування папок:
//    RenameFolder();
//
//    // Видалення папок:
//    DeleteFolder();
//
//    // Закриття файлу:
//    CloseFile();
//
//    // Читання інформації з файлу:
//    WriteIntoFile();
//
//    // Переміщення позиції файлових вказівників
//    FilePositioning();
//
//    return 0;
//}
//
////Як створити папку?
//
//#include <iostream>
//#include <string>
//#include <direct.h> //для _mkdir(), _wmkdir()
//#include <cerrno>
//
//void ShowErrnoMessage()
//{
//    std::cout << "Error code: " << errno << std::endl;
//
//    std::cout << "Message: ";
//    if (errno == EEXIST)
//    {
//        std::cout << "Folder already exists.\n";
//    }
//    else if (errno == ENOENT)
//    {
//        std::cout << "Path is incorrect.\n";
//    }
//
//    std::cout << std::endl;
//}
//
//void CreateFolder()
//{
//    const char* folder1Name = "MyFolder";
//    const wchar_t* folder2Name = L"папка";
//
//    int creationResult;
//
//    creationResult = _mkdir(folder1Name);
//    if (creationResult != 0)
//    {
//        std::cout << "Error! Could not create folder.\n";
//        ShowErrnoMessage();
//    }
//
//    creationResult = _wmkdir(folder2Name);
//    if (creationResult != 0)
//    {
//        std::cout << "Error! Could not create folder.\n";
//        ShowErrnoMessage();
//    }
//}
//
////Як перейменувати папку
//
//void RenameFolder()
//{
//    const char* oldName = "Filder";
//    const char* newName = "Folder";
//
//    int renamingResult = rename(oldName, newName);
//    if (renamingResult != 0)
//    {
//        std::cout << "Folder could not been renamed.\n";
//    }
//}
//
////Як видалити папку?
//
//void DeleteFolder()
//{
//    const char* folderPath = "Empty";
//    std::string removeCommand = "rmdir ";
//    removeCommand += folderPath; //removeCommand = "rmdir Empty"
//
//    //system("rmdir Empty");
//    int removingResult = system(removeCommand.c_str());
//    if (removingResult != 0)
//    {
//        std::cout << "Folder could not been removed.\n";
//    }
//}
//
////Як створити файл ?
//
//void CreateFile()
//{
//    // Функція створення/відкриття файлів fopen:
//// Прототип: 
////              FILE* fopen(const char* filename, const char* mode)
//// Параметри:
////              filename - шлях до файлу разом з назвою файлу та розширенням
////              mode - режим відкриття файлу
//// Повертаюче значення: вказівник на відкритий файл. nullptr - файл не можливо відкрити/створити
//// 
//// Замітка: для типу wchar_t існує функція _wfopen.
//// 
//// FILE - це структура, яка містить лише одне поле - вказівник на файл.
//// 
//// УВАГА: компілятор Visual Studio за замовчуванням не дозволяє використовувати
////              функцію fopen, бо вважає її небезпечною. Він рекомендує використовувати
////              натомість функцію fopen_s().
//// 
//// Функція створення/відкриття файлів fopen_s:
//// Прототип: 
////              errno_t fopen(FILE** stream, const char* filename, const char* mode)
//// Параметри:
////              stream - адреса на вказівник типу File, до якого прив'язується файл
////              filename - шлях до файлу разом з назвою файлу та розширенням
////              mode - режим відкриття файлу
//    // Повертаюче значення: 0 - файл успішно відкрито, значення EINVAL в інших випадках.
//// Замітка: для типу wchar_t існує функція _wfopen_s.
//
//
//
//// Режими відкриття файлу:
//// "r"  - відкриває файл для читання. Якщо файла не існує чи його неможливо знайти, повертається nullptr.
//// "w"  - відкриває пустий файл для запису. Якщо файл існує, то його вміст видаляється.
//// "a"  - відкриває файл для запису в його кінець. Створює файл, якщо його не існує.
//// "r+" - відкриває файл для читання і для запису. Файл має існувати.
//// "w+" - відкриває пустий файл для читання і для запису. Якщо файл існує, то його вміст видаляється.
//// "a+" - відкриває файл для читання і для запису в кінець. Створює файл, якщо він не існує.
//
//// Варіант відкриття через fopen:
////FILE* file1;
////file1 = fopen("sdgsdgh.txt", "r");
////if (file1 == nullptr)
////{
////    std::cout << "File could not been opened.\n";
////}
////
//// Варіант відкриття через fopen_s:
////FILE* file2;
////errno_t openingResult = fopen_s(&file2, "sdgsgdh.txt", "r");
////if (openingResult != 0)
////{
////    std::cout << "File could not been opened.\n";
////}
//}
//
////Як перейменувати файл ?
//
//void RenameFile()
//{
//    const char* oldName = "OldFileName.txt";
//    const char* newName = "NewFileName.txt";
//
//    int renamingResult = rename(oldName, newName);
//    if (renamingResult != 0)
//    {
//        std::cout << "File could not been renamed.\n";
//    }
//}
//
////Як видалити файл ?
//
//void DeleteFile()
//{
//    const char* filename = "MyFileForDelete.txt";
//    int deletionResult = remove(filename);
//    if (deletionResult != 0)
//    {
//        std::cout << "File could not been deleted.\n";
//    }
//}
//
////Що означають розширення файлів ?
//
//void CloseFile()
//{
//    // Відкрили файл і з'єднали з потоком.
//    const char* filename = "SomeFile.bin";
//    FILE* file;
//    fopen_s(&file, filename, "wb");
//
//    while (true)
//    {
//    }
//
//    // Попрацювати з файлом.
//
//    //Закрити файл, від'єднавши потік.
//    fclose(file);
//}
//
//int main()
//{
//    //fopen("MyFile.txt");
//}
//
////Текстові і бінарні файли
//
//int number = 100;
////Myfile < number
////"100"
////0110 0100
//
////Як зчитати інформацію з файлу ?
//
//void ReadFromFile()
//{
//    // Є декілька функцій для читання інформації з файлу:
//
//    // 1. Прототип: int fgetc(FILE* stream)
//    // Опис: читає і повертає наступний символ з потоку.
//    // Параметри: stream - потік на файл.
//    // Повертає значення: зчитаний символ, якщо вийшло зчитати.
//    // Інакше EOF.
//
//    // 2. Прототип:     char* fgets(char* str, int count, FILE* stream)
//    // Опис:            читає максимум (count - 1) символів із потоку і зберігає
//    //                  їх в масиві str. Зчитування зупиняється, якщо зустрічається
//    //                  символ \n або кінець файлу. Дописує нуль-символ в кінець
//    //                  зчитаної послідовності.
//    // Параметри: 
//    // 
//    // str - масив, куди записуються символи
//    // count - розмір масиву str
//    // stream - потік на файл.
//    // Повертаюче значення: str, якщо успішно вдалося зчитати послідовність
//    // nullptr, якщовиникла проблема
//    // 
//    // 3. Прототип:     size_t fread(void* buffer, size_t size, size_t count, FILE* stream)
//    // Опис:            зчитує максимум count байтів у вказівник buffer із потоку stream
//    // Параметри:
//    // 
//    // buffer - вказівник, куди записуються байти
//    // size - розмір кожного елементу послідовності даних, які треба зчитувати
//    // count - кількість байтів для зчитування
//    // stream - потік на файл
//    // Повертаюче значення: кількість успішно зчитаних байтів.
//
//    /*int number;
//    fread(&number, sizeof(number), 1, file);
//
//    double arr[10];
//    fread(arr, sizeof(double), 10, file);*/
//
//    // Приклад використання функції fgetc:
//
//    const char* filename = "Text.txt";
//    FILE* fileStream;
//    fopen_s(&fileStream, filename, "r");
//    if (fileStream == nullptr)
//    {
//        std::cout << "Could not open the file.\n";
//        return;
//    }
//
//    int character = fgetc(fileStream);
//    while (character != EOF)
//    {
//        std::cout << static_cast<char>(character);
//        character = fgetc(fileStream);
//    }
//    fclose(fileStream);
//}
//
////Як записати у файл інформацію ?
//
//void WriteIntoFile()
//{
//    // Є декілька функцій для запису інформації у файл:
//
//
//
//    // 1. Прототип: int fputc(int ch, FILE* stream);
//    //    Опис: Записує символ ch в файловий потік stream
//    //    Параметри: ch - символ
//    //               stream - потік, зв'язаний з файлом
//    //    Повертає значення: якщо символ успішно записався - повертає символ.
//    //                       Інакше - EOF.
//
//    // 2. Прототип: int fputs(const char* str, FILE* stream);
//    //    Опис: Записує рядок str в файловий потік stream
//    //    Параметри: str - рядок
//    //               stream - потік, зв'язаний з файлом
//    //    Повертає значення: якщо рядок успішно записався - повертає ненульове значення.
//
//    // 3. Прототип: size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
//    //    Опис: записує дані, на які вказує buffer, в файловий потік stream
//    // Параметри:      buffer - вказівник на дані, які треба записати
//    //                 size - розмір кожного елементу даних, які треба записати
//    //                 count - кількість елементів даних, які треба записати
//    //                 stream - потік, зв'язаний з файлом
//    //
//    // Повертачне значення: Кількість об'єктів, які записалися успішно.
//    //                      Якщо це значення менше за count - щось пішло не так.
//
//    // Приклад використання функції fputc:
//    {
//        FILE* fileStream = nullptr;
//        const char* filename = "Characters.txt";
//
//        fopen_s(&fileStream, filename, "w");
//        if (fileStream != nullptr)
//        {
//            fputc('!', fileStream);
//            fputc('@', fileStream);
//            fputc('#', fileStream);
//
//            fclose(fileStream);
//        }
//    }
//
//    // Приклад використання функції fputs:
//    {
//        FILE* fileStream = nullptr;
//        const char* filename = "Strings.txt";
//
//        fopen_s(&fileStream, filename, "w");
//        if (fileStream != nullptr)
//        {
//            fputs("My name is", fileStream);
//            fputs("Demian\n", fileStream);
//            fputs("Goodbye!", fileStream);
//
//            fclose(fileStream);
//        }
//    }
//}
//
////Переміщення позиції файлових вказівників
//
//void FilePositioning()
//{
//    // Оскільки у файла є вказівники на наступні символи для зчитування, то ми можемо 
//    // працювати з ними. Наприклад, коли ми використовуємо функції для читання чи запису,
//    // то після проведених операцій ці функції переміщають ці вказівники далі.
//
//    // Бувають ситуації, коли нам треба зняти місцезнаходження цих вказівників, або
//    // коли нам треба перемістити ці вказівники назад чи вперед.
//
//    // Для роботи з вказівниками є наступні функції:
//    // 1. long ftell (FILE* stream) - повертає позицію файлового вказівника
//    // 2. int fseek (FILE* stream, long offset, int origin) - встановлює позицію файлового вказівника
//    // 3. int fgetpos (FILE* stream, fpos_t* pos) - записує позицію файлового вказівника
//    // 4. int fsetpos (FILE* stream, const fpos_t* pos) - переписує позицію файлового вказівника
//    // 5. void rewind (FILE* stream) - переміщує файловий вказівник на початок
//
//    // Приклад: є файл з тексто вими даними. Найти всі букви "а" і замінити їх на б0укви "А".
//    {
//        /*fseek(file, 5, SEEK_CUR);
//
//        SEEK_SET;
//        SEEK_CUR;
//        SEEK_END;
//        */
//        FILE* fileStream = nullptr;
//        const char* filename = "Good text.txt";
//
//        fopen_s(&fileStream, filename, "r+");
//        if (fileStream != nullptr)
//        {
//            int character;
//            while ((character = fgetc(fileStream)) != EOF)
//            {
//                if (character == 'a')
//                {
//                    fseek(fileStream, -1, SEEK_CUR);
//                    fputc('A', fileStream);
//                    fseek(fileStream, 1, SEEK_CUR);
//                }
//            }
//            fclose(fileStream);