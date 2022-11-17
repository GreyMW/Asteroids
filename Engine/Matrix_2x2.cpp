#include "Matrix_2x2.h"
#include "Vector2.h"

Matrix_2x2::Matrix_2x2(Vector2 col1, Vector2 col2)
{
	v1 = col1;
	v2 = col2;
}

Matrix_2x2::Matrix_2x2(float x1, float x2, float y1, float y2)
{
	v1 = Vector2(x1, y1);
	v2 = Vector2(x2, y2);
}

//for the matrix where all the numbers are the same
Matrix_2x2::Matrix_2x2(float x)
{
	v1 = Vector2(x, x);
	v2 = Vector2(x, x);
}

Vector2 Matrix_2x2::operator*(const Vector2 v2_in) const
{
	return Vector2(v1.x * v2_in.x + v2.x * v2_in.y, v1.y * v2_in.x + v2.y * v2_in.y);
}
