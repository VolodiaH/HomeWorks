#include <vld.h>
#include <iostream>
#include "DynamicIntArray.h"

int main ()
{
	DynamicIntArray intArray(10);
	for (size_t i{}; i < 100; ++i)
	{
		intArray.push_back(i);
	}
	//intArray.setSize(15);
	intArray.push_back(45);
	//intArray.clear();
	intArray.push_back(45);
	intArray.push_back(45);
	intArray[0] = 56;
	intArray.at(1) = 34;
	intArray.push_back(36);
	for(size_t i{}; i < intArray.getSize(); ++i)
		std::cout<< intArray[i] << " ";
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