#pragma once
class Vector2
{
public:
	float x;
	float y;
	Vector2(float x_in, float y_in);

	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2& operator += (const Vector2& rhs);
	Vector2& operator -= (const Vector2& rhs);
	Vector2 operator*(const float scalar) const;
	Vector2& operator*=(const float scalar);


};

