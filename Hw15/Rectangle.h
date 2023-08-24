#pragma once
#include "ObjectCounter.h"

class Rectangle : private ObjectCounter<Rectangle>
{
public:
	Rectangle() = default;
	Rectangle(const float length, const float height);

	float perimeter() const;
	float square() const;

	using ObjectCounter::CreatedObjects;

private:
	float m_length{};
	float m_height{};
};

