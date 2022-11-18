#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "FrameTimer.h"

//#include "Vector2.h"

class Ship
{
public:
	Ship(float center_x, float center_y, int height, int width);
	//the ship will be drawn as a triangle pointed sideways centered on x and y modified by the rotation
	void draw(Graphics& gfx) const;
	Vector2 rotate_ship(float degrees, Vector2& vec) const;
	void update_rotation(const Keyboard& kbd, const FrameTimer& frame_timer);
	void update_velocity(const Keyboard& kbd, const FrameTimer& frame_timer);
	void update_position(const FrameTimer& frame_timer);

private:

	//x and y are stored as float for smooth movement
	//float x;
	//float y;
	Vector2 xy;

	int width;
	int height;

	float rotation;
	float rotation_speed;

	Vector2 velocity;
	const float acceleration = 50;
	const float velocity_cap = 300;

};

