#include "Vector4.h"

#include <math.h>

math::Vector4::Vector4()
	: Vector4(0.0f)
{}

math::Vector4::Vector4(float val)
	: x(val), y(val), z(val), w(val)
{}

math::Vector4::Vector4(float X, float Y, float Z, float W)
	:x(X), y(Y), z(Z), w(W)
{}

bool math::Vector4::operator==(Vector4 const&compar)
{
	if (x == compar.x)
		if (y == compar.y)
			if (z == compar.z)
				if (w == compar.w)
					return true;
	return false;
}

bool math::Vector4::operator!=(Vector4 const &compar)
{
	if (x != compar.x)
		if (y != compar.y)
			if (z != compar.z)
				if (w != compar.w)
					return true;
	return false;
}

math::Vector4 math::Vector4::operator+(Vector4 const &v)
{
	return{ x + v.x, y + v.y, z + v.z, w + v.w };
}

math::Vector4 math::Vector4::operator-(Vector4 const &v)
{
	return{ x - v.x, y - v.y, z - v.z, w - v.w };
}

math::Vector4 math::Vector4::operator=(Vector4 const &newValue)
{
	Vector4 resulte;
	x = newValue.x;
	y = newValue.y;
	z = newValue.z;
	w = newValue.w;

	return resulte;
}

void math::Vector4::operator+=(Vector4 const &toAdd)
{
	x += toAdd.x;
	y += toAdd.y;
	z += toAdd.z;
	w += toAdd.w;
}

void math::Vector4::operator-=(Vector4 const &toRemove)
{
	x -= toRemove.x;
	y -= toRemove.y;
	z -= toRemove.z;
	w -= toRemove.w;
}

float math::Vector4::Size()
{
	return sqrtf(x*x + y*y + z*z + w*w);
}

math::Vector4 math::Vector4::Normalise()
{
	float length = Size();

	Vector4 result;
	result.x = x / length;
	result.y = y / length;
	result.z = z / length;
	result.w = w / length;

	return result;
}

float math::Vector4::Dot(Vector4 toCalc)
{
	float result = x *toCalc.x + y *toCalc.y + z *toCalc.z + w *toCalc.w;
	return result;
}

void math::Vector4::Scale(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	w *= scale;
}