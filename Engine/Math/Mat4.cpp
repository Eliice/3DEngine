#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "Mat4.h"
#include "Vector3.h"

namespace math
{
	double rad(float angle)
	{
		return angle * M_PI / 180.f;;
	}

	const Mat4 Mat4::Identity = Mat4(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	);

	Mat4::Mat4()
	{
		*this = Mat4::Identity;
	}

	Mat4::~Mat4()
	{
	}

	Mat4::Mat4(float const matrix[16])
	{
		int index = 0;
		for (float i = 0; i < 4; ++i)
			for (float j = 0; j < 4; ++j)
			{
				(i, j) = matrix[index++];
			}
	}

	Mat4::Mat4(float const m1, float const m2, float const m3, float const m4, float const m5, float const m6, float const m7, float const m8, float const m9, float const m10, float const m11, float const m12, float const m13, float const m14, float const m15, float const m16)
	{
		m[0] = m1;
		m[1] = m2;
		m[2] = m3;
		m[3] = m4;

		m[4] = m5;
		m[5] = m6;
		m[6] = m7;
		m[7] = m8;

		m[8] = m9;
		m[9] = m10;
		m[10] = m11;
		m[11] = m12;

		m[12] = m13;
		m[13] = m14;
		m[14] = m15;
		m[15] = m16;
	}

	Mat4 Mat4::MatrixTranslation(Vector3 translate)
	{
		return Mat4{ 1, 0, 0, translate.x,
			0, 1, 0, translate.y,
			0, 0, 1, translate.z,
			0, 0, 0, 1 };
	}

	Mat4 Mat4::MatrixScale(Vector3 const scale)
	{
		return Mat4{ scale.x, 0, 0, 0,
			0, scale.y, 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1 };
	}

	Mat4 Mat4::MatrixRotateX(float const x)
	{
		return Mat4{ 1, 0, 0, 0,
			0, cos(x), sin(x), 0,
			0, -sin(x), cos(x), 0,
			0, 0, 0, 1 };
	}

	Mat4 Mat4::MatrixRotateY(float const y)
	{
		return Mat4{ cos(y), 0, -sin(y), 0,
			0, 1, 0, 0,
			sin(y), 0, cos(y), 0,
			0, 0, 0, 1 };
	}

	Mat4 Mat4::MatrixRotateZ(float const z)
	{
		return Mat4{ cos(z), sin(z), 0, 0,
			-sin(z), cos(z), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1 };
	}
	Mat4 Mat4::ProjectionMatrix(float const aspectRatio, float const fov, float const near, float const far)
	{
		float d = 1.f / tan(fov / 2.f);
		float range = 1.f / (near - far);

		return Mat4{ d / aspectRatio, 0.f, 0.f, 0.f,
			0.f, d, 0.f, 0.f,
			0.f, 0.f, (near + far)*range, -1.f,
			0.f, 0.f, (near*far*2.f)*range, 0.f };
	}

	Mat4 Mat4::operator*(Mat4 const& matrix) const
	{
		Mat4 a;
		for (int i = 0; i < 16; i += 4)
		{
			for (int j = 0; j < 4; j++)
			{
				a.m[i + j] = 0.0;
				for (int k = 0; k < 4; k++)
					a.m[i + j] += m[i + k] * matrix.m[k * 4 + j];
			}
		}

		return a;
	}

	Vector3 Mat4::operator*(Vector3 vec)
	{
		Vector3 result;
		result.x = m[1] * vec.x + m[2] * vec.y + m[3] * vec.z;
		result.y = m[5] * vec.x + m[6] * vec.y + m[7] * vec.z;
		result.z = m[9] * vec.x + m[10] * vec.y + m[11] * vec.z;
		return result;
	}

	Mat4 Mat4::operator*=(Mat4 const& matrix)
	{
		*this = *this * matrix;
		return *this;
	}

	Mat4 Mat4::operator+(Mat4 & matrix) const
	{
		Mat4 result;
		for (int i = 0; i < 16; ++i)
			result.m[i] = m[i] + matrix.m[i];
		return result;
	}

	Mat4 Mat4::Inverse()
	{
		Mat4 inv;

		inv.m[0] = m[5] * m[10] * m[15] -
			m[5] * m[11] * m[14] -
			m[9] * m[6] * m[15] +
			m[9] * m[7] * m[14] +
			m[13] * m[6] * m[11] -
			m[13] * m[7] * m[10];

		inv.m[4] = -m[4] * m[10] * m[15] +
			m[4] * m[11] * m[14] +
			m[8] * m[6] * m[15] -
			m[8] * m[7] * m[14] -
			m[12] * m[6] * m[11] +
			m[12] * m[7] * m[10];

		inv.m[8] = m[4] * m[9] * m[15] -
			m[4] * m[11] * m[13] -
			m[8] * m[5] * m[15] +
			m[8] * m[7] * m[13] +
			m[12] * m[5] * m[11] -
			m[12] * m[7] * m[9];

		inv.m[12] = -m[4] * m[9] * m[14] +
			m[4] * m[10] * m[13] +
			m[8] * m[5] * m[14] -
			m[8] * m[6] * m[13] -
			m[12] * m[5] * m[10] +
			m[12] * m[6] * m[9];

		inv.m[1] = -m[1] * m[10] * m[15] +
			m[1] * m[11] * m[14] +
			m[9] * m[2] * m[15] -
			m[9] * m[3] * m[14] -
			m[13] * m[2] * m[11] +
			m[13] * m[3] * m[10];

		inv.m[5] = m[0] * m[10] * m[15] -
			m[0] * m[11] * m[14] -
			m[8] * m[2] * m[15] +
			m[8] * m[3] * m[14] +
			m[12] * m[2] * m[11] -
			m[12] * m[3] * m[10];

		inv.m[9] = -m[0] * m[9] * m[15] +
			m[0] * m[11] * m[13] +
			m[8] * m[1] * m[15] -
			m[8] * m[3] * m[13] -
			m[12] * m[1] * m[11] +
			m[12] * m[3] * m[9];

		inv.m[13] = m[0] * m[9] * m[14] -
			m[0] * m[10] * m[13] -
			m[8] * m[1] * m[14] +
			m[8] * m[2] * m[13] +
			m[12] * m[1] * m[10] -
			m[12] * m[2] * m[9];

		inv.m[2] = m[1] * m[6] * m[15] -
			m[1] * m[7] * m[14] -
			m[5] * m[2] * m[15] +
			m[5] * m[3] * m[14] +
			m[13] * m[2] * m[7] -
			m[13] * m[3] * m[6];

		inv.m[6] = -m[0] * m[6] * m[15] +
			m[0] * m[7] * m[14] +
			m[4] * m[2] * m[15] -
			m[4] * m[3] * m[14] -
			m[12] * m[2] * m[7] +
			m[12] * m[3] * m[6];

		inv.m[10] = m[0] * m[5] * m[15] -
			m[0] * m[7] * m[13] -
			m[4] * m[1] * m[15] +
			m[4] * m[3] * m[13] +
			m[12] * m[1] * m[7] -
			m[12] * m[3] * m[5];

		inv.m[14] = -m[0] * m[5] * m[14] +
			m[0] * m[6] * m[13] +
			m[4] * m[1] * m[14] -
			m[4] * m[2] * m[13] -
			m[12] * m[1] * m[6] +
			m[12] * m[2] * m[5];

		inv.m[3] = -m[1] * m[6] * m[11] +
			m[1] * m[7] * m[10] +
			m[5] * m[2] * m[11] -
			m[5] * m[3] * m[10] -
			m[9] * m[2] * m[7] +
			m[9] * m[3] * m[6];

		inv.m[7] = m[0] * m[6] * m[11] -
			m[0] * m[7] * m[10] -
			m[4] * m[2] * m[11] +
			m[4] * m[3] * m[10] +
			m[8] * m[2] * m[7] -
			m[8] * m[3] * m[6];

		inv.m[11] = -m[0] * m[5] * m[11] +
			m[0] * m[7] * m[9] +
			m[4] * m[1] * m[11] -
			m[4] * m[3] * m[9] -
			m[8] * m[1] * m[7] +
			m[8] * m[3] * m[5];

		inv.m[15] = m[0] * m[5] * m[10] -
			m[0] * m[6] * m[9] -
			m[4] * m[1] * m[10] +
			m[4] * m[2] * m[9] +
			m[8] * m[1] * m[6] -
			m[8] * m[2] * m[5];
		return inv;
	}

	Mat4 Mat4::GetRevertedMatrix() const
	{
		return{
			m[0], m[4], m[8], m[12],
			m[1], m[5], m[9], m[13],
			m[2], m[6], m[10], m[14],
			m[3], m[7], m[11], m[15]
		};
	}

	void Mat4::Print() const
	{
		for (int i = 0; i < _countof(m); i += 4)
		{
			std::cout << m[i] << ", " << m[i+1] << ", " << m[i+2] << ", " << m[i+3] << std::endl;
		}
	}
	void Mat4::SetMatrix(float mat[16])
	{
		m[16] = mat[16];
	}
	std::string Mat4::Serialize()
	{
		std::string data;
		data = "\n\t\t\t\t\t {\n \t\t\t\t\t\t matrice: [";
		for (size_t i = 0; i < 16; ++i)
		{
			data += std::to_string(m[i]) + ", "; 
		}
		data += "]\n\t\t\t\t\t },\n";
		return data;
	}
	Mat4* Mat4::Deserialize(std::string& data)
	{
		Mat4* mat = new Mat4();
		float m[16];

		std::string str;

		data.erase(0, data.find_first_of("[") + 1);
		str = data.substr(0, data.find_first_of(","));
				
		m[0] = std::stof(str);

		for (size_t i = 1; i < 15; ++i)
		{
			data.erase(0, data.find_first_of(",") + 1);
			str = data.substr(0, data.find(","));
			m[i] = std::stof(str);
		}

		data.erase(0, data.find_first_of(",") + 1);
		str = data.substr(0, data.find(","));

		m[15] = std::stof(str);

		mat->SetMatrix(m);
		return mat;
	}
}