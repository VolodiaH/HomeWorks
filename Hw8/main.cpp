#include <iostream>
#include <format>

void translateArray(int numbers[], int size);
void toUppercase(char str[]);
bool isPalindrom(const char str[]);
void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount);
bool isEqual(const char str1[], const char str2[]);

int main()
{
	constexpr int bufferSize{ 256 };

	{
		std::cout << "\n-----------------------------------------------1-----------------------------------------------------\n";
		constexpr int size{ 10 };
		int numbers[size];
		int count{};
		for (int count{ 0 }; count < size; ++count)
			std::cin >> numbers[count];
		
		translateArray(numbers, size);
	}

	{
		std::cout << "\n-----------------------------------------------2-----------------------------------------------------\n";

		char string[bufferSize];
		std::cin >> string;
		toUppercase(string);
	}
	
	{
		std::cout << "\n-----------------------------------------------3-----------------------------------------------------\n";

		char string[bufferSize];
		std::cin >> string;
		std::cout << std::format("{}", isPalindrom(string));
	}

	{
		std::cout << "\n-----------------------------------------------4-----------------------------------------------------\n";

		char string[bufferSize];
		std::cin >> string;
		int vowels{}, constonants{};
		parseStringLetters(string, vowels, constonants);
		std::cout << std::format("vowels: {}, constonants: {}", vowels, constonants);
	}

	{
		std::cout << "\n-----------------------------------------------5-----------------------------------------------------\n";

		char string[bufferSize];
		char string2[bufferSize];
		std::cout << "String 1:";
		std::cin.getline(string, bufferSize);
		std::cout << "String 2:";
		std::cin.getline(string2, bufferSize);
		
		std::cout << std::format("{} == {} is {}", string, string2, isEqual(string, string2));
	}
}

void translateArray(int numbers[], int size) 
{
	for (int i{}; i < size; ++i)
		std::cout << ((numbers[i] >= 0) ? numbers[i] * 2 : 0 ) 
		<< " ";
}

void toUppercase(char str[]) 
{
	for (char* ptr{ str }; *ptr; ++ptr)
	{
		if ('a' <= *ptr && *ptr <= 'z')
			std::cout << char{*ptr - ('a' - 'A')};
		else
			std::cout << *ptr;
	}
}

bool isPalindrom(const char str[]) 
{
	// I guess it should be done with out strlen...
	int count{};
	while (str[count++] != '\0');
	--count;

	for (int i{}, j{count - 1}; i < count / 2; ++i, --j)
	{
		if (str[i] != str[j])
			return false;
	}

	return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
	for (char* ptr{ const_cast<char*> (str) }; *ptr; ++ptr)
	{
		if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' || *ptr == 'y' ||
			*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U' || *ptr == 'Y'
			)
			++vowelsCount;
		else
			++constonantsCount;
	}
}

bool isEqual(const char str1[], const char str2[]) 
{
	if (str1[0] == '\0' && str2[0] == '\0')
		return true;

	char *ptr1{ const_cast<char*> (str1) };
	char *ptr2{ const_cast<char*> (str2) };

	while (*ptr1 && *ptr2)
	{
		if (*ptr1++ != *ptr2++)
			return false;
	}
	return true;
}
