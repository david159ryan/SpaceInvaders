#include "Animation.h"


Animation::Animation(const SDL_Rect * frame_rects, int num_frames, uint64_t frame_time, bool loop)
{
	this->frame_rects.assign(frame_rects, frame_rects + num_frames);
	frame_iterator = this->frame_rects.begin();
	this->frame_time = frame_time;
	this->num_frames = num_frames;
	timer = Stopwatch();
	b_playing = false;
	b_loop = loop;
	elapsed_time = 0;
}

void Animation::Play()
{
	//looks redundant but may add more here in future
	if (b_playing) {
		return;
	}

	b_playing = true;
	timer.Start();
}

void Animation::Reset() {
	frame_iterator = frame_rects.begin();
	elapsed_time = 0;
}

void Animation::Stop() {
	//looks redundant but may add more here in future
	if (!b_playing) {
		return;
	}

	b_playing = false;
	timer.Stop();
	Reset();
}

//	Logic to check whether next frame should be displayed.
//	For animations where frame_time is set to 0, always load
//	next frame
void Animation::Update() {
	if (num_frames == 1) {
		return;
	}

	if (frame_time == 0) {
		NextFrame();
		return;
	}

	//	allows animation to catch up in case of fps drops
	uint64_t current_time = timer.GetTime();

	//std::cout << "current frame time: " << frame_time << std::endl;

	//TODO change this to while and fix timer.Set(time)
	if (current_time > frame_time) {
		NextFrame();
		std::cout << "skipping anim frames" << std::endl;
		current_time -= frame_time;
		timer.Reset();
		timer.Start();
	}
}

// Moves iterator to next frame. Wraps to beginning when it
// reaches the end.
void Animation::NextFrame() {
	//	iterator.end() represents theoretical index after last element.
	//	Therefore we can safely increment iterator and check for end afterwards
	//	without risking skipping the last element.
	frame_iterator++;

	// return to start frame if animation is looping.
	// stop animation otherwise
	if (frame_iterator == frame_rects.end()) {
		if (b_loop) {
			frame_iterator = frame_rects.begin();
		}
		else {
			Stop();
		}
	}
}


SDL_Rect Animation::CurrentFrame() {
	return *frame_iterator;
}




