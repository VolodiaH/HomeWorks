#include "Vector2d.h"
#include <cmath>

Vector2d::Vector2d(const float x, const float y):
m_x{x},
m_y{y}
{
}

Vector2d& Vector2d::operator=(const Vector2d& v)
{
	if (this == &v)
		return *this;

	m_x = v.m_x;
	m_y = v.m_y;

	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) const
{
	Vector2d v(*this);

	v.m_x += secondVector.m_x;
	v.m_y += secondVector.m_y;

	return v;
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const
{
	Vector2d v(*this);

	v.m_x -= secondVector.m_x;
	v.m_y -= secondVector.m_y;

	return v;
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
	Vector2d leftVector1(leftVector);
	return leftVector1 += rightVector;
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
	Vector2d leftVector1(leftVector);
	return leftVector1 -= rightVector;
}

Vector2d& Vector2d::operator+=(const Vector2d& rightVector)
{
	m_x += rightVector.m_x;
	m_y += rightVector.m_y;

	return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& rightVector)
{
	m_x -= rightVector.m_x;
	m_y -= rightVector.m_y;

	return *this;
}

float Vector2d::operator()() const
{
	const float res = static_cast<float>(std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2)));
	return res;
}

float& Vector2d::operator[](const size_t i)
{
	return (&m_x)[i];
}

std::ostream &operator<<(std::ostream &os, const Vector2d &v)
{
	os << '{' << v.m_x << "; " << v.m_y << '}';
	return os;
}

std::istream &operator>>(std::istream &is, Vector2d &v)
{
	is >> v.m_x >> v.m_y;
	return is;
}

