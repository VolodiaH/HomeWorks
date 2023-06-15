#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int length):
	m_length(length) {}

int Triangle::length() 
{
	return m_length;
}

TriangleFactory::TriangleFactory() {}

TriangleFactory& TriangleFactory::instance() 
{
	static TriangleFactory factory;
	return factory;
}

std::unique_ptr<Triangle> TriangleFactory::makeIsosceles(int length)
{
	return std::make_unique<TriangleFactory::IsoscelesTriangle>(length);
}

std::unique_ptr<Triangle> TriangleFactory::makeRight(int length)
{
	return std::make_unique<TriangleFactory::RightTriangle>(length);
}

TriangleFactory::RightTriangle::RightTriangle(int length) : Triangle(length)
{}

TriangleFactory::IsoscelesTriangle::IsoscelesTriangle(int length) :Triangle(length)
{}

void TriangleFactory::IsoscelesTriangle::drawTriangle()
{
	drawBottom();
	drawBody();
	drawTop();
}

void TriangleFactory::IsoscelesTriangle::drawTop()
{
	int top = length() / 2 - 1;
	if (length() & 1)
		++top;

	for (int i = 0; i < length(); ++i)
		if (i == top)
			if (length() & 1)
				std::cout << "**";
			else
				std::cout << "***";
		else
			std::cout << " ";
}

void TriangleFactory::IsoscelesTriangle::drawBody()
{
	int height = length() / 2 - 2;

	if (length() & 1)
		++height;
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < length(); ++i)
			if (i == j + 1 || i == length() - (j + 1))
				std::cout << "*";
			else
				std::cout << " ";
		std::cout << "\n";
	}
}

void TriangleFactory::IsoscelesTriangle::drawBottom()
{
	for (int i = 0; i < length() + 1; ++i)
		std::cout << "*";

	std::cout << "\n";
}


void TriangleFactory::RightTriangle::drawTriangle()
{
	drawRightTriangle();
}

void TriangleFactory::RightTriangle::drawRightTriangle()
{
	for (int i = 0; i < length(); ++i)
	{
		for (int j = 0; j < length(); ++j)
		{
			if (j == 0 || j == i)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << '\n';
	}

	for(int i = 0; i < length() + 1; ++i)
		std::cout << '*';
}
