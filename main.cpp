//#include <iostream>
//#include <algorithm>
////#include <thread>
//#include <mutex>

#ifdef DEF1
std::mutex m;
std::atomic<unsigned long> count;
unsigned long count;
void func()
{
	for (unsigned long i = 0; i < 1'000'000; i++)
	{
		std::scoped_lock lock(m);
		++count;
	}
}



int main(int argc, char* argv[])
{
	std::string s1(argv[1]);
	std::string signature(argv[2]);

	std::string combined(argv[1]);
	int pos = combined.find(".img");
	if (pos == std::string::npos)
	{
		std::cout << "NO IMAGE ";
		return 1;
	}
	combined.insert(pos, "_sign");
	std::cout << "Combined: " << combined << " " << argv[2];
	return 1;

	//ls *$1_$2.img
	/*std::thread t1(func);
	std::thread t2(func);
	t1.join();
	t2.join();
	std::cout << "Count:" << count;*/

	std::ostream_iterator<std::string> oi{ std::cout };

	*oi = "Hello";
	++oi;
	*oi = " World!\n";


	return 0;

}
#endif // 0

#include <iostream>
#include <memory>
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
