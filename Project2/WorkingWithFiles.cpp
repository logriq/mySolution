////�� ���������� ����� �� �����?
//
//int main()
//{
//    // �� ���������� ����� �� �����?
//    {
//        // ���� �� ����� - �� ����� ��������� ����:
//        // 1. "�����\\�����\\�����\\�����\\����.����������"
//        // ���������: R"(D:\Documents\Visual Studio 2022\MyFile.txt)"
//        // 2. "�����/�����/�����/�����/����.����������"
//        // ���������: "D:/Documents/Visual Studio 2022/MyFile.txt"
//    }
//    
//
//    // ��������� �����:
//    CreateFolder();
//
//    // �������������� �����:
//    RenameFolder();
//
//    // ��������� �����:
//    DeleteFolder();
//
//    // �������� �����:
//    CloseFile();
//
//    // ������� ���������� � �����:
//    WriteIntoFile();
//
//    // ���������� ������� �������� ���������
//    FilePositioning();
//
//    return 0;
//}
//
////�� �������� �����?
//
//#include <iostream>
//#include <string>
//#include <direct.h> //��� _mkdir(), _wmkdir()
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
//    const wchar_t* folder2Name = L"�����";
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
////�� ������������� �����
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
////�� �������� �����?
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
////�� �������� ���� ?
//
//void CreateFile()
//{
//    // ������� ���������/�������� ����� fopen:
//// ��������: 
////              FILE* fopen(const char* filename, const char* mode)
//// ���������:
////              filename - ���� �� ����� ����� � ������ ����� �� �����������
////              mode - ����� �������� �����
//// ���������� ��������: �������� �� �������� ����. nullptr - ���� �� ������� �������/��������
//// 
//// ������: ��� ���� wchar_t ���� ������� _wfopen.
//// 
//// FILE - �� ���������, ��� ������ ���� ���� ���� - �������� �� ����.
//// 
//// �����: ��������� Visual Studio �� ������������� �� �������� ���������������
////              ������� fopen, �� ����� �� �����������. ³� ��������� ���������������
////              �������� ������� fopen_s().
//// 
//// ������� ���������/�������� ����� fopen_s:
//// ��������: 
////              errno_t fopen(FILE** stream, const char* filename, const char* mode)
//// ���������:
////              stream - ������ �� �������� ���� File, �� ����� ����'������� ����
////              filename - ���� �� ����� ����� � ������ ����� �� �����������
////              mode - ����� �������� �����
//    // ���������� ��������: 0 - ���� ������ �������, �������� EINVAL � ����� ��������.
//// ������: ��� ���� wchar_t ���� ������� _wfopen_s.
//
//
//
//// ������ �������� �����:
//// "r"  - ������� ���� ��� �������. ���� ����� �� ���� �� ���� ��������� ������, ����������� nullptr.
//// "w"  - ������� ������ ���� ��� ������. ���� ���� ����, �� ���� ���� �����������.
//// "a"  - ������� ���� ��� ������ � ���� �����. ������� ����, ���� ���� �� ����.
//// "r+" - ������� ���� ��� ������� � ��� ������. ���� �� ��������.
//// "w+" - ������� ������ ���� ��� ������� � ��� ������. ���� ���� ����, �� ���� ���� �����������.
//// "a+" - ������� ���� ��� ������� � ��� ������ � �����. ������� ����, ���� �� �� ����.
//
//// ������ �������� ����� fopen:
////FILE* file1;
////file1 = fopen("sdgsdgh.txt", "r");
////if (file1 == nullptr)
////{
////    std::cout << "File could not been opened.\n";
////}
////
//// ������ �������� ����� fopen_s:
////FILE* file2;
////errno_t openingResult = fopen_s(&file2, "sdgsgdh.txt", "r");
////if (openingResult != 0)
////{
////    std::cout << "File could not been opened.\n";
////}
//}
//
////�� ������������� ���� ?
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
////�� �������� ���� ?
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
////�� ��������� ���������� ����� ?
//
//void CloseFile()
//{
//    // ³������ ���� � �'������ � �������.
//    const char* filename = "SomeFile.bin";
//    FILE* file;
//    fopen_s(&file, filename, "wb");
//
//    while (true)
//    {
//    }
//
//    // ����������� � ������.
//
//    //������� ����, ��'������� ����.
//    fclose(file);
//}
//
//int main()
//{
//    //fopen("MyFile.txt");
//}
//
////������� � ����� �����
//
//int number = 100;
////Myfile < number
////"100"
////0110 0100
//
////�� ������� ���������� � ����� ?
//
//void ReadFromFile()
//{
//    // � ������� ������� ��� ������� ���������� � �����:
//
//    // 1. ��������: int fgetc(FILE* stream)
//    // ����: ���� � ������� ��������� ������ � ������.
//    // ���������: stream - ���� �� ����.
//    // ������� ��������: �������� ������, ���� ������ �������.
//    // ������ EOF.
//
//    // 2. ��������:     char* fgets(char* str, int count, FILE* stream)
//    // ����:            ���� �������� (count - 1) ������� �� ������ � ������
//    //                  �� � ����� str. ���������� �����������, ���� �����������
//    //                  ������ \n ��� ����� �����. ������ ����-������ � �����
//    //                  ������� �����������.
//    // ���������: 
//    // 
//    // str - �����, ���� ����������� �������
//    // count - ����� ������ str
//    // stream - ���� �� ����.
//    // ���������� ��������: str, ���� ������ ������� ������� �����������
//    // nullptr, ����������� ��������
//    // 
//    // 3. ��������:     size_t fread(void* buffer, size_t size, size_t count, FILE* stream)
//    // ����:            ����� �������� count ����� � �������� buffer �� ������ stream
//    // ���������:
//    // 
//    // buffer - ��������, ���� ����������� �����
//    // size - ����� ������� �������� ����������� �����, �� ����� ���������
//    // count - ������� ����� ��� ����������
//    // stream - ���� �� ����
//    // ���������� ��������: ������� ������ �������� �����.
//
//    /*int number;
//    fread(&number, sizeof(number), 1, file);
//
//    double arr[10];
//    fread(arr, sizeof(double), 10, file);*/
//
//    // ������� ������������ ������� fgetc:
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
////�� �������� � ���� ���������� ?
//
//void WriteIntoFile()
//{
//    // � ������� ������� ��� ������ ���������� � ����:
//
//
//
//    // 1. ��������: int fputc(int ch, FILE* stream);
//    //    ����: ������ ������ ch � �������� ���� stream
//    //    ���������: ch - ������
//    //               stream - ����, ��'������ � ������
//    //    ������� ��������: ���� ������ ������ ��������� - ������� ������.
//    //                       ������ - EOF.
//
//    // 2. ��������: int fputs(const char* str, FILE* stream);
//    //    ����: ������ ����� str � �������� ���� stream
//    //    ���������: str - �����
//    //               stream - ����, ��'������ � ������
//    //    ������� ��������: ���� ����� ������ ��������� - ������� ��������� ��������.
//
//    // 3. ��������: size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
//    //    ����: ������ ���, �� �� ����� buffer, � �������� ���� stream
//    // ���������:      buffer - �������� �� ���, �� ����� ��������
//    //                 size - ����� ������� �������� �����, �� ����� ��������
//    //                 count - ������� �������� �����, �� ����� ��������
//    //                 stream - ����, ��'������ � ������
//    //
//    // ���������� ��������: ʳ������ ��'����, �� ���������� ������.
//    //                      ���� �� �������� ����� �� count - ���� ���� �� ���.
//
//    // ������� ������������ ������� fputc:
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
//    // ������� ������������ ������� fputs:
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
////���������� ������� �������� ���������
//
//void FilePositioning()
//{
//    // ������� � ����� � ��������� �� ������� ������� ��� ����������, �� �� ������ 
//    // ��������� � ����. ���������, ���� �� ������������� ������� ��� ������� �� ������,
//    // �� ���� ���������� �������� �� ������� ���������� �� ��������� ���.
//
//    // ������� ��������, ���� ��� ����� ����� ��������������� ��� ���������, ���
//    // ���� ��� ����� ���������� �� ��������� ����� �� ������.
//
//    // ��� ������ � ����������� � ������� �������:
//    // 1. long ftell (FILE* stream) - ������� ������� ��������� ���������
//    // 2. int fseek (FILE* stream, long offset, int origin) - ���������� ������� ��������� ���������
//    // 3. int fgetpos (FILE* stream, fpos_t* pos) - ������ ������� ��������� ���������
//    // 4. int fsetpos (FILE* stream, const fpos_t* pos) - �������� ������� ��������� ���������
//    // 5. void rewind (FILE* stream) - ������� �������� �������� �� �������
//
//    // �������: � ���� � ������ ���� ������. ����� �� ����� "�" � ������� �� �� �0���� "�".
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