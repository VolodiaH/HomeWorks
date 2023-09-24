// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <iostream>

enum class VectorRelativeState
{
    Identical, //
    coDirected,//
    OppositeDirected,//
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

class Vector2d
{

public:

	Vector2d(const float x, const float y);
	Vector2d(const float x1, const float y1, const float x2, const float y2);

	Vector2d &operator=(const Vector2d &);
	Vector2d operator+(const Vector2d &secondVector) const;
	Vector2d operator-(const Vector2d &secondVector) const;

	Vector2d& operator+=(const Vector2d &rightVector);
	Vector2d& operator-=(const Vector2d &rightVector);

	float operator()() const;

	float& operator[](const size_t i);

	friend Vector2d operator+(const Vector2d &leftVector, const Vector2d &rightVector);
	friend Vector2d operator-(const Vector2d &leftVector, const Vector2d &rightVector);

	friend std::ostream &operator<<(std::ostream &os, const Vector2d &v);
	friend std::istream &operator>>(std::istream &is, Vector2d &v);

	float dotProduct(const Vector2d &other) const;
	Vector2d negate() const;

	VectorRelativeState getRelativeState(const Vector2d &other) const;

	void scale(float factorX, float factorY);

private:
	float m_x{0.0};
	float m_y{0.0};

};

struct Vector3d
{
	float x;
	float y;
	float z;
};

Vector3d crossProduct(Vector3d lhs, Vector3d rhs);