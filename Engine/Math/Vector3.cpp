
#include <iostream>
#include "Vector3.h"
#include "Maths.h"
#include <string>

namespace math
{
	Vector3::Vector3()
		: Vector3(0.0f)
	{}

	Vector3::Vector3(float val)
		: x(val), y(val), z(val)
	{
	}

	Vector3::Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	float Vector3::dot(Vector3 const& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	Vector3 Vector3::cross(Vector3 B)
	{
		Vector3 C;

		C.x = this->y * B.z - this->z * B.y;
		C.y = this->z * B.x - this->x * B.z;
		C.z = this->x * B.y - this->y * B.x;

		return C;
	}

	float Vector3::length()
	{
		return sqrtf(x*x + y*y + z*z);
	}

	float Vector3::distance(Vector3 const& B)
	{
		Vector3 vec_length(*this - B);

		return vec_length.length();
	}

	Vector3 Vector3::conj()
	{
		return Vector3(-x,-y,-z);
	}

	Vector3 Vector3::normalize()
	{
		Vector3 Vector;

		float length = this->length();

		if (length != 0)
		{
			Vector.x = this->x / length;
			Vector.y = this->y / length;
			Vector.z = this->z / length;
		}

		return Vector;
	}

	Vector3 Vector3::rotationToVector3() const
	{
		Maths maths;

		double x = maths.rad(this->x);
		double y = maths.rad(this->y);

		Vector3 dir;
		float cosX = cosf(x);

		dir.x = sinf(y) * cosX;
		dir.y = -sinf(x);
		dir.z = cosf(y) * cosX;

		return dir;
	}

	Vector4 Vector3::vector3ToVector4()
	{
		return Vector4(x,y,z,0);
	}

	void Vector3::normalizeNormals(Vector3 const& A, Vector3 const& B, Vector3 const& C)
	{
		Vector3 normal, aux1, aux2;

		aux1 = B - A;
		aux2 = C - B;

		normal = aux2.cross(aux1).normalize();

		this->x = normal.x;
		this->y = normal.y;
		this->z = normal.z;
	}

	Vector3 Vector3::setAbsolute()
	{
		return{ std::abs(x), std::abs(y), std::abs(z) };
	}

	Vector3 Vector3::operator*(float f) const
	{
		return{ x * f, y * f, z * f };
	}

	Vector3& Vector3::operator*=(float f)
	{
		x *= f; y *= f; z *= f;
		return *this;
	}

	Vector3 Vector3::operator/(float f) const
	{
		return{ x / f, y / f, z / f };
	}

	Vector3& Vector3::operator/=(float f)
	{
		x /= f; y /= f; z /= f;
		return *this;
	}

	Vector3 Vector3::operator+(Vector3 const& v) const
	{
		return{ x + v.x, y + v.y, z + v.z };
	}

	Vector3& Vector3::operator+=(Vector3 const& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	Vector3 Vector3::operator-(Vector3 const& v) const
	{
		return{ x - v.x, y - v.y, z - v.z };
	}

	Vector3& Vector3::operator-=(Vector3 const& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	bool Vector3::operator==(Vector3 const &compar)
	{
		if (x == compar.x)
			if (y == compar.y)
				if (z == compar.z)
					return true;
		return false;
	}

	bool Vector3::operator!=(Vector3 const &compar)
	{
		if (x != compar.x)
			if (y != compar.y)
				if (z != compar.z)
					return true;
		return false;
	}

	Vector3 Vector3::operator*(Vector3 const &oper) const
	{
		return Vector3(x * oper.x, y*oper.y, z*oper.z);
	}

	void Vector3::SetX(float X)
	{
		x = X;
	}

	void Vector3::SetY(float Y)
	{
		y = Y;
	}

	void Vector3::SetZ(float Z)
	{
		z = Z;
	}

	std::string Vector3::Serialize()
	{
		return "\n \t\t\t\t\t {\n \t\t\t\t\t\t vector: \n \t\t\t\t\t\t x: " + std::to_string(x) + ",\n \t\t\t\t\t\t y: " + std::to_string(y) + ",\n \t\t\t\t\t\t z: " + std::to_string(z) + ",\n \t\t\t\t\t }, \n";
	}

	Vector3* Vector3::Deserialize(std::string& data)
	{
		Vector3* vec3 = new Vector3();

		std::string str;
		
		data.erase(0, data.find_first_of(":") + 2);
		data.erase(0, data.find_first_of(":") + 2);
		str = data.substr(0, data.find_first_of(","));

		vec3->SetX(std::stof(str));

		data.erase(0, data.find_first_of(":") + 2);
		str = data.substr(0, data.find_first_of(","));

		vec3->SetY(std::stof(str));

		data.erase(0, data.find_first_of(":") + 2);
		str = data.substr(0, data.find_first_of(","));

		vec3->SetZ(std::stof(str));

		return vec3;
	}

	/*auto Vector3::operator=(Vector3 const& result) &
	{
		Vector3 v1;

		v1.x = result.x;
		v1.y = result.y;
		v1.z = result.z;

		return v1;
	}*/

	std::ostream& operator<<(std::ostream& os, Vector3 const& v)
	{
		os << "maths::Vector3 :" << std::endl;
		os << "\t-\tx = " << v.x << std::endl;
		os << "\t-\ty = " << v.y << std::endl;
		os << "\t-\tz = " << v.z << std::endl;

		return os;
	}
}

