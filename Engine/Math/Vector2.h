#pragma once

namespace math
{
	struct Vector2
	{
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);

		bool operator==(Vector2);
		bool operator!=(Vector2);
		Vector2 operator+(Vector2);
		Vector2 operator-(Vector2);
		Vector2 operator=(Vector2);
		void operator+=(Vector2);
		void operator-=(Vector2);

		float Size();
		Vector2 Normalise();
		float Dot(Vector2);
		void Scale(float);

	}; 


}
