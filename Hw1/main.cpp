#include <iostream>
#include "Triangle.h"

std::unique_ptr<Triangle> chooseTriangle(int length)
{
	std::string answer = "";
	std::cout << "A right triangle? (y,n) ";
	std::cin >> answer;
	if (answer[0] == 'y')
		return TriangleFactory::instance().makeRight(length);
	else
		return TriangleFactory::instance().makeIsosceles(length);
}

int main() 
{
	//you asked about it
	std::cout << "I love C++\n";

	constexpr int lowBoundary = 5;
	constexpr int highBoundary = 53;
	constexpr int maxWrongCount = 3;

	int wrongEnterCount = 0;

	while (true)
	{
		std::cout << "\nLength of triangle(" << lowBoundary << "-" << highBoundary << "): ";

		int length = 5;
		std::cin >> length;
		if (lowBoundary <= length && length <= highBoundary)
		{
			std::unique_ptr<Triangle>tr = chooseTriangle(length);
			tr->drawTriangle();

			wrongEnterCount = 0;
		}
		else
		{
			++wrongEnterCount;
			if (wrongEnterCount == maxWrongCount)
			{
				std::cout << "Not today!";
				return -1;
			}
			
			if (!std::cin.good())
			{
				std::cout << "NUMBERS PLEASE!";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				std::cout << "I know.... It is very hard - but try again";
			
			continue;
		}
		
		std::cout << "\nDraw again?(y,n)";
		std::string answer = "";
		std::cin >> answer;

		switch (answer[0])
		{
		case 'y':
			break;
		case 'n':
			std::cout << "Bye!";
			return 0;
		default:
			std::cout << "I will take it for NO";
			return 0;
			break;
		}

	}
	return 0;
}
