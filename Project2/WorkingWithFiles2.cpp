#include <ios>
#include <iostream>
#include <istream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
	 Ієрархія потоків вводу / виводу в C++

	 Є такий файл ios. В ньому є клас ios_base. В ньому знаходяться основні
	 методи і константи, які мають підтримувати всі потоки вводу/виводу.
	 Наприклад тут ви можете зустріти маніпулятори boolalpha, dec,
	 defaultfloat, fixed і інші.

	 Також ви можете зустріти сутність std::ios, яка являється псевдонімом
	 до std::basic_ios<char, char_traits<char>>.

	 Йдемо далі.

	 Наступний файл ostream (output stream). В ньому уже знаходиться
	 клас basic_ostream. Цей клас наслідується від класу ios, а отже має
	 всі ті самі маніпулятори і методи на подобі clear, fill і інших. Але
	 цей клас відповідає тепер за конкретний потік виводу. Тобто його треба
	 використовувати, щоб виводити інформацію звідкись. Цей клас уже
	 добавляє свої маніпулятори, такі як endl, ends та flush, а також
	 безліч перевантажень для оператора <<.

	 Пам'ятаєте std::cout? Так от, cout - це глобальний об'єкт (де він
	 створюється, ми поговоримо пізніше) цього класу. А точніше він створюється
	 як глобальна змінна типу std::ostream = basic_ostream<char, char_traits<char>>;

	 Йдемо далі.

	 Наступний файл istream (input stream). В ньому уже знаходиться
	 клас basic_istream. Тут ситуація аналогічна: він також наслідується
	 від від класу ios, а отже має ті самі маніпулятори і методи.
	 Але цей клас відповідає тепер за конкретний потік вводу. Тобто його треба
	 використовувати, щоб вводити інформацію кудись. Цей клас уже
	 добавляє свої маніпулятори, такі як ws, skipws і інші, а також
	 безліч перевантажень для оператора >>.

	 Пам'ятаєте std::cin? Так от, cin - це глобальний об'єкт (де він
	 створюється, ми поговоримо пізніше) цього класу. А точніше він створюється
	 завдяки псевдоніму std::istream = basic_istream<char, char_traits<char>>;

	 Також у файлі iostream знаходиться клас basic_iostream, який наслідується від
	 двох класів basic_istream та basic_ostream. Ну і очевидно, що він в собі
	 комбінує ввід і вивід інформації.
	
	 А тепер поговоримо про місце, де створюються глобальні об'єкти std::cin і
	 std::cout. Це файл iostream (який ви підключаєте). Він підключає в себе
	 всі попередні файли а також безліч інших. Саме тому ми його і підключаємо
	 постійно, якщо хочемо працювати з вводом/виводом інформації в консолі.
	
	 В цьому файлі ви знайдете інші об'єкти, такі як std::cerr і std::clog.
	 Чим вони відрізняються від std::cout?
	 1. std::cout - це стандартний потік виводу, який використовується для нормального
	 виводу інформації у програмі. Він буферизується, що означає, що дані зберігаються
	 в пам'яті перед їх надсиланням в консоль/термінал. Це може покращити продуктивність,
	 оскільки кілька операторів виводу можна об'єднати в одну операцію.
	 */


	 /*
	----------------------------------------------------------------------------------------
	 
	  Переходимо до головної теми цього відео. В ієрархії потоків вводу/виводу є
	  ще файл fstream (file stream). В цьому файлі знаходяться зразу 3 класи:
	  1. ifstream (input file stream) - клас, який відповідає за ЗЧИТУВАННЯ даних з файлу.
	  2. ofstream (output file stream) - клас, який відповідає за ЗАПИС даних у файл.
	  3. fstream (file stream) - клас, який є об'єднанням двох класів ifstream та ofstream
	 
	  Клас ifstream наслідується від basic_istream, а отже має той самий інтерфейс + декілька
	  нових методів для роботи конкретно з файлами (наприклад open, is_open).
	 
	  Аналогічна ситуація з класом ofstream. Він наслідується від basic_ostream.
	 
	  Клас fstream наслідується від класу basic_iostream і комбінує в собі ввід та вивід
	  інформації з файлу чи у файл.

	  ---------------------------------------------------------------------------------------
	  */


int main()
{

	/*
	------------------------------------------------------------------------------------------------------

										 Як поламати потік?

	 В кожному класі з нашої ієрархії є поле, яке називається _Mystate. Воно має тип int і відповідає
	 за стан потоку. Стан може бути добрим (полагодженим / з яким можна працювати) або поганим (який
	 треба або полагодити або перестати працювати). В цьому числу записується одне з 4 можливих значень:
	 1. std::ios::goodbit - відповідає за те, що потік працює нормально. Встановлюється за замовчуванням
		при створенні потоку.
	 2. std::ios::eofbit - встановлюється тоді, коли при зчитуванні даних з потоку ми зустріли кінець файлу
		(eof - End Of File).
	 3. std::ios::failbit - встановлюється тоді, коли відбулася помилка, яку можна виправити.
		Наприклад (коли потік не може читати чи записувати дані із-за тимчасового
		збою в мережі чи дані не відповідають очікуваному формату).
	 4. std::ios::badbit - встановлюється тоді, коли відбулася помилка, яку не можна виправити.
		Наприклад коли потік не може зчитувати/записувати дані із-за апаратного збою,
		чи потік неочікувано закрився.

	 Щоб перевірити стан потоку, існують 4 методи: good(), eof(), fail(), bad(). Вони
	 повертають true, якщо встановлений один з 4 бітів.

	 Ось приклад на перевірку цих бітів:  */

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
										 Як полагодити потік?

	  1. Якщо стан потоку має значення std::ios::eofbit, то в такому випадку
		 потік дійшов до кінця запису/зчитування і вам треба його закрити та заново
		 відкрити. Робиться це методами close та open. Це відбувається зазвичай
		 при роботі з файлами.

	  2. Якщо стан потоку має значення std::ios::failbit, то в такому випадку ви
		 можете спочатку викликати метод clear(), який встановить стан потоку заново
		 в значення std::ios::goodbit, а потім почистити потік методом ignore(),
		 який витягне звідти символи, але не запише їх в потік (щоб він заново
		 не поламався). Після цього можна продовжити роботу.

	  3. Якщо стан потоку має значення std::ios::badbit, то в такому випадку ви
		 можете викликати метод clear(), але це не гарантує, що потік зможе спокійно
		 працювати далі, так як такий біт встановлюється у "невиправних" ситуаціях.
		 Тут рекомендується більше не працювати з потоком, а відкрити новий (або
		 закрити і відкрити цей).

		 Ось приклад на полагодження потоку:
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

									 Режими відкриття файлу

	  1. std::ios::in  - відкрити файл для читання. Якщо файлу не існує - потік "ламається".
	  2. std::ios::out - відкрити файл для запису. Якщо файлу існує - його вміст очищається (можливо).
						 Якщо не існує - файл створюється.
	  3. std::ios::app - відкрити файл для запису в кінець. Якщо файлу не існує - файл створюється.
	  4. std::ios::trunc - використовується з режимом out. Заставляє файл очиститися, якщо в ньому
						  щось було до відкриття.
	  5. std::ios::ate - використовується з іншими режимами. Переміщає вказівник зчитування в кінець
						  файлу.
	  6. std::ios::binary - відкрити файл в бінарному режимі. Використовується з іншими режимами.

	  ------------------------------------------------------------------------------------------------ */



	  /* ------------------------------------------------------------------------------------------------

									Позиція у файлі та EOF

	  При роботі з файлами інструментами мови С++ все працює так само, як і з інструментами мови С:
	  При з'єднанні файлового потоку з файлом у файлі появляється вказівник на конкретний елемент
	  у файлі. Будемо називати його позиція у файлі. Якщо ви відкрили файл для читання завдяки
	  режиму std::ios::in, то позиція вказує на перший елемент. Аналогічно з std::ios::out.
	  При зчитуванні/записі інформації у файл ця позиція переміщується завжди вперед, допоки не зустріне
	  спеціальний символ, який символізує кінець файлу. Він називається EOF (End Of File). Тому часто
	  при зчитуванні інформації з файлу треба писати код в якому зчитування має відбуватися до цього символу.
	  Як дізнатися позицію у файлі та як її змінити, я розповім в кінці уроку.
	 
	  --------------------------------------------------------------------------------------------
	
	                               Як зчитати текст з файлу?
	
	  Текст можна читати з файлу трьома способами (по крайній мірі я знаю 4 способи):
	  1. Посимвольно.
	
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

		2. Порядково

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
	 
	   3. Побайтово

	{
		std::string filename = "MyTextFile.txt";
		std::ifstream fileStream(filename, std::ios::binary);

		if (!fileStream.is_open())
		{
			std::cerr << "Couldn't open the file. :(\n";
			return 1;
		}

		// Визначити кількість байтів у файлі:
		fileStream.seekg(0, std::ios::end);
		size_t fileSize = fileStream.tellg();
		fileStream.seekg(0, std::ios::beg);

		// Створити тимчасовий масив:
		size_t bufferLength = fileSize + 1;
		char* buffer = new char[bufferLength];
		fileStream.read(buffer, fileSize);
		buffer[fileSize] = '\0';

		// Перевірити, чи файл було повністю зчитано:
		if (fileStream.gcount() != fileSize)
		{
			std::cerr << "Error reading file. :(\n";
			return 1;
		}

		std::cout << buffer;
		delete[] buffer;
	}

	  4. Завдяки перевантаженому оператору >> так само, як ви це робите з std::cin.
    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :(\n";
            return 1;
        }

        std::string word;
        while (fileStream >> word) // обережно, пропускаються пробільні символи
        {
            std::cout << word;
        }
    }
	 
	 */


	 /* ----------------------------------------------------------------------------------------
		 
		                                Як записати текст у файл?
		 
		  Текст можна записати у файл трьома способами (по крайній мірі я знаю 3 способи):
		  1. Посимвольно.
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

		2. Порядково завдяки перевантаженому оператору << так само, як ви це робите з std::cout.
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



	 3. Побайтово.
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
	
	                               Як записати НЕ текст у файл?
	
	Візьмемо декілька даних різних типів:
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

	// Всі вони записуються завдяки методу write. Все що треба зрозуміти - це
	// те, що цей метод записує дані в байтах, тобто йому треба відправляти адресу
	// типу char (так як розмір типу char відповідає за розмір одного байту).
	//
	// Тому вам треба перетворювати ваші дані в адресу на цей тип і відправляти
	// цьому методу.
	//
	// Спробуємо створити файл, в який запишемо всі ці дані, послідовно.

	std::string filename = "MyData.bin"; // він її написав від балди, це ролі не грає.
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

                               Як зчитати НЕ текст з файлу?

 Щоб зчитати не текст із файлу, вам треба спочатку створити ці дані у вашій програмі:
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

	// А тепер завдяки методу read ми зчитаємо ці дані в такому ж порядку, як і записували.
	// Ви маєте знати цей порядок.
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
	
	                               Як закрити файловий потік?
	
	 Якщо ви попрацювали з потоком і більше не плануєте з ним працювати до кінця його
	 області видимості (тобто поки об'єкт потоку не знищиться), ви можете закрити його.
	 Закрити означає відв'язати потік від файлу, щоб файлом могли користуватися інші потоки.
	 Для цього використовуйте метод close():
	
	 Відкрили потік:
	 std::string filename = "SomeFile";
	 std::ifstream fileStream(filename);
	
	 ... Попрацювали з потоком ...
	
	 Закрили потік:
	 fileStream.close();
	
	 Також ви маєте знати, що класи std::ifstream, std::ofstream, та std::fstream
	 мають деструктор, який автоматично викликає метод close.
	
	 -----------------------------------------------------------------------------------   */



	 /* ------------------------------------------------------------------------------------------
		 
		                                Як закрити файловий потік?
		 
		  Якщо ви попрацювали з потоком і більше не плануєте з ним працювати до кінця його
		  області видимості (тобто поки об'єкт потоку не знищиться), ви можете закрити його.
		  Закрити означає відв'язати потік від файлу, щоб файлом могли користуватися інші потоки.
		  Для цього використовуйте метод close():
		 
		  Відкрили потік:
		std::string filename = "SomeFile";
		std::ifstream fileStream(filename);
		 
		... Попрацювали з потоком ...

*/

}

