#include "Ship.h"



Ship::Ship(int center_x, int center_y, int height_in, int width_in)
{
	x = center_x;
	y = center_y;
	height = height_in;
	width = width_in;
}

void Ship::draw(Graphics& gfx) const
{
	using std::abs;
	float percentage_x = 1.0f;
	float percentage_y = 1.0f;
	for(int j = height; j > ( -1 * height); j--)
	{
		//percentage of how high we are on the triangle
		percentage_y = float(abs(j)) / float(height);
		

		for(int i = (-1*width); i < width; i++)
		{
			percentage_x = float(width - i) / float(width*2);
			if(abs(percentage_x) >= abs(percentage_y))
			{
				gfx.PutPixel(i + x, j + y, 255, 255, 255);	
			}
			
		}
	}
}
