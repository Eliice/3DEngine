#pragma once
#include "Vector3.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace math
{
	class Maths
	{
	public:
		Maths();
		~Maths();

		static float rad(float angle);
		static Vector3 rad(Vector3 const vec);
	};


}
