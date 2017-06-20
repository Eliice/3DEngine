#include "Maths.h"
#include <cmath>

namespace math
{
	Maths::Maths()
	{
	}


	Maths::~Maths()
	{
	}

	float Maths::rad(float angle)
	{
		return (angle * M_PI / 180.f);
	}

	Vector3 Maths::rad(Vector3 const vec)
	{
		Vector3 result;
		result.x = rad(vec.x);
		result.y = rad(vec.y);
		result.z = rad(vec.z);

		return result;
	}
}

