#pragma once

#include <iostream>
#include <format>

#include "HeaderLoops.h"
void task1(int count)
{
	int negatives{};
	int positives{};
	int zeros{};

	for (; count; --count)
	{
		int numb{};
		std::cin >> numb;

		if (numb < 0)
			++negatives;
		else if (numb > 0)
			++positives;
		else
			++zeros;
	}
	std::cout << std::format("Positive: {}, negative: {}, zeroes: {}", positives, negatives, zeros);
}

void loops::factorial(int number)
{
	long long res{ 1 };

	for (int i{ number }; i > 0; --i) 
		res *= i;

	std::cout << res;
}

void loops::printNaturalNumbersToBig(int count)
{
	for (int i{1}; i <= count; ++i)
		std::cout << i << " ";
}
void loops::printNaturalNumbersFromBig(int count)
{
	for (int i{ count }; i > 0; --i)
		std::cout << i << " ";
}