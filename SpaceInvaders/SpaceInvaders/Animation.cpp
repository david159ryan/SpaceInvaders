#include "Animation.h"

Animation::Animation()
{

}

Animation::Animation(const SDL_Rect * frames, int num_frames, uint64_t frame_time, bool loop)
{
	for (int i = 0; i < num_frames; i++)
	{
		this->frame_rects.push_back(&frames[i]);
	}
	current_frame = 0;
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
	current_frame = 0;
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
	
	//std::cout << "current time: " << current_time << std::endl << "frame time: " << frame_time << std::endl;

	//TODO this logic is broken... just using for debugging
	int skipped_frames = -1;

	//TODO change this to while and fix timer.Set(time)
	while (current_time > frame_time) {
		NextFrame();
		skipped_frames++;
		current_time -= frame_time;
		timer.Reset();
		timer.Start();
	}
	if (skipped_frames > 0) {
		std::cout << "skipped anim frames: " << skipped_frames << std::endl;
	}
}

// Moves iterator to next frame. Wraps to beginning when it
// reaches the end.
void Animation::NextFrame() {

	current_frame++;

	// return to start frame if animation is looping.
	// stop animation otherwise
	if (current_frame == num_frames) {
		if (b_loop) {
			Reset();
		}
		else {
			Stop();
		}
	}
}


const SDL_Rect * Animation::CurrentFrame() {
	return frame_rects[current_frame];
}

Animation::~Animation()
{
	
}
