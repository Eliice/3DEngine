#pragma once

namespace math
{
	struct Vector4
	{
		Vector4();
		Vector4(float);
		Vector4(float, float, float, float);

		bool operator==(Vector4 const&);
		bool operator!=(Vector4 const&);
		Vector4 operator+(Vector4 const&);
		Vector4 operator-(Vector4 const&);
		Vector4 operator=(Vector4 const&);
		void operator+=(Vector4 const&);
		void operator-=(Vector4 const&);

		float Size();
		Vector4 Normalise();
		float Dot(Vector4);
		void Scale(float);

		float x, y, z, w;
	};
}

