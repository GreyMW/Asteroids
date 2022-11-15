#include "Vector2.h"

Vector2::Vector2(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	//returns a pointer to itself? Haven't learned pointers yet, a bit beyond me for the moment
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	//returns a pointer to itself? Haven't learned pointers yet, a bit beyond me for the moment
	return *this;
}

Vector2 Vector2::operator*(const float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2& Vector2::operator*=(const float scalar) 
{
	x = x * scalar;
	y = y * scalar;
	return *this;
}
