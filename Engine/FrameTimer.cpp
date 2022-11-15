#include "FrameTimer.h"
#include <chrono>

FrameTimer::FrameTimer(){
	most_current_time = std::chrono::steady_clock::now();
	update_delta_time();
	//instantiating default value in header instead of here.
	//Is this proper practice?
	//delta_time = 1.0f;
}

//calculates and updates delta time in seconds
void FrameTimer::update_delta_time(){
	const auto old_time = most_current_time;
	most_current_time = std::chrono::steady_clock::now();
	const std::chrono::duration<float> change_in_time = most_current_time - old_time;
	delta_time = change_in_time.count();
}

float FrameTimer::time_since_last_frame() const {
	return delta_time;
}
