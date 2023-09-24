#include "Vector2d.h"

bool isEqual(float a, float b, float eps = 1e-6)
{
    return fabs(a - b) < eps;
}

Vector2d::Vector2d(const float x, const float y):
m_x{x},
m_y{y}
{
}

Vector2d::Vector2d(const float x1, const float y1, const float x2, const float y2):
m_x{ x1 + x2},
m_y{ y1 + y2}
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
	return static_cast<float>(std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2)));
}

float &Vector2d::operator[](const size_t i)
{
	return (&m_x)[i];
}

float Vector2d::dotProduct(const Vector2d& other) const
{
	return m_x * other.m_y;
}

Vector2d Vector2d::negate() const
{
	return {-m_x, -m_y};
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
	const float magnitude = operator()();
	const float otherMagnitude = other.operator()();
	const float dot = dotProduct(other);

	
	if(isEqual(dot, 0.0))
		return VectorRelativeState::RightAngle;

	if(dot > 0)
	{
		if (isEqual(dot, magnitude * otherMagnitude))
			return VectorRelativeState::Identical;
		if (dot < magnitude * otherMagnitude)
			return VectorRelativeState::coDirected;
		
	    return VectorRelativeState::AcuteAngle;
	}

	if (isEqual(dot, magnitude * otherMagnitude))
		return VectorRelativeState::OppositeDirected;

    return VectorRelativeState::ObtuseAngle;
}

void Vector2d::scale(float factorX, float factorY)
{
    m_x *= factorX;
    m_y *= factorY;
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

Vector3d crossProduct(Vector3d lhs, Vector3d rhs)
{
	return { lhs.y * rhs.z - lhs.z * rhs.y,
			 lhs.z * rhs.x - lhs.x * rhs.z,
			 lhs.x * rhs.y - lhs.y * rhs.x };
}