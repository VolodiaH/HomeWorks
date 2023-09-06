#include "Vector2d.h"

Vector2d::Vector2d(const float x, const float y):
m_x1{x},
m_y1{y}
{
}

Vector2d::Vector2d(const float x1, const float y1, const float x2, const float y2):
m_x1{ x1 },
m_y1{ y1 },
m_x2{ x2 },
m_y2{ y2 }
{
}

Vector2d& Vector2d::operator=(const Vector2d& v)
{
	if (this == &v)
		return *this;

	m_x1 = v.m_x1;
	m_y1 = v.m_y1;

	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) const
{
	Vector2d v(*this);

	v.m_x1 += secondVector.m_x1;
	v.m_y1 += secondVector.m_y1;

	return v;
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const
{
	Vector2d v(*this);

	v.m_x1 -= secondVector.m_x1;
	v.m_y1 -= secondVector.m_y1;

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
	m_x1 += rightVector.m_x1;
	m_y1 += rightVector.m_y1;

	return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& rightVector)
{
	m_x1 -= rightVector.m_x1;
	m_y1 -= rightVector.m_y1;

	return *this;
}

float Vector2d::operator()() const
{
	const float res = static_cast<float>(std::sqrt(std::pow(m_x1, 2) + std::pow(m_y1, 2)));
	return res;
}

float& Vector2d::operator[](const size_t i)
{
	return (&m_x1)[i];
}

float Vector2d::dotProduct(const Vector2d& other) const
{
	return m_x1 * other.m_y1 + m_y2 * other.m_x2;
}

Vector2d Vector2d::crossProduct(const Vector2d& other) const
{
	return {m_x1 * other.m_y1, m_y2 * other.m_x2};
}

Vector2d Vector2d::negate() const
{
	return {-m_x1, -m_y1};
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
	const float magnitude = operator()();
	const float otherMagnitude = other.operator()();
	const float dot = dotProduct(other);

	
	if(!static_cast<int>(dot))
		return VectorRelativeState::RightAngle;

	//I sensed an unpleasant disturbance in the force, about those comparing floating types
	if(dot > 0)
	{
		if (std::fabs(dot) == magnitude * otherMagnitude)
			return VectorRelativeState::Identical;
		if (dot < magnitude * otherMagnitude)
			return VectorRelativeState::coDirected;
		
	    return VectorRelativeState::AcuteAngle;
	}

	if (std::fabs(dot) == magnitude * otherMagnitude)
		return VectorRelativeState::OppositeDirected;

    return VectorRelativeState::ObtuseAngle;
}

void Vector2d::scale(float factorX, float factorY)
{
    m_x1 *= factorX;
    m_y1 *= factorY;
}

std::ostream &operator<<(std::ostream &os, const Vector2d &v)
{
	os << '{' << v.m_x1 << "; " << v.m_y1 << '}';
	return os;
}

std::istream &operator>>(std::istream &is, Vector2d &v)
{
	is >> v.m_x1 >> v.m_y1;
	return is;
}

