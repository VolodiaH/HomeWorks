#pragma once
class Rectangle
{

public:
	constexpr Rectangle() = default;
	Rectangle(const float length, const float height);

	float perimeter() const;
	float square() const;

private:
	float m_length{};
	float m_height{};
};

