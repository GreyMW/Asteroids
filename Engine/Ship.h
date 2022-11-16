#pragma once
#include "Graphics.h"
#include "Vector2.h"

class Ship
{
public:
	Ship(int center_x, int center_y, int height, int width);
	//the ship will be drawn as a triangle pointed sideways centered on x and y modified by the rotation
	void draw(Graphics& gfx) const;
	void rotate_ship(float degrees);

private:
	
	int x;
	int y;
	int width;
	int height;

};
