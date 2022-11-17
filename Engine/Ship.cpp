#include "Ship.h"
#include "Vector2.h"
#include "Matrix_2x2.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "FrameTimer.h"



Ship::Ship(float center_x, float center_y, int height_in, int width_in)
{
	x = center_x;
	y = center_y;
	height = height_in;
	width = width_in;
	//stored in degrees
	rotation = 0.0f;
	rotation_speed = 50.0f;
	velocity = Vector2(0.0f, 0.0f);
	
}

void Ship::draw(Graphics& gfx) const
{

	float percentage_x = 1.0f;
	float percentage_y = 1.0f;
	for(int j = height; j > ( -1 * height); j--)
	{
		//percentage of how high we are on the triangle
		percentage_y = static_cast<float>(abs(j)) / static_cast<float>(height);
		

		for(int i = (-1*width); i < width; i++)
		{
			//how far along we are on the triangle
			percentage_x = static_cast<float>(width - i) / static_cast<float>(width * 2);

			//as long as how far along we are is greater or equal to how high we are on the triangle
			//it's part of the triangle
			if(abs(percentage_x) >= abs(percentage_y))
			{

				Vector2 vec(static_cast<float>(i), static_cast<float>(j));

				//Rotates each pixel of the ship individually
				vec = rotate_ship(rotation, vec);

				gfx.PutPixel(vec, 255, 255, 255);
			}
			
		}
	}
}

Vector2 Ship::rotate_ship(const float degrees, Vector2& vec) const
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
	return (rotation_matrix * vec) + Vector2(static_cast<float>(x),static_cast<float>(y));
	

}

void Ship::update_rotation(const Keyboard& kbd, const FrameTimer& frame_timer)
{
	if(kbd.KeyIsPressed(VK_LEFT))
	{
		rotation += frame_timer.time_since_last_frame() * rotation_speed;
	}
	if(kbd.KeyIsPressed(VK_RIGHT))
	{
		rotation -= frame_timer.time_since_last_frame() * rotation_speed;
	}
}

void Ship::update_velocity(const Keyboard& kbd, const FrameTimer& frame_timer)
{
	const float radians = float(rotation * M_PI / 180.0f);

	if(kbd.KeyIsPressed(VK_UP))
	{
		velocity += Vector2(frame_timer.time_since_last_frame() * static_cast<float>(cos(radians)) * acceleration,
			frame_timer.time_since_last_frame() * static_cast<float>(sin(radians)) * acceleration*-1.0f);

		//caps velocity
		//if(velocity > velocity_cap)
		//{
		//	velocity = velocity_cap;
		//}
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		velocity -= Vector2(frame_timer.time_since_last_frame() * static_cast<float>(cos(radians)) * acceleration,
			frame_timer.time_since_last_frame() * static_cast<float>(sin(radians)) * acceleration*-1.0f);

		//negative acceleration not allowed
		//if(velocity < 0.0f)
		//{
		//	velocity = 0.0f;
		//}
	}
}

void Ship::update_position(const FrameTimer& frame_timer)
{
	
	const float delta_x = velocity.x * frame_timer.time_since_last_frame();
	const float delta_y = velocity.y * frame_timer.time_since_last_frame();
	x += delta_x;
	y += delta_y;
}
