#pragma once

#include <SDL.h>
#include <vector>
#include <iostream>
#include "stopwatch.h"

class Animation
{
public:
	Animation();
	Animation(const SDL_Rect * frames_rects, int num_frames, uint64_t frame_time, bool loop);
	//~Animation();
	void Play();
	void Stop();
	void Reset();
	void Update();
	SDL_Rect CurrentFrame();


private:
	int num_frames;
	uint64_t frame_time;
	std::vector<SDL_Rect> frame_rects;
	std::vector<SDL_Rect>::iterator frame_iterator;
	void NextFrame();
	bool b_playing;
	bool b_loop;
	long elapsed_time;
	Stopwatch timer;
};