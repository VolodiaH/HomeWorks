#pragma once
#include <iostream>

#include "HeaderRecursions.h"

int recursion::factorial(int number)
{
	return (number > 1) ? factorial(number - 1) * number : 1;
}

void recursion::printNaturalNumbersToBig(int count)
{
	if (count - 1) 
		printNaturalNumbersToBig(count - 1);

	std::cout<< count <<" ";
}
void recursion::printNaturalNumbersFromBig(int count)
{
	std::cout << count << " ";
	if (count - 1)
		printNaturalNumbersFromBig(count - 1);
}