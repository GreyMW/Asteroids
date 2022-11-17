#pragma once
#include "Vector2.h"

class Matrix_2x2
{
public:
	Matrix_2x2(Vector2 col1, Vector2 col2);
	Matrix_2x2(float x1, float x2, float y1, float y2);
	Matrix_2x2(float x);
	Vector2 operator*(const Vector2 v2_in) const;
private:
	Vector2 v1;
	Vector2 v2;

};

