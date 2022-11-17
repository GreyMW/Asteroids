#include "Ship.h"
#include "Vector2.h"
#include "Matrix_2x2.h"
#define _USE_MATH_DEFINES
#include <math.h>


Ship::Ship(int center_x, int center_y, int height_in, int width_in)
{
	x = center_x;
	y = center_y;
	height = height_in;
	width = width_in;
	rotation = 0;
}

void Ship::draw(Graphics& gfx) 
{

	float percentage_x = 1.0f;
	float percentage_y = 1.0f;
	for(int j = height; j > ( -1 * height); j--)
	{
		//percentage of how high we are on the triangle
		percentage_y = float(abs(j)) / float(height);
		

		for(int i = (-1*width); i < width; i++)
		{
			//how far along we are on the triangle
			percentage_x = float(width - i) / float(width*2);

			//as long as how far along we are is greater or equal to how high we are on the triangle
			//it's part of the triangle
			if(abs(percentage_x) >= abs(percentage_y))
			{

				Vector2 vec(static_cast<float>(i), static_cast<float>(j));

				vec = rotate_ship(270, vec);

				gfx.PutPixel(vec, 255, 255, 255);
			}
			
		}
	}
}

Vector2 Ship::rotate_ship(const float degrees, Vector2& vec)
{
	//affine transformation for rotation C = M(B-A)+A
	//where C is the final vector
	//B is vec
	//A is [x, y] or the center of our ship
	//M is the rotation matrix:
	//[cos(a) -sin(a)
	// sin(a) cos(a)]

	const float radians = float(degrees * M_PI / 180.0f);

	const Matrix_2x2 rotation_matrix = Matrix_2x2(float(cos(radians)), float(sin(radians)), -1.0f * float(sin(radians)), float(cos(radians)));

	//the vector comes in as B-A
	//M(B-A)+A
	return (rotation_matrix * vec) + Vector2(float(x),float(y));
	

}
