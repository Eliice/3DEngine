#pragma once

#include <ostream>

#include "Mat4.h"
#include "Vector4.h"


#ifdef DLL_EXPORT
#define ENGINE_DLL __declspec(dllexport)
#else
#define ENGINE_DLL __declspec(dllimport)
#endif


namespace math
{
	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3();
		Vector3(float);
		ENGINE_DLL Vector3(float, float, float);
		~Vector3() = default;

		Vector3 cross(Vector3 A);
		float dot(Vector3 const&)const;
		float length();
		float distance(Vector3 const&);
		Vector3 conj();
		Vector3 normalize();
		Vector3 rotationToVector3()const;
		Vector4 vector3ToVector4();
		void normalizeNormals(Vector3 const&, Vector3 const&, Vector3 const&);

		Vector3 setAbsolute();

		Vector3 operator*(float)const;
		Vector3& operator*=(float);
		Vector3 operator/(float)const;
		Vector3& operator/=(float);

		Vector3 operator+(Vector3 const&)const;
		Vector3& operator+=(Vector3 const&);
		Vector3 operator-(Vector3 const&)const;
		Vector3& operator-=(Vector3 const&);
		bool operator==(Vector3 const&);
		bool operator!=(Vector3 const&);
		Vector3 operator*(Vector3 const&)const;
		//auto operator=(Vector3 const&)->Vector3&;

		void SetX(float X);
		void SetY(float Y);
		void SetZ(float Z);

		static	Vector3 const null;

		std::string Serialize();
		Vector3* Deserialize(std::string& data);
	};
	auto operator<<(std::ostream&, Vector3 const&)->std::ostream&;
}

