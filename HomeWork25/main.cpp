# include <iostream>
#include <string>

bool check_Palindrom(std::string str); // Функция проверки строки на палиндром
short syntax_String(std::string str); // Функция подсчёта кол-ва символов пробела, точки, запятой, восклицательного и вопросительного знаков
std::string part_String(std::string str, char sym); // Функция возврата подстроки, начинающейся с последнего символа sym строки str

int main() {

	// Задача 1. Новая строка из совпадений символов
	std::cout << "\033[91mTask 1. New string from character matches\033[0m\n\nSource string is: ";
	std::string my_Dream = "I'd like to become a very smart programmer!"; // Строка с исходным текстом
	char sym; // Переменная для хранения введённого пользователем символа
	std::string result = ""; // Строка для формирования ответа
	std::cout << "\033[93m" << my_Dream << "\033[0m\n\n";
	std::cout << "Enter a symbol -> ";
	std::cin >> sym;
	std::cin.ignore();
	for (short i = 0; i < my_Dream.length(); i++) // Цикл расчёта повторений символа sym в строке my_Dream
		if (sym == tolower(my_Dream[i]) || sym == toupper(my_Dream[i]))
			result += sym;
	std::cout << "\nFinal string is: \033[92m" << result << "\033[0m\n\n";

	// Задача 2. Проверка на палиндром
	std::cout << "\033[91mTask 2. Checking for palindrome\033[0m\n\nEnter a word -> ";
	std::string my_Word;
	std::getline(std::cin, my_Word);
	std::cout.setf(std::ios_base::boolalpha);
	std::cout << "\n\033[92m" << check_Palindrom(my_Word) << "\033[0m\n\n";

	// Задача 3. Синтактические символы строки
	std::cout << "\033[91mTask 3. String syntax characters\033[0m\n\nEnter a string -> ";
	std::string str;
	std::getline(std::cin, str);
	std::cout << "\nNumber of characters ' ', '.', ',', '!', '?' in the entered string is \033[92m" << syntax_String(str) << "\033[0m\n\n";

	// Задача 4. Часть строки
	std::cout << "\033[91mTask 4. Part of a string\033[0m\n\nSource string is: ";
	std::string my_Promise = "I'll devote more free time to my education";
	char symbol; // Переменная для хранения введённого пользователем символа
	std::cout << "\033[93m" << my_Promise << "\033[0m\n\n";
	std::cout << "Enter a sumbol to form a substring -> ";
	std::cin >> symbol;
	std::cout << "Part of a string is: \033[93m" << part_String(my_Promise, symbol) << "\033[0m" << std::endl;

	return 0;
}

bool check_Palindrom(std::string str) {
	short length = str.length(); // Переменная для хранения длины строки
	for (short i = 0; i < length / 2; i++)
		if (tolower(str[i]) != tolower(str[length - i - 1]))
			return false;
	return true;
}

short syntax_String(std::string str) {
	short length = str.length(); // Переменная для хранения длины строки
	short counter = 0; // Переменная для подсчёта кол-ва символов пробела, точки, запятой, восклицательного и вопросительного знаков
	for (short i = 0; i < length; i++)
		if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
			counter++;
	return counter;
}

std::string part_String(std::string str, char sym) {
	return (str.rfind(sym) == std::string::npos) ? "" : str.substr(str.rfind(sym));
}

