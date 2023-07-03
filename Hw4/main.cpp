#include <iostream>

enum class Month :char
{
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec
};

const std::string months[] = { "January" , "February", "March", 
								"April", "May", "June", "July", 
								"August", "September", "October",
								"November", "December" };

int main()
{

	{
		std::cout << "\n----------------------------------1---------------------------------------\n";

		std::cout << "Enter 3 numbers: ";

		int first{ 0 }, second{ 0 }, third{ 0 };
		std::cin >> first >> second >> third;

		int max = first;

		if (max < second)
			max = second;

		if (max < third)
			max = third;

		std::cout << "Max is: " << max << '\n';
	}

	{
		std::cout << "\n----------------------------------2---------------------------------------\n";

		std::cout << "Enter 2 numbers: ";

		int first{ 0 }, second{ 0 };
		std::cin >> first >> second;

		const int min{ (first > second) ? second : first };

		std::cout << "Min is: " << min << '\n';
	}

	{
		std::cout << "\n----------------------------------3---------------------------------------\n";

		std::cout << "Enter number: ";

		int first{ 0 };
		std::cin >> first;

		if (first % 5 == 0 && first % 11 == 0)
			std::cout << "Yes.... It divides" << '\n';
		else
			std::cout << "Wrong number!" << '\n';
	}

	{
		std::cout << "\n----------------------------------4---------------------------------------\n";

		std::cout << "Enter 3 numbers: ";

		unsigned first{ 0 }, second{ 0 }, third{ 0 };
		std::cin >> first >> second >> third;

		const unsigned sum{ first + second + third };
		constexpr unsigned correctSumOfAngles{ 180 };

		if (first && second && third &&
			sum == correctSumOfAngles)
			std::cout << "Correct\n";
		else
			std::cout << "Strange triangle\n";
	}

	{
		std::cout << "\n----------------------------------5---------------------------------------\n";

		std::cout << "Enter number(1-12): ";

		int number{ 0 };
		std::cin >> number;

		std::cout << (1 > number || number > 12) ? 
			"Try again\n" : months[number - 1];
	}

	{
		std::cout << "\n----------------------------------6---------------------------------------\n";

		std::cout << "Enter number(1-12): ";

		int number{ 0 };
		std::cin >> number;

		Month month = static_cast<Month>(number);
		if (Month::Jan <= month && month <= Month::Feb || Month::Dec == month)
			std::cout << "Winter\n";
		else if (Month::Mar <= month && month <= Month::May)
			std::cout << "Spring\n";
		else if (Month::Jun <= month && month <= Month::Aug)
			std::cout << "Summer\n";
		else if (Month::Sep <= month && month <= Month::Nov)
			std::cout << "Fall\n";
		else
			std::cout << "Do you live on Earth?\n";
	}

	return 0;
}
