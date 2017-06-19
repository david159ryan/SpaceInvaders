#pragma once
#include <chrono>

class Stopwatch {
public:
	Stopwatch();
	void Start();
	void Stop();
	void Reset();
	void Resume();
	bool IsRunning();
	uint64_t GetTime();

private:
	std::chrono::milliseconds start_time;
	std::chrono::milliseconds stop_time;
	std::chrono::milliseconds GetCurrentTime();
	bool b_running;
};