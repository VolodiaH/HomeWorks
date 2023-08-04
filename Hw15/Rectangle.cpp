#include "Rectangle.h"

constexpr float PerimeterCoefficient = 2.0f;

size_t ObjectCounter<Rectangle>::m_createdObjects = 0;

Rectangle::Rectangle(const float length, const float height) :
m_length(length),
m_height(height)
{
}

float Rectangle::perimeter() const
{
    return PerimeterCoefficient * (m_height + m_length);
}

float Rectangle::square() const
{
    return m_height * m_length;
}

