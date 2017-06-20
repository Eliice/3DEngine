#include "Vector2.h"

#include <math.h>

namespace math {
	Vector2::Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2::Vector2(float valueX, float valueY)
	{
		x = valueX;
		y = valueY;
	}
	bool Vector2::operator==(Vector2 toCompare)
	{
		if (x == toCompare.x)
			if (y == toCompare.y)
				return true;
		return false;
	}
	bool Vector2::operator!=(Vector2 toCompare)
	{
		if (x != toCompare.x)
			if (y != toCompare.y)
				return true;
		return false;
	}
	Vector2 Vector2::operator+(Vector2 toAdd)
	{
		Vector2 result;
		result.x = x + toAdd.x;
		result.y = y + toAdd.y;
		return Vector2(x + toAdd.x, y + toAdd.y);
	}
	Vector2 Vector2::operator-(Vector2 toRemove)
	{
		Vector2 result;
		result.x = x - toRemove.x;
		result.y = y - toRemove.y;
		return Vector2(x-toRemove.x, y - toRemove.y);
	}
	Vector2 Vector2::operator=(Vector2 newValue)
	{
		return Vector2(newValue.x, newValue.y);
	}
	void Vector2::operator+=(Vector2 toAdd)
	{
		x += toAdd.x;
		y += toAdd.y;
	}
	void Vector2::operator-=(Vector2 toRemove)
	{
		x -= toRemove.x;
		y -= toRemove.y;
	}
	float Vector2::Size()
	{
		return sqrtf(x*x + y*y);
	}
	Vector2 Vector2::Normalise()
	{
		float length = Size();
		return Vector2(x/length, y/length);
	}
	float Vector2::Dot(Vector2 toCalc)
	{
		return x *toCalc.x + y*toCalc.y;
	}
	void Vector2::Scale(float scale)
	{
		x *= scale;
		y *= scale;
	}
}

