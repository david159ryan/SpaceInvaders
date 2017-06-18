#include <entity.h>

class Invader : public Entity {
public:

	const int INVADER_MOVE_X = 5;

	static Invader * Invader1(int x, int y);
	static Invader * Invader2(int x, int y);
	static Invader * Invader3(int x, int y);
	void Move(double delta, int dir);
	void Update();
private:
	Invader(int x, int y, int type);
	Invader();
};