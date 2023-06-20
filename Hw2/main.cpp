#include <iostream>
#include <iomanip>

std::string weekDays[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

enum class WeekDays :char 
{
Mon, Tue, Wed, Thu, Fri, Sat, Sun
};

auto main(int argc, char* argv[]) -> int {

	{
		std::cout << "\n----------------------------------1---------------------------------------\n";

		int number1{ 0 }, number2{ 0 };

		std::cout << "Enter integer 1: ";
		std::cin >> number1;
		std::cout << "Enter integer 2: ";
		std::cin >> number2;

		std::swap(number1, number2);

		std::cout << "Integer 1: " << number1 << '\n';
		std::cout << "Integer 2: " << number2 << '\n';
	}
	
	{
		std::cout << "\n----------------------------------2---------------------------------------\n";

		double doubleNumber{ 356.212354366 };
		std::cout << std::setw(20) << std::right << std::setfill('$') << static_cast<int>(doubleNumber) << '\n';
		std::cout << std::setw(20) << std::right << std::setfill('$') << doubleNumber << '\n';

		std::cout << "\n----------------------------------3---------------------------------------\n";

        std::cout << std::setfill(' ');
		std::cout << std::setprecision(2) << "Normal: " << std::fixed << doubleNumber <<std::setw(20) <<std::right << " e-notation:" << std::scientific << doubleNumber << '\n';
		std::cout << std::setprecision(5) << "Normal: "  << std::fixed << doubleNumber << std::setw(17) << std::right << " e-notation:" << std::scientific << doubleNumber << '\n';
		std::cout << std::setprecision(10) << "Normal: " << std::fixed << doubleNumber << std::setw(12) << std::right << " e-notation:" << std::scientific << doubleNumber << '\n';
	}

	{
		std::cout << "\n----------------------------------4---------------------------------------\n";

		constexpr int weekDaysCount{ 7 };

		for (std::size_t i{ 0 }; i < weekDaysCount; ++i)
		{
			WeekDays day{ static_cast<WeekDays>(i) };
			std::cout << weekDays[i] << " " << static_cast<int>(day) + 1 << '\n';
		}
	}
	{
		std::cout << "\n----------------------------------5---------------------------------------\n";

		std::cout << "Please enter the number: ";

		int number{ 0 };
		std::cin >> number;

		std::cout << "Boolean: " << std::boolalpha << static_cast<bool>(number) <<'\n';
	}
	
}
