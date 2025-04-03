#include <iostream>
#include <cstring>

int main()
{
	// General Information

	// There is a templated class std::basic_string' designed
	// to manipulate strings of any character type.

	// This class generalizes how sequences of characters are
	// manipulated and stored. String creation, manipulation,
	// and destruction are all handled by a convenient set of
	// class methods and related functions.

	// Several specializations of std::basic_string are provided for commonly - used types:
	//         Alias       | Specialization                 |
	// | std::string   | std::basic_string<char>        |
	// | std::wstring  | std::basic_string<wchar_t>     |
	// | std::u8string | std::basic_string<char8_t>     | (C++20)
	// | std::u16string | std::basic_string<char16_t>   | (C++11)
	// | std::u32string | std::basic_string<char32_t>   | (C++11)

	// Most popular specialization is std::string.

	// Don't forget to include <string> file to use all std::basic_string specializations.

	// Member Types

	// std::string::value_type
	// std::string::traits_type

	// std::string::allocator_type

	// std::string::size_type
	// std::string::difference_type

	// std::string::reference
	// std::string::const_reference

	// std::string::pointer
	// std::string::const_pointer

	// std::string::iterator
	// std::string::const_iterator

	// std::string::reverse_iterator
	// std::string::const_reverse_iterator

	//Destructor
	// All characters stored in free store,
	// so when you destroy std::string object,
	// it calls destructor.

}


void Constants();
void Constructor();
void AssignmentOperator();
void Method_assign();
void Method_get_allocator();
void Iterators();
void Capacity();
void Operations();
void Search();
void NonMemberFunctions();


void Constants()
{
	std::cout << "------------ Constants -----------\n\n";

	// std::string::npos - static special value equal to the maximum value representable by the type si
	// There are many functions which work with std::string, and they return std::string::npos
	// in some cases.
	std::cout << "std::string::npos = " << std::string::npos << "\n\n";

	system("pause");
	system("cls");
}

void Constructor()
{
	std::cout << "---------------------- Constructor ----------------------" << "\n\n";

	// std::string has a lot of constructors (18 in C++20).
	// Here are most popular of them.

	// 1. Default Constructor - constructs an empty string.
	std::cout << "Default Constructor:\n";

	std::string str1;
	std::cout << "str1 = [" << str1 << "]" << "\n\n";

	// 2. C-string Constructor.
	std::cout << "C-string Constructor:\n";

	std::string str2("Hello str2");
	std::string str3{ "Hello str3" };
	std::string str4 = "Hello str4";

	std::cout << "str2 = [" << str2 << "]\n";
	std::cout << "str3 = [" << str3 << "]\n";
	std::cout << "str4 = [" << str4 << "]\n\n";

	// 3. Copy Constructor.
	std::cout << "Copy Constructor:\n";

	std::string str5(str2);
	std::cout << "str5 = " << str5 << "\n\n";

	// 4. Move Constructor
	std::cout << "Move Constructor:\n";
	std::string str6(std::move(str3));
	std::cout << "str6 = [" << str6 << "]\n\n";

	// 5. Characters count Constructor
	std::cout << "Characters count Constructor:\n";
	std::string str7(5, 'A');
	std::cout << "str7 = [" << str7 << "]\n\n";

	// 6. std::initializer_list Constructor
	std::cout << "std::initializer_list Constructor:\n";
	std::string str8{ '1', '2', '3' };
	std::cout << "str8 = [" << str8 << "]\n\n";

	// 7. Partial Copy Constructor
	std::cout << "Partial Copy Constructor:\n";
	std::string str9("Hello world");
	std::string str10(str9, 6, 5);
	std::cout << "str10 = [" << str10 << "]\n\n";

	// 8. Partial Copy (with chars count) Constructor
	std::cout << "Partial Copy (with chars count) Constructor:\n";
	std::string str11("My name is Gory Entov");
	std::string str12(str11, 11, 4);
	std::cout << "str12 = [" << str12 << "]\n\n";

	// 9. Partial Copy from C-str Constructor
	std::cout << "Partial Copy from C-str Constructor:\n";
	std::string str13("Hello World", 5);
	std::cout << "str13 = [" << str13 << "]\n\n";

	system("pause");
	system("cls");
}

void AssignmentOperator()
{
	std::cout << "--------------------------------- operator= ---------------------------------\n\n";

	// You can assign one string to another using overloaded assignment operator.
	// This operator has 5 overloads.

	// 1. Assign character.
	std::cout << "Assign character:\n";
	std::string str1 = "str1";
	std::cout << "str1 = [" << str1 << "]\n";
	str1 = ' ';
	std::cout << "str1 = [" << str1 << "]\n\n";

	// 2. Assign C-string.
	std::cout << "Assign C-string:\n";
	std::string str2 = "str2";
	std::cout << "str2 = [" << str2 << "]\n";
	str2 = "abc";
	std::cout << "str2 = [" << str2 << "]\n\n";

	// 3. Assign std::initializer_list.
	// 3. Assign std::initializer_list.
	std::cout << "Assign std::initializer_list:\n";
	std::string str3 = "str3";
	std::cout << "str3 = [" << str3 << "]\n";
	str3 = { '1', 'A', '#' };
	std::cout << "str3 = [" << str3 << "]\n\n";

	// 4. Assign std::string.
	std::cout << "Assign std::string:\n";
	std::string str4 = "str4";
	std::string str5 = "str5";
	std::cout << "str4 = [" << str4 << "]\n";
	str4 = str5;
	std::cout << "str4 = [" << str4 << "]\n\n";

	// 5. Assign with moving std::string.
	std::cout << "Assign with moving std::string:\n";
	std::string str6 = "str6";
	std::cout << "str6 = [" << str6 << "]\n";
	std::cout << "str5 = " << str5 << "\n";
	str6 = std::move(str5);
	std::cout << "str6 = [" << str6 << "]\n";
	std::cout << "str5 = " << str5 << "\n";

	system("pause");
	system("cls");
}

void Method_assign()
{
	std::cout << "--------------------------------- assign ---------------------------------\n\n";

	// operator= can have only 1 parameter, and that's bad.
	// So you can use 'assign' method for more possibilities.
	// This method has 8 overloads. Here are 7 of them.

	std::string str1;

	std::cout << "str1 = [" << str1 << "]\n";

	str1.assign(3, ' ');
	std::cout << "str1 = [" << str1 << "]\n";

	str1.assign("Later bitches");
	std::cout << "str1 = [" << str1 << "]\n";

	str1.assign("Hello World!", 5);
	std::cout << "str1 = [" << str1 << "]\n";

	std::string str2("Oh my God! Look at your ass!");
	str1.assign(str2, 6, 3);
	std::cout << "str1 = [" << str1 << "]\n";

	str1.assign(str2);
	std::cout << "str1 = [" << str1 << "]\n";

	str1.assign({ 'a', 'b', 'c' });
	std::cout << "str1 = [" << str1 << "]\n";

	str1.assign(std::move(str2));
	std::cout << "str1 = [" << str1 << "]\n";
	std::cout << "str2 = [" << str2 << "]\n\n";

	system("pause");
	system("cls");
}


void Method_get_allocator()
{
	// std::string is being constructed with associated allocator
	// (3td template parameter). You can get this allocator by invoking this method.

	std::string str;
	std::allocator<char> allocator = str.get_allocator();
}


void ElementAccess()
{
	std::cout << "--------------------------------- Element Access ---------------------------------\n\n";

	// Method 'at' return character by index and throws 'std::out_of_range'
	// exception if index is incorrect.
	std::cout << "Method 'at()':\n";
	std::string str1 = "Hello";
	std::cout << "str1 = [";
	for (size_t i = 0; i < str1.length(); i++)
	{
		std::cout << str1.at(i);
	}
	std::cout << "]\n\n";

	// operator[] return character by index
	std::cout << "Method 'operator[]':\n";
	std::string str2 = "Goodbye";
	std::cout << "str2 = [";
	for (size_t i = 0; i < str2.length(); i++)
	{
		std::cout << str2[i];
	}
	std::cout << "]\n\n";

	// Method 'front' returns reference to first element.
	// Method 'back' returns reference to last element.
	std::cout << "Method 'front()' and 'back()':\n";
	std::string str3 = "abc";
	std::cout << "front = " << str3.front() << "\n";
	std::cout << "back = " << str3.back() << "\n\n";

	// Methods 'data' and 'c_str' return internal character
	std::cout << "Method 'data()' and 'c_str()':\n";
	const char* ptr1 = str3.data();
	std::cout << "ptr1 = [" << ptr1 << "]\n";
	const char* ptr2 = str3.c_str();
	std::cout << "ptr2 = [" << ptr2 << "]\n\n";

	system("pause");
	system("cls");

}

void Iterators()
{
	std::cout << "--------------------------------- Iterators ---------------------------------\n\n";

	// To work with iterators, std::string has some methods.
	// 'begin' and 'end' for working with variable characters.
	std::string str1 = "hello lower world";

	for (std::string::iterator it = str1.begin(); it != str1.end(); ++it)
	{
		*it = std::toupper(*it);
	}

	// 'cbegin' and 'cend' for working with const characters.
	std::cout << '\t' << "str1 = [";

	for (std::string::const_iterator it = str1.cbegin(); it != str1.cend(); ++it)
	{
		std::cout << *it;
	}

	// 'cbegin' and 'cend' for working with const characters.
	std::cout << '\t' << "str1 = [";

	for (std::string::const_iterator it = str1.cbegin(); it != str1.cend(); ++it)
	{
		std::cout << *it;
	}

	std::cout << "]\n";

	// 'rbegin' and 'rend' for working with variable characters from the end.
	std::string str2 = "abcde";

	for (std::string::reverse_iterator it = str2.rbegin(); it != str2.rend(); ++it)
	{
		*it = std::toupper(*it);
	}

	// 'crbegin' and 'crend' for working with const characters from the end.
	std::cout << '\t' << "str2 = [";

	for (std::string::const_reverse_iterator it = str2.crbegin(); it != str2.crend(); ++it)
	{
		std::cout << *it;
	}

	std::cout << "]\n\n";

	system("pause");
	system("cls");

}


