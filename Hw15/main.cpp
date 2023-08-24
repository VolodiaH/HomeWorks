#include <iostream>

#include "Rectangle.h"
#include "Vector2d.h"

int main()
{

	{
		{
			Rectangle r1;
			Rectangle r2;
			Rectangle r3;
			std::cout << "Object count: " << Rectangle::CreatedObjects();
		}
		std::cout << "Object count: " << Rectangle::CreatedObjects();
	}

	{
        Vector2d testVec{ 1.2, 5.6 };
        const Vector2d testVec1{ 1.9, 8.6 };

        std::cout << testVec << '\n';
        std::cout << testVec1 << '\n';
        testVec += testVec1 + testVec1;
        std::cout << testVec << '\n';
        std::cout << testVec + testVec1 + testVec << '\n';
        std::cout << testVec - testVec1 << '\n';

        testVec = testVec1;
        std::cout << testVec << '\n';
        std::cout << testVec() << '\n';
        std::cout << testVec[1] << '\n';
        std::cout << testVec[2] << '\n';
	}
}
