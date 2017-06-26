#pragma once
#include <chrono>

class Stopwatch {
public:
	Stopwatch();
	Stopwatch(uint64_t start_time);
	void Start();
	void Stop();
	void Reset();
	void Resume();
	void Set(uint64_t start_time);
	bool IsRunning();
	uint64_t GetTime();

private:
	std::chrono::milliseconds start_time;
	std::chrono::milliseconds stop_time;
	std::chrono::milliseconds GetCurrentTime();
	bool b_running;
};