#pragma once

#include <iostream>

class Vector2d
{

public:

	Vector2d(const float x, const float y);

	Vector2d &operator=(const Vector2d &);
	Vector2d operator+(const Vector2d &secondVector) const;
	Vector2d operator-(const Vector2d &secondVector) const;

	Vector2d& operator+=(const Vector2d &rightVector);
	Vector2d& operator-=(const Vector2d &rightVector);

	float operator()() const;

	float &operator[](const size_t i);

	friend Vector2d operator+(const Vector2d &leftVector, const Vector2d &rightVector);
	friend Vector2d operator-(const Vector2d &leftVector, const Vector2d &rightVector);

	friend std::ostream &operator<<(std::ostream &os, const Vector2d &v);
	friend std::istream &operator>>(std::istream &is, Vector2d &v);

private:
	float m_x{0.0};
	float m_y{0.0};
};

