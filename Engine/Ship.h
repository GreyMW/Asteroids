#pragma once
#include "Graphics.h"

class Ship
{
	Ship();

public:
	void draw(Graphics& gfx) const;
	void rotate_ship();

private:
	//the ship will be drawn as a triangle pointed sideways
	int ship_center;
	int ship_width;
	int ship_height;
	Graphics& ship_gfx;
};
