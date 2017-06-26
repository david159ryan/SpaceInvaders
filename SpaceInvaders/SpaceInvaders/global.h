#pragma once
extern int SCALE, WIDTH, HEIGHT;

struct Vector2 {
	float x;
	float y;
	bool operator==(const Vector2  &rhs) const;
};

inline
bool Vector2::operator==(const Vector2 &rhs) const
{
	return (x == rhs.x) && (y == rhs.y);
}

const static Vector2 LEFT	= { -1, 0  };
const static Vector2 RIGHT	= {  1, 0  };
const static Vector2 UP		= {  0, -1  };
const static Vector2 DOWN	= {  0, 1 };
const static Vector2 STILL	= {  0, 0  };