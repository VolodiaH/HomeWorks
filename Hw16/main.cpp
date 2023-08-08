#include <vld.h>
#include <iostream>
#include "DynamicIntArray.h"

int main ()
{
	DynamicIntArray intArray(0);
	for (size_t i{}; i < intArray.getSize(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout<<'\n';

	intArray.push_back(56);
	intArray.push_back(56);
	intArray.push_back(56);
	intArray.push_back(56);
	DynamicIntArray intArray2;
	intArray2 = intArray;
	for(size_t i{}; i < intArray2.getSize(); ++i)
	{
		std::cout<< intArray2[i] << " ";
	}
}