#include <iostream>
#include <format>

void task1();
void task2();
void task3();
void task4();
void task5();

int main() 
{
	task1();
	task2();
	task3();
	task4();
	task5();
}

void task1() 
{
	std::cout << "Enter init value, step, end value:";

	int init{ 0 }, delta{ 0 }, end{ 0 };
	std::cin >> init >> delta >> end;

	while (init < end)
	{
		init += delta;
		std::cout << init << " ";
	}
}

void task2() 
{
	std::cout << "Enter init fib number: ";
	
	int number{ 0 };
	std::cin >> number;

	int firstNumber{ 0 }, secondNumber{ 1 };
	for (std::size_t i = 1; i <= number; ++i)
	{
		std::cout << firstNumber << " ";

		int nextNumber = firstNumber + secondNumber;
		firstNumber = secondNumber;
		secondNumber = nextNumber;
	}
}

long long factorial(int number)
{
	if (number < 1)
		return number;

	long long res{ 1 };

	for (std::size_t i = number; i > 0; --i)
		res *= i;

	return res;
}

void task3() 
{
	std::cout << "Enter factorial number: ";
	
	int number{ 0 };
	std::cin >> number;

	std::cout << std::format("Your number: {}", factorial(number));
}

std::string binaryString(std::size_t count)
{
	std::string res("");

	for (std::size_t i = 0; i < count; ++i)
		res.insert(res.begin(), (i & 1) ? '0' : '1');

	return res;
}

void task4() 
{
	std::cout << "Enter triangle length: ";

	int length{ 0 };
	std::cin >> length;

	for (std::size_t i = 0; i < length; ++i)
		std::cout << std::string(i+1, '*') << '\n';

	std::cout << "\n";

	for (std::size_t i = length; i > 0 ; --i)
		std::cout << std::string(i , '*') << '\n';

	std::cout << "\n";

	for (std::size_t i = 0; i < length; ++i)
		std::cout << std::string(i, ' ') + std::string(length, '*') << '\n';

	std::cout << "\n";

	for (std::size_t i = 1; i <= length; ++i)
		std::cout << binaryString(i) << '\n';

}

void task5() 
{
	std::cout << "Enter character: ";
	char symbol{ 0 };
	std::cin >> symbol; 

	int sum{ 0 };

	while (symbol != '.')
	{
		if (std::isalpha(symbol) && std::islower(symbol))
			std::cout << std::format("Your symbol: {}\n", static_cast<char>(std::toupper(symbol)));
		else if (std::isdigit(symbol))
			sum += symbol - '0', std::cout << std::format("Sum: {}\n", sum);
		else
			std::cout << "I do not support it!!! \n";

		std::cout << "Enter character: ";
		std::cin >> symbol;
	}
}
