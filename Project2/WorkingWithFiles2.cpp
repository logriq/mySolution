#include <ios>
#include <iostream>
#include <istream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
	 �������� ������ ����� / ������ � C++

	 � ����� ���� ios. � ����� � ���� ios_base. � ����� ����������� ������
	 ������ � ���������, �� ����� ����������� �� ������ �����/������.
	 ��������� ��� �� ������ ������� ����������� boolalpha, dec,
	 defaultfloat, fixed � ����.

	 ����� �� ������ ������� ������� std::ios, ��� ��������� ����������
	 �� std::basic_ios<char, char_traits<char>>.

	 ����� ���.

	 ��������� ���� ostream (output stream). � ����� ��� �����������
	 ���� basic_ostream. ��� ���� ���������� �� ����� ios, � ���� ��
	 �� � ��� ����������� � ������ �� ����� clear, fill � �����. ���
	 ��� ���� ������� ����� �� ���������� ���� ������. ����� ���� �����
	 ���������������, ��� �������� ���������� �������. ��� ���� ���
	 �������� ��� �����������, ��� �� endl, ends �� flush, � �����
	 ����� ������������� ��� ��������� <<.

	 ���'����� std::cout? ��� ��, cout - �� ���������� ��'��� (�� ��
	 �����������, �� ���������� �����) ����� �����. � ������ �� �����������
	 �� ��������� ����� ���� std::ostream = basic_ostream<char, char_traits<char>>;

	 ����� ���.

	 ��������� ���� istream (input stream). � ����� ��� �����������
	 ���� basic_istream. ��� �������� ���������: �� ����� ����������
	 �� �� ����� ios, � ���� �� � ��� ����������� � ������.
	 ��� ��� ���� ������� ����� �� ���������� ���� �����. ����� ���� �����
	 ���������������, ��� ������� ���������� ������. ��� ���� ���
	 �������� ��� �����������, ��� �� ws, skipws � ����, � �����
	 ����� ������������� ��� ��������� >>.

	 ���'����� std::cin? ��� ��, cin - �� ���������� ��'��� (�� ��
	 �����������, �� ���������� �����) ����� �����. � ������ �� �����������
	 ������� ��������� std::istream = basic_istream<char, char_traits<char>>;

	 ����� � ���� iostream ����������� ���� basic_iostream, ���� ���������� ��
	 ���� ����� basic_istream �� basic_ostream. �� � ��������, �� �� � ���
	 ������ ��� � ���� ����������.
	
	 � ����� ���������� ��� ����, �� ����������� �������� ��'���� std::cin �
	 std::cout. �� ���� iostream (���� �� ���������). ³� ������� � ����
	 �� �������� ����� � ����� ����� �����. ���� ���� �� ���� � ���������
	 �������, ���� ������ ��������� � ������/������� ���������� � ������.
	
	 � ����� ���� �� �������� ���� ��'����, ��� �� std::cerr � std::clog.
	 ��� ���� ����������� �� std::cout?
	 1. std::cout - �� ����������� ���� ������, ���� ��������������� ��� �����������
	 ������ ���������� � �������. ³� ������������, �� ������, �� ��� �����������
	 � ���'�� ����� �� ����������� � �������/�������. �� ���� ��������� �������������,
	 ������� ����� ��������� ������ ����� ��'������ � ���� ��������.
	 */


	 /*
	----------------------------------------------------------------------------------------
	 
	  ���������� �� ������� ���� ����� ����. � �������� ������ �����/������ �
	  �� ���� fstream (file stream). � ����� ���� ����������� ����� 3 �����:
	  1. ifstream (input file stream) - ����, ���� ������� �� ���������� ����� � �����.
	  2. ofstream (output file stream) - ����, ���� ������� �� ����� ����� � ����.
	  3. fstream (file stream) - ����, ���� � ��'�������� ���� ����� ifstream �� ofstream
	 
	  ���� ifstream ���������� �� basic_istream, � ���� �� ��� ����� ��������� + �������
	  ����� ������ ��� ������ ��������� � ������� (��������� open, is_open).
	 
	  ��������� �������� � ������ ofstream. ³� ���������� �� basic_ostream.
	 
	  ���� fstream ���������� �� ����� basic_iostream � ������ � ��� ��� �� ����
	  ���������� � ����� �� � ����.

	  ---------------------------------------------------------------------------------------
	  */


int main()
{

	/*
	------------------------------------------------------------------------------------------------------

										 �� �������� ����?

	 � ������� ���� � ���� �������� � ����, ��� ���������� _Mystate. ���� �� ��� int � �������
	 �� ���� ������. ���� ���� ���� ������ (������������ / � ���� ����� ���������) ��� ������� (����
	 ����� ��� ���������� ��� ��������� ���������). � ����� ����� ���������� ���� � 4 �������� �������:
	 1. std::ios::goodbit - ������� �� ��, �� ���� ������ ���������. �������������� �� �������������
		��� �������� ������.
	 2. std::ios::eofbit - �������������� ���, ���� ��� ��������� ����� � ������ �� ������� ����� �����
		(eof - End Of File).
	 3. std::ios::failbit - �������������� ���, ���� �������� �������, ��� ����� ���������.
		��������� (���� ���� �� ���� ������ �� ���������� ��� ��-�� �����������
		���� � ����� �� ��� �� ���������� ����������� �������).
	 4. std::ios::badbit - �������������� ���, ���� �������� �������, ��� �� ����� ���������.
		��������� ���� ���� �� ���� ���������/���������� ��� ��-�� ���������� ����,
		�� ���� ����������� ��������.

	 ��� ��������� ���� ������, ������� 4 ������: good(), eof(), fail(), bad(). ����
	 ���������� true, ���� ������������ ���� � 4 ���.

	 ��� ������� �� �������� ��� ���:  */

	 /*std::cout << "Enter a number: ";
	 int number;
	 std::cin >> number;

	 if (std::cin.good())
	 {
		 std::cout << "Your number = " << number << std::endl;
	 }
	 else
	 {
		 std::cout << "Oops. Something went wrong.\n";
		 std::cin >> number;
	 }*/


	 //--------------------------------------------------------------------------------------------------------




 // --------------------------------------------------------------------------------
	 /*
										 �� ���������� ����?

	  1. ���� ���� ������ �� �������� std::ios::eofbit, �� � ������ �������
		 ���� ����� �� ���� ������/���������� � ��� ����� ���� ������� �� ������
		 �������. �������� �� �������� close �� open. �� ���������� ��������
		 ��� ����� � �������.

	  2. ���� ���� ������ �� �������� std::ios::failbit, �� � ������ ������� ��
		 ������ �������� ��������� ����� clear(), ���� ���������� ���� ������ ������
		 � �������� std::ios::goodbit, � ���� ��������� ���� ������� ignore(),
		 ���� ������� ����� �������, ��� �� ������ �� � ���� (��� �� ������
		 �� ���������). ϳ��� ����� ����� ���������� ������.

	  3. ���� ���� ������ �� �������� std::ios::badbit, �� � ������ ������� ��
		 ������ ��������� ����� clear(), ��� �� �� �������, �� ���� ����� �������
		 ��������� ���, ��� �� ����� �� �������������� � "�����������" ���������.
		 ��� ������������� ����� �� ��������� � �������, � ������� ����� (���
		 ������� � ������� ���).

		 ��� ������� �� ������������ ������:
	 {
		 std::cout << "Enter a number: ";
		 int number;
		 std::cin >> number;

		 while (!std::cin.good() && std::cin.fail())
		 {
			 std::cin.clear();
			 std::cout << "You entered incorrect value. Enter only one integer number.\n";
			 std::cin.ignore(LLONG_MAX, '\n');
			 std::cout << "Enter a number: ";
			 std::cin >> number;
		 }
	 }*/

	 // ----------------------------------------------------------------------------



	 /* ----------------------------------------------------------------------------------------------

									 ������ �������� �����

	  1. std::ios::in  - ������� ���� ��� �������. ���� ����� �� ���� - ���� "��������".
	  2. std::ios::out - ������� ���� ��� ������. ���� ����� ���� - ���� ���� ��������� (�������).
						 ���� �� ���� - ���� �����������.
	  3. std::ios::app - ������� ���� ��� ������ � �����. ���� ����� �� ���� - ���� �����������.
	  4. std::ios::trunc - ��������������� � ������� out. ��������� ���� ����������, ���� � �����
						  ���� ���� �� ��������.
	  5. std::ios::ate - ��������������� � ������ ��������. ������� �������� ���������� � �����
						  �����.
	  6. std::ios::binary - ������� ���� � �������� �����. ��������������� � ������ ��������.

	  ------------------------------------------------------------------------------------------------ */



	  /* ------------------------------------------------------------------------------------------------

									������� � ���� �� EOF

	  ��� ����� � ������� ������������� ���� �++ ��� ������ ��� ����, �� � � ������������� ���� �:
	  ��� �'������ ��������� ������ � ������ � ���� ����������� �������� �� ���������� �������
	  � ����. ������ �������� ���� ������� � ����. ���� �� ������� ���� ��� ������� �������
	  ������ std::ios::in, �� ������� ����� �� ������ �������. ��������� � std::ios::out.
	  ��� ���������/����� ���������� � ���� �� ������� ����������� ������ ������, ������ �� �������
	  ����������� ������, ���� �������� ����� �����. ³� ���������� EOF (End Of File). ���� �����
	  ��� ��������� ���������� � ����� ����� ������ ��� � ����� ���������� �� ���������� �� ����� �������.
	  �� �������� ������� � ���� �� �� �� ������, � ������� � ���� �����.
	 
	  --------------------------------------------------------------------------------------------
	
	                               �� ������� ����� � �����?
	
	  ����� ����� ������ � ����� ������ ��������� (�� ������ �� � ���� 4 �������):
	  1. �����������.
	
	  {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :(\n";
            return 1;
        }

        char character;
        while (fileStream.get(character))
        {
            std::cout << character;
        }

        if (fileStream.eof())
        {
            std::cout << "\n\nWe reached the end of the file.\n";
        }

		2. ���������

		{
		std::string filename = "MyTextFile.txt";
		std::ifstream fileStream(filename);

		if (!fileStream.is_open())
		{
			std::cerr << "Couldn't open the file. :(\n";
			return 1;
		}

		std::string Line;
		while (std::getline(fileStream, Line, '\n'))
		{
			std::cout << Line;
		}

		if (fileStream.eof())
		{
			std::cout << "\n\nWe reached the end of the file.\n";
		}
	}
	 
	   3. ���������

	{
		std::string filename = "MyTextFile.txt";
		std::ifstream fileStream(filename, std::ios::binary);

		if (!fileStream.is_open())
		{
			std::cerr << "Couldn't open the file. :(\n";
			return 1;
		}

		// ��������� ������� ����� � ����:
		fileStream.seekg(0, std::ios::end);
		size_t fileSize = fileStream.tellg();
		fileStream.seekg(0, std::ios::beg);

		// �������� ���������� �����:
		size_t bufferLength = fileSize + 1;
		char* buffer = new char[bufferLength];
		fileStream.read(buffer, fileSize);
		buffer[fileSize] = '\0';

		// ���������, �� ���� ���� ������� �������:
		if (fileStream.gcount() != fileSize)
		{
			std::cerr << "Error reading file. :(\n";
			return 1;
		}

		std::cout << buffer;
		delete[] buffer;
	}

	  4. ������� ��������������� ��������� >> ��� ����, �� �� �� ������ � std::cin.
    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :(\n";
            return 1;
        }

        std::string word;
        while (fileStream >> word) // ��������, ������������� ������� �������
        {
            std::cout << word;
        }
    }
	 
	 */


	 /* ----------------------------------------------------------------------------------------
		 
		                                �� �������� ����� � ����?
		 
		  ����� ����� �������� � ���� ������ ��������� (�� ������ �� � ���� 3 �������):
		  1. �����������.
		{
			 std::string filename = "MyTextFile1.txt";
std::ofstream fileStream(filename, std::ios::out);

		if (!fileStream.is_open())
		{
			std::cerr << "Couldn't open the file. :(\n";
			return 1;
		}

		std::cout << "Enter some text: ";
		std::string text;
		std::getline(std::cin, text);

		size_t textLength = text.length();
		for (size_t i = 0; i < textLength; ++i)
		{
			fileStream.put(text[i]);
		}

		2. ��������� ������� ��������������� ��������� << ��� ����, �� �� �� ������ � std::cout.
	{
		std::string filename = "MyTextFile2.txt";
		std::ofstream fileStream(filename);

		if (!fileStream.is_open())
		{
			std::cerr << "Couldn't open the file. :(\n";
			return 1;
		}

		std::string line1 = "Today is a good day!";
		std::string line2 = "Because I am recording a lesson!";

		fileStream << line1 << '\n' << line2 << '\n' << 1000;
	}



	 3. ���������.
	{
		std::string filename = "MyTextFile3.txt";
		std::ofstream fileStream(filename, std::ios::binary);

		if (!fileStream.is_open())
		{
			std::cerr << "Couldn't open the file. :(\n";
			return 1;
		}

		std::string line = "Some line of text.";
		fileStream.write(line.c_str(), line.length());
	}

	*/




	/* ----------------------------------------------------------------------------------------
	
	                               �� �������� �� ����� � ����?
	
	³������ ������� ����� ����� ����:
	int variable = 10;
	double array[3] = { 1.123, 2.455, 3.789 };

	class Point
	{
	private:
		float x;
		float y;

	public:
		Point(float x = 0, float y = 0)
			: x(x), y(y)
		{
		}

		float X() const { return x; }
		float Y() const { return y; }
	};

	Point myPoint(12.3f, 54.6f);
	std::vector<int> myVector = { 1, 2, 3, 4, 5 };

	// �� ���� ����������� ������� ������ write. ��� �� ����� �������� - ��
	// ��, �� ��� ����� ������ ��� � ������, ����� ���� ����� ���������� ������
	// ���� char (��� �� ����� ���� char ������� �� ����� ������ �����).
	//
	// ���� ��� ����� ������������� ���� ��� � ������ �� ��� ��� � ����������
	// ����� ������.
	//
	// �������� �������� ����, � ���� �������� �� �� ���, ���������.

	std::string filename = "MyData.bin"; // �� �� ������� �� �����, �� ��� �� ���.
	std::ofstream fileStream(filename, std::ios::binary);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file. :(\n";
		return 1;
	}

	int variable - 10;
	fileStream.write(reinterpret_cast<const char*>(&variable), sizeof(variable));

	fileStream.write(reinterpret_cast<const char*>(array), sizeof(double) * 3);

	fileStream.write(reinterpret_cast<const char*>(&myPoint), sizeof(Point));

	fileStream.write(reinterpret_cast<const char*>(myVector.data()), sizeof(int) * myVector.size());
}

*/



/* --------------------------------------------------------------------------------------------

                               �� ������� �� ����� � �����?

 ��� ������� �� ����� �� �����, ��� ����� �������� �������� �� ��� � ����� �������:
	int variable;
	double array[3];

	class Point
	{
	private:
		float x;
		float y;

	public:
		Point(float x = 0, float y = 0)
			: x(x), y(y)
		{
		}

		float X() const { return x; }
		float Y() const { return y; }

		Point myPoint;
	std::vector<int> myVector(5);

	// � ����� ������� ������ read �� ������� �� ��� � ������ � �������, �� � ����������.
	// �� ���� ����� ��� �������.
	std::string filename = "MyData.bin";
	std::ifstream fileStream(filename, std::ios::binary);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file. :(\n";
		return 1;
	}

	fileStream.read(reinterpret_cast<char*>(&variable), sizeof(variable));

	fileStream.read(reinterpret_cast<char*>(array), sizeof(double) * 3);

	fileStream.read(reinterpret_cast<char*>(&myPoint), sizeof(Point));

	fileStream.read(reinterpret_cast<char*>(myVector.data()), sizeof(int) * myVector.size());

	std::cout << "variable = " << variable << std::endl;

	std::cout << "array = ";
	for (size_t i = 0; i < 3; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
*/


/* ------------------------------------------------------------------------------------
	
	                               �� ������� �������� ����?
	
	 ���� �� ����������� � ������� � ����� �� ������� � ��� ��������� �� ���� ����
	 ������ �������� (����� ���� ��'��� ������ �� ���������), �� ������ ������� ����.
	 ������� ������ ���'����� ���� �� �����, ��� ������ ����� ������������� ���� ������.
	 ��� ����� �������������� ����� close():
	
	 ³������ ����:
	 std::string filename = "SomeFile";
	 std::ifstream fileStream(filename);
	
	 ... ����������� � ������� ...
	
	 ������� ����:
	 fileStream.close();
	
	 ����� �� ���� �����, �� ����� std::ifstream, std::ofstream, �� std::fstream
	 ����� ����������, ���� ����������� ������� ����� close.
	
	 -----------------------------------------------------------------------------------   */



	 /* ------------------------------------------------------------------------------------------
		 
		                                �� ������� �������� ����?
		 
		  ���� �� ����������� � ������� � ����� �� ������� � ��� ��������� �� ���� ����
		  ������ �������� (����� ���� ��'��� ������ �� ���������), �� ������ ������� ����.
		  ������� ������ ���'����� ���� �� �����, ��� ������ ����� ������������� ���� ������.
		  ��� ����� �������������� ����� close():
		 
		  ³������ ����:
		std::string filename = "SomeFile";
		std::ifstream fileStream(filename);
		 
		... ����������� � ������� ...

*/

}

