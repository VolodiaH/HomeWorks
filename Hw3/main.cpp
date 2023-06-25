#include <iostream>
// next 2 headers with C++20
#include <format>
#include <numbers>

auto main(int argc, char* argv[]) -> int 
{
	{
		std::cout << "\n----------------------------------1---------------------------------------\n";

		unsigned long time;

		std::cout << "Enter time: ";
		std::cin >> time;

		constexpr int secondsInMinute{ 60 };
		constexpr int secondsInHour{ secondsInMinute * 60 };

		unsigned int hours{ 0 }, minutes{ 0 };

		if (time >= secondsInHour) 
		{
			hours = time / secondsInHour;
			time -= hours * secondsInHour;
		}
		if (time >= secondsInMinute) 
		{
			minutes = time / secondsInMinute;
			time -= minutes * secondsInMinute;
		}
		
		std::cout << std::format("Hours: {}, Minutes: {}, Seconds: {}", hours, minutes, time);
	}

	{
		std::cout << "\n----------------------------------2---------------------------------------\n";

		constexpr int numbersCount{ 3 };

		std::cout << std::format("Enter {} numbers: ", numbersCount);

		int first{ 0 }, second{ 0 }, third{ 0 };
		std::cin >> first >> second >> third;

		const int sum{ first + second + third };
		const int product{ first * second * third };
		const int averageArithmetic{ sum / numbersCount };

		std::cout << std::format("Sum: {} \n", sum);
		std::cout << std::format("Product: {}\n", product);
		std::cout << std::format("Average Arithmetic: {}\n", averageArithmetic);

		std::cout << std::format(" first({}) == second({}) is {}\n", first, second, first == second);
		std::cout << std::format(" second({}) == third({}) is {}\n", first, second, second == third);
		
		std::cout << std::format(" first({}) < second({}) is {}\n", first, second, first < second);
		std::cout << std::format(" second({}) < third({}) is {}\n", first, second, second < third);
		
		std::cout << std::format(" first({}) <= second({}) is {}\n", first, second, first <= second);
		std::cout << std::format(" second({}) <= third({}) is {}\n", first, second, second <= third);
		
		std::cout << std::format(" first({}) > second({}) is {}\n", first, second, first > second);
		std::cout << std::format(" second({}) > third({}) is {}\n", first, second, second > third);
		
		std::cout << std::format(" first({}) >= second({}) is {}\n", first, second, first >= second);
		std::cout << std::format(" second({}) >= third({}) is {}\n", first, second, second >= third);
	}

	{
		std::cout << "\n----------------------------------3---------------------------------------\n";
		
		int first{ 0 }, second{ 0 };
		std::cout << "Enter 2 numbers: ";
		std::cin >> first >> second;

		const bool lessThan{ first < second }, equal{ first == second }, moreThan{ first > second }, lessOrEqual{ first <= second };

		std::cout << lessThan << "/" << equal << "/" << moreThan << "/" << lessOrEqual << '\n';
		std::cout << std::format( "{}/{}/{}/{}\n", lessThan, equal, moreThan, lessOrEqual);

		// appears that std::format already deduce bool as true\false not 1\0... I hope it is not UB
		// next line is for raw string std::cout... if you need it
		//std::cout << std::boolalpha;
		std::cout << std::format("Less Than of the first({}) and the second({}) is {}\n", first, second, lessThan);
		std::cout << std::format("Equal of the first({}) and the second({}) is {}\n", first, second, equal);
		std::cout << std::format("More Than of the first({}) and the second({}) is {}\n", first, second, moreThan);
		std::cout << std::format("Less Or Equal of the first({}) and the second({}) is {}\n", first, second, lessOrEqual);
	}

	{
		std::cout << "\n----------------------------------4---------------------------------------\n";

		int width{ 0 }, height{ 0 };

		std::cout << "Enter width:";
		std::cin >> width;
		std::cout << "Enter height:";
		std::cin >> height;

		const int square{ width * height };
		const int perimeter{ (width + height) * 2 };

		std::cout << std::format("Square is {}, Perimeter is {}", square, perimeter);
	}

	{
		std::cout << "\n----------------------------------5---------------------------------------\n";
		
		std::cout << "Enter radius: ";

		double radius{ 0 };
		std::cin >> radius;

		const long double square{ std::numbers::pi_v<double> *(radius * radius) };
		const long double length{ 2 * std::numbers::pi_v<double> *radius };

		std::cout << std::format("Square is {}, Length is {}", square, length);
	}
}
