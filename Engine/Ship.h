#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "FrameTimer.h"
//#include "Vector2.h"

class Ship
{
public:
	Ship(int center_x, int center_y, int height, int width);
	//the ship will be drawn as a triangle pointed sideways centered on x and y modified by the rotation
	void draw(Graphics& gfx);
	Vector2 rotate_ship(float degrees, Vector2& vec);
	void update_rotation(const Keyboard& kbd, const FrameTimer& frame_timer);
private:
	
	int x;
	int y;
	int width;
	int height;
	float rotation;
	float rotation_speed;

};

