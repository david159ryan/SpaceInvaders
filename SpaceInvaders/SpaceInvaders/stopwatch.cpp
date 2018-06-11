#include "stopwatch.h"

Stopwatch::Stopwatch()
{
	Reset();
	b_running = false;
}

Stopwatch::Stopwatch(uint64_t time) : Stopwatch()
{
	Set(time);
}

void Stopwatch::Start()
{
	using namespace std::chrono;
	start_time = (start_time == milliseconds::zero()) ? GetCurrentTime() : start_time;
	b_running = true;
}

void Stopwatch::Stop()
{
	using namespace std::chrono;
	b_running = false;
	stop_time = GetCurrentTime();
}

void Stopwatch::Reset()
{
	using namespace std::chrono;
	b_running = false;
	start_time = milliseconds::zero();
	stop_time = milliseconds::zero();
}

void Stopwatch::Resume()
{
	using namespace std::chrono;
	if (b_running || start_time == milliseconds::zero()) {
		return;
	}
	uint64_t time = GetCurrentTime().count() - GetTime();
	Set(time);
	b_running = true;
}

//TODO doesn't appear to be working as expected. FIX DAVE!!!
void Stopwatch::Set(uint64_t time)
{
	using namespace std::chrono;
	milliseconds ms = milliseconds(time);
	start_time = duration_cast<milliseconds>(ms);
}

bool Stopwatch::IsRunning()
{
	return b_running;
}

uint64_t Stopwatch::GetTime()
{
	uint64_t time = (b_running) ? GetCurrentTime().count() : stop_time.count();
	return (time - start_time.count());
}

std::chrono::milliseconds Stopwatch::GetCurrentTime()
{
	using namespace std::chrono;
	return  duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()
	);
}