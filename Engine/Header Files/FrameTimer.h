#pragma once
#include <chrono>

class FrameTimer {
public:
	FrameTimer();
	void update_delta_time();
	float time_since_last_frame() const;
	
private:
	std::chrono::steady_clock::time_point most_current_time;

	//my understanding is we should always instantiate
	float delta_time{0.0f};

};