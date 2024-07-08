#include <iostream>
#include <string>

class bad_length : public std::exception {
public:
	const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(std::string str, int forbidden_length) {

	if (str.length() == forbidden_length) throw bad_length();
	return str.length();
}

int main(int argc, char** argv)
{

	setlocale(LC_ALL, "Russian");

	int num_lenght = 0;
	std::string word;

	for (int i = 0; i < 10; ++i) {

		std::cout << "Введите запретную длину: ";
		std::cin >> num_lenght;
		std::cout << "Введите слово: ";
		std::cin >> word;

		try
		{
			function(word, num_lenght);
		}
		catch (const bad_length& ex) { std::cout << ex.what(); return 1; }


	}

	return 0;
}