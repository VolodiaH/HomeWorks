enum Month :char
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

const std::string months[] = { "January" , "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

#include <iostream>

int main() 
{

	{
		std::cout << "\n----------------------------------1---------------------------------------\n";

		std::cout << "Enter 3 numbers: ";

		int first, second, third;
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

		int first, second;
		std::cin >> first >> second;

		const int min = (first > second) ? second : first;

		std::cout << "Min is: " << min << '\n';
	}

	{
		std::cout << "\n----------------------------------3---------------------------------------\n";

		std::cout << "Enter number: ";

		int first;
		std::cin >> first;

		if (first % 5 == 0 && first % 11 == 0)
			std::cout << "Yes.... It divides" << '\n';
		else
			std::cout << "Wrong number!" << '\n';
	}

	{
		std::cout << "\n----------------------------------4---------------------------------------\n";

		std::cout << "Enter 3 numbers: ";

		int first, second, third;
		std::cin >> first >> second >> third;

		const int sum{ first+second+third };
        constexpr int correctSumOfAngles{ 180 };
        if(sum == correctSumOfAngles)
            std::cout << "Correct\n";
        else
            std::cout << "Strange triangle\n";
	}

	{
		std::cout << "\n----------------------------------5---------------------------------------\n";

		std::cout << "Enter number(1-12): ";

		int number;
		std::cin >> number;

		const Month month = static_cast<Month>(number);

		switch (month)
		{
		case Month::Jan:	
		case Month::Feb:	
		case Month::Mar:	
		case Month::Apr:	
		case Month::May:	
		case Month::Jun:	
		case Month::Jul:	
		case Month::Aug:	
		case Month::Sep:	
		case Month::Oct:	
		case Month::Nov:	
		case Month::Dec:	
            std::cout << months[month - 1];
        	break;

		default:	std::cout << "Try again\n";	break;
		}
	}

	{
		std::cout << "\n----------------------------------6---------------------------------------\n";

		std::cout << "Enter number(1-12): ";

		int month;
		std::cin >> month;

		if (Month::Jan <= month && month <= Month::Feb || Month::Dec == month)
			std::cout << "Winter\n";
		else if (Month::Mar <= month && month <= Month::May)
			std::cout << "Spring\n";
		else if (Month::Jun <= month && month <= Month::Aug)
			std::cout << "Summer\n";
		else if(Month::Sep <= month && month <= Month::Nov)
			std::cout << "Fall\n";
		else 
			std::cout << "Do you live on Earth?\n";
	}

	return 0;
}