#pragma once
#include <memory>

class ITriangle 
{
public:
	virtual void drawTriangle() = 0;
};

class Triangle: public ITriangle
{
protected:
	Triangle(int length);

	int length();

private:
	int m_length;
};

class TriangleFactory 
{
public:
	static TriangleFactory& instance();

	std::unique_ptr<Triangle> makeRight(int length);
	std::unique_ptr<Triangle> makeIsosceles(int length);

private:
	TriangleFactory();

	class RightTriangle: public Triangle
	{
	public:
		RightTriangle(int length);

	private:
		void drawTriangle();

		void drawRightTriangle();
	};

	class IsoscelesTriangle: public Triangle
	{
	public:
		IsoscelesTriangle(int length);

	private:
		void drawTriangle();

		void drawTop();
		void drawBody();
		void drawBottom();

	};
};

