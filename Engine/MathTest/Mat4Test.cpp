#include "Mat4Test.h"

namespace math
{
	bool nmf(float A, float B)
	{
		return (fabs(A - B) < 0.0005f);
	}

	auto Mat4Test::StartTest() -> void
	{
		TestConstructor();
		TestInverse();
		TestOperatorAddMat4();
		TestOperatorProductMat4();
		TestOperatorProductVector3();
		TestRotateX();
		TestRotateY();
		TestRotateZ();
		TestScale();
		TestTranslate();
		TestProjectionMatrix();
	}
	auto Mat4Test::TestConstructor() -> void
	{
		Mat4 matrix = Mat4();
		assert(matrix.m[0] == 1.0f);
		assert(matrix.m[1] == 0.0f);
		assert(matrix.m[2] == 0.0f);
		assert(matrix.m[3] == 0.0f);

		assert(matrix.m[4] == 0.0f);
		assert(matrix.m[5] == 1.0f);
		assert(matrix.m[6] == 0.0f);
		assert(matrix.m[7] == 0.0f);

		assert(matrix.m[8] == 0.0f);
		assert(matrix.m[9] == 0.0f);
		assert(matrix.m[10] == 1.0f);
		assert(matrix.m[11] == 0.0f);

		assert(matrix.m[12] == 0.0f);
		assert(matrix.m[13] == 0.0f);
		assert(matrix.m[14] == 0.0f);
		assert(matrix.m[15] == 1.0f);

		Mat4 matrix2 = Mat4(12, 14, 1.25, 59, -8, -7.5, 4, 1, 11, 0, -6, 12, 2.85, 12, 14, 0);

		assert(matrix2.m[0] == 12.0f);
		assert(matrix2.m[1] == 14.0f);
		assert(matrix2.m[2] == 1.25f);
		assert(matrix2.m[3] == 59.0f);

		assert(matrix2.m[4] == -8.0f);
		assert(matrix2.m[5] == -7.5f);
		assert(matrix2.m[6] == 4.0f);
		assert(matrix2.m[7] == 1.0f);

		assert(matrix2.m[8] == 11.0f);
		assert(matrix2.m[9] == 0.0f);
		assert(matrix2.m[10] == -6.0f);
		assert(matrix2.m[11] == 12.0f);

		assert(matrix2.m[12] == 2.85f);
		assert(matrix2.m[13] == 12.0f);
		assert(matrix2.m[14] == 14.0f);
		assert(matrix2.m[15] == 0.0f);

	}

	auto Mat4Test::TestTranslate() -> void
	{
		Mat4 matrix = Mat4();
		Vector3 translate = Vector3(10, -5.84, 3);

		matrix = matrix.MatrixTranslation(translate);

		assert(matrix.m[0] == 1);
		assert(matrix.m[1] == 0);
		assert(matrix.m[2] == 0);
		assert(matrix.m[3] == 10);

		assert(matrix.m[4] == 0);
		assert(matrix.m[5] == 1);
		assert(matrix.m[6] == 0);
		assert(nmf(matrix.m[7],-5.84));

		assert(matrix.m[8] == 0);
		assert(matrix.m[9] == 0);
		assert(matrix.m[10] == 1);
		assert(matrix.m[11] == 3);

		assert(matrix.m[12] == 0);
		assert(matrix.m[13] == 0);
		assert(matrix.m[14] == 0);
		assert(matrix.m[15] == 1);
	}

	auto Mat4Test::TestScale() -> void
	{
		Mat4 matrix = Mat4();
		Vector3 scale = Vector3(10, -5.84, 3);

		matrix = matrix.MatrixScale(scale);

		assert(matrix.m[0] == 10);
		assert(matrix.m[1] == 0);
		assert(matrix.m[2] == 0);
		assert(matrix.m[3] == 0);

		assert(matrix.m[4] == 0);
		assert(nmf(matrix.m[5],-5.84));
		assert(matrix.m[6] == 0);
		assert(matrix.m[7] == 0);

		assert(matrix.m[8] == 0);
		assert(matrix.m[9] == 0);
		assert(matrix.m[10] == 3);
		assert(matrix.m[11] == 0);

		assert(matrix.m[12] == 0);
		assert(matrix.m[13] == 0);
		assert(matrix.m[14] == 0);
		assert(matrix.m[15] == 0);
	}

	auto Mat4Test::TestRotateX() -> void
	{
		Mat4 matrix = Mat4();
		
		matrix = matrix.MatrixRotateX(12);

		assert(matrix.m[0] == 1);
		assert(matrix.m[1] == 0);
		assert(matrix.m[2] == 0);
		assert(matrix.m[3] == 0);

		assert(matrix.m[4] == 0);
		assert(nmf(matrix.m[5], cos(12)));
		assert(nmf(matrix.m[6],sin(12)));
		assert(matrix.m[7] == 0);

		assert(matrix.m[8] == 0);
		assert(nmf(matrix.m[9],-sin(12)));
		assert(nmf(matrix.m[10],cos(12)));
		assert(matrix.m[11] == 0);

		assert(matrix.m[12] == 0);
		assert(matrix.m[13] == 0);
		assert(matrix.m[14] == 0);
		assert(matrix.m[15] == 1);

		Mat4 matrix2 = Mat4();

		matrix2 = matrix2.MatrixRotateX(-3.54);

		assert(matrix2.m[0] == 1);
		assert(matrix2.m[1] == 0);
		assert(matrix2.m[2] == 0);
		assert(matrix2.m[3] == 0);

		assert(matrix2.m[4] == 0);
		assert(nmf(matrix2.m[5], cos(-3.54)));
		assert(nmf(matrix2.m[6], sin(-3.54)));
		assert(matrix2.m[7] == 0);

		assert(matrix2.m[8] == 0);
		assert(nmf(matrix2.m[9], -sin(-3.54)));
		assert(nmf(matrix2.m[10], cos(-3.54)));
		assert(matrix2.m[11] == 0);

		assert(matrix2.m[12] == 0);
		assert(matrix2.m[13] == 0);
		assert(matrix2.m[14] == 0);
		assert(matrix2.m[15] == 1);

		Mat4 matrix3 = Mat4();

		matrix3 = matrix3.MatrixRotateX(1.26);

		assert(matrix3.m[0] == 1);
		assert(matrix3.m[1] == 0);
		assert(matrix3.m[2] == 0);
		assert(matrix3.m[3] == 0);

		assert(matrix3.m[4] == 0);
		assert(nmf(matrix3.m[5], cos(1.26)));
		assert(nmf(matrix3.m[6], sin(1.26)));
		assert(matrix3.m[7] == 0);

		assert(matrix3.m[8] == 0);
		assert(nmf(matrix3.m[9], -sin(1.26)));
		assert(nmf(matrix3.m[10], cos(1.26)));
		assert(matrix3.m[11] == 0);

		assert(matrix3.m[12] == 0);
		assert(matrix3.m[13] == 0);
		assert(matrix3.m[14] == 0);
		assert(matrix3.m[15] == 1);
	}

	auto Mat4Test::TestRotateY() -> void
	{
		Mat4 matrix = Mat4();

		matrix = matrix.MatrixRotateY(12);

		assert(nmf(matrix.m[0],cos(12)));
		assert(matrix.m[1] == 0);
		assert(nmf(matrix.m[2],-sin(12)));
		assert(matrix.m[3] == 0);

		assert(matrix.m[4] == 0);
		assert(matrix.m[5] == 1);
		assert(matrix.m[6] == 0);
		assert(matrix.m[7] == 0);

		assert(nmf(matrix.m[8],sin(12)));
		assert(matrix.m[9] == 0);
		assert(nmf(matrix.m[10],cos(12)));
		assert(matrix.m[11] == 0);

		assert(matrix.m[12] == 0);
		assert(matrix.m[13] == 0);
		assert(matrix.m[14] == 0);
		assert(matrix.m[15] == 1);

		Mat4 matrix2 = Mat4();
		
		matrix2 = matrix2.MatrixRotateY(-3.54);

		assert(nmf(matrix2.m[0],cos(-3.54)));
		assert(matrix2.m[1] == 0);
		assert(nmf(matrix2.m[2],-sin(-3.54)));
		assert(matrix2.m[3] == 0);

		assert(matrix2.m[4] == 0);
		assert(matrix2.m[5] == 1);
		assert(matrix2.m[6] == 0);
		assert(matrix2.m[7] == 0);

		assert(nmf(matrix2.m[8],sin(-3.54)));
		assert(matrix2.m[9] == 0);
		assert(nmf(matrix2.m[10],cos(-3.54)));
		assert(matrix2.m[11] == 0);

		assert(matrix2.m[12] == 0);
		assert(matrix2.m[13] == 0);
		assert(matrix2.m[14] == 0);
		assert(matrix2.m[15] == 1);

		Mat4 matrix3 = Mat4();

		matrix3 = matrix3.MatrixRotateY(1.26);

		assert(nmf(matrix3.m[0],cos(1.26)));
		assert(matrix3.m[1] == 0);
		assert(nmf(matrix3.m[2],-sin(1.26)));
		assert(matrix3.m[3] == 0);

		assert(matrix3.m[4] == 0);
		assert(matrix3.m[5] == 1);
		assert(matrix3.m[6] == 0);
		assert(matrix3.m[7] == 0);

		assert(nmf(matrix3.m[8],sin(1.26)));
		assert(matrix3.m[9] == 0);
		assert(nmf(matrix3.m[10],cos(1.26)));
		assert(matrix3.m[11] == 0);

		assert(matrix3.m[12] == 0);
		assert(matrix3.m[13] == 0);
		assert(matrix3.m[14] == 0);
		assert(matrix3.m[15] == 1);
	}

	auto Mat4Test::TestRotateZ() -> void
	{
		Mat4 matrix = Mat4();

		matrix = matrix.MatrixRotateZ(12);

		assert(nmf(matrix.m[0],cos(12)));
		assert(nmf(matrix.m[1],sin(12)));
		assert(matrix.m[2] == 0);
		assert(matrix.m[3] == 0);

		assert(nmf(matrix.m[4],-sin(12)));
		assert(nmf(matrix.m[5],cos(12)));
		assert(matrix.m[6] == 0);
		assert(matrix.m[7] == 0);

		assert(matrix.m[8] == 0);
		assert(matrix.m[9] == 0);
		assert(matrix.m[10] == 1);
		assert(matrix.m[11] == 0);

		assert(matrix.m[12] == 0);
		assert(matrix.m[13] == 0);
		assert(matrix.m[14] == 0);
		assert(matrix.m[15] == 1);

		Mat4 matrix2 = Mat4();
		
		matrix2 = matrix2.MatrixRotateZ(-3.54);

		assert(nmf(matrix2.m[0],cos(-3.54)));
		assert(nmf(matrix2.m[1],sin(-3.54)));
		assert(matrix2.m[2] == 0);
		assert(matrix2.m[3] == 0);

		assert(nmf(matrix2.m[4],-sin(-3.54)));
		assert(nmf(matrix2.m[5],cos(-3.54)));
		assert(matrix2.m[6] == 0);
		assert(matrix2.m[7] == 0);

		assert(matrix2.m[8] == 0);
		assert(matrix2.m[9] == 0);
		assert(matrix2.m[10] == 1);
		assert(matrix2.m[11] == 0);

		assert(matrix2.m[12] == 0);
		assert(matrix2.m[13] == 0);
		assert(matrix2.m[14] == 0);
		assert(matrix2.m[15] == 1);

		Mat4 matrix3 = Mat4();

		matrix3 = matrix3.MatrixRotateZ(1.26);

		assert(nmf(matrix3.m[0],cos(1.26)));
		assert(nmf(matrix3.m[1],sin(1.26)));
		assert(matrix3.m[2] == 0);
		assert(matrix3.m[3] == 0);

		assert(nmf(matrix3.m[4],-sin(1.26)));
		assert(nmf(matrix3.m[5],cos(1.26)));
		assert(matrix3.m[6] == 0);
		assert(matrix3.m[7] == 0);

		assert(matrix3.m[8] == 0);
		assert(matrix3.m[9] == 0);
		assert(matrix3.m[10] == 1);
		assert(matrix3.m[11] == 0);

		assert(matrix3.m[12] == 0);
		assert(matrix3.m[13] == 0);
		assert(matrix3.m[14] == 0);
		assert(matrix3.m[15] == 1);
	}

	auto Mat4Test::TestProjectionMatrix() -> void
	{
		Mat4 matrix = Mat4();
		
		matrix = matrix.ProjectionMatrix(1280/720, 42, 0.1, 1000);

		assert(nmf(matrix.m[0],(1/ tan(42/2))/(1280/720)));
		assert(matrix.m[1] == 0);
		assert(matrix.m[2] == 0);
		assert(matrix.m[3] == 0);

		assert(matrix.m[4] == 0);
		assert(nmf(matrix.m[5],1/tan(42/2)));
		assert(matrix.m[6] == 0);
		assert(matrix.m[7] == 0);

		assert(matrix.m[8] == 0);
		assert(matrix.m[9] == 0);
		assert(nmf(matrix.m[10], (0.1 + 1000) * (1.f / (0.1 - 1000))));
		assert(matrix.m[11] == -1.f);

		assert(matrix.m[12] == 0);
		assert(matrix.m[13] == 0);
		assert(nmf(matrix.m[14],(0.1 * 1000 * 2.f) * (1.f / (0.1 - 1000))));
		assert(matrix.m[15] == 0);
	}

	auto Mat4Test::TestInverse() -> void
	{
		Mat4 m = Mat4(1, 0, 0, 0,
					    0, 1, 0, 0,
						0, 0, 1, 0,
						0, 0, 0, 1);
		
		m.Inverse();

		assert(m.m[0] == m.m[5] * m.m[10] * m.m[15] - m.m[5] * m.m[11] * m.m[14] - m.m[9] * m.m[6] * m.m[15] + m.m[9] * m.m[7] * m.m[14] + m.m[13] * m.m[6] * m.m[11] -	m.m[13] * m.m[7] * m.m[10]);
		assert(m.m[1] == -m.m[1] * m.m[10] * m.m[15] + m.m[1] * m.m[11] * m.m[14] + m.m[9] * m.m[2] * m.m[15] - m.m[9] * m.m[3] * m.m[14] - m.m[13] * m.m[2] * m.m[11] + m.m[13] * m.m[3] * m.m[10]);
		assert(m.m[2] == m.m[1] * m.m[6] * m.m[15] - m.m[1] * m.m[7] * m.m[14] - m.m[5] * m.m[2] * m.m[15] + m.m[5] * m.m[3] * m.m[14] + m.m[13] * m.m[2] * m.m[7] - m.m[13] * m.m[3] * m.m[6]);
		assert(m.m[3] == -m.m[1] * m.m[6] * m.m[11] + m.m[1] * m.m[7] * m.m[10] + m.m[5] * m.m[2] * m.m[11] - m.m[5] * m.m[3] * m.m[10] - m.m[9] * m.m[2] * m.m[7] + m.m[9] * m.m[3] * m.m[6]);

		assert(m.m[4] == -(m.m[4]) * m.m[10] * m.m[15] + m.m[4] * m.m[11] * m.m[14] + m.m[8] * m.m[6] * m.m[15] - m.m[8] * m.m[7] * m.m[14] - m.m[12] * m.m[6] * m.m[11] + m.m[12] * m.m[7] * m.m[10]);
		assert(m.m[5] == m.m[0] * m.m[10] * m.m[15] - m.m[0] * m.m[11] * m.m[14] - m.m[8] * m.m[2] * m.m[15] + m.m[8] * m.m[3] * m.m[14] + m.m[12] * m.m[2] * m.m[11] - m.m[12] * m.m[3] * m.m[10]);
		assert(m.m[6] == -m.m[0] * m.m[6] * m.m[15] + m.m[0] * m.m[7] * m.m[14] + m.m[4] * m.m[2] * m.m[15] - m.m[4] * m.m[3] * m.m[14] - m.m[12] * m.m[2] * m.m[7] + m.m[12] * m.m[3] * m.m[6]);
		assert(m.m[7] == m.m[0] * m.m[6] * m.m[11] - m.m[0] * m.m[7] * m.m[10] - m.m[4] * m.m[2] * m.m[11] + m.m[4] * m.m[3] * m.m[10] + m.m[8] * m.m[2] * m.m[7] - m.m[8] * m.m[3] * m.m[6]);

		assert(m.m[8] == m.m[4] * m.m[9] * m.m[15] - m.m[4] * m.m[11] * m.m[13] - m.m[8] * m.m[5] * m.m[15] + m.m[8] * m.m[7] * m.m[13] + m.m[12] * m.m[5] * m.m[11] - m.m[12] * m.m[7] * m.m[9]);
		assert(m.m[9] == -m.m[0] * m.m[9] * m.m[15] + m.m[0] * m.m[11] * m.m[13] + m.m[8] * m.m[1] * m.m[15] - m.m[8] * m.m[3] * m.m[13] - m.m[12] * m.m[1] * m.m[11] +	m.m[12] * m.m[3] * m.m[9]);
		assert(m.m[10] == m.m[0] * m.m[5] * m.m[15] - m.m[0] * m.m[7] * m.m[13] - m.m[4] * m.m[1] * m.m[15] + m.m[4] * m.m[3] * m.m[13] + m.m[12] * m.m[1] * m.m[7] - m.m[12] * m.m[3] * m.m[5]);
		assert(m.m[11] == -m.m[0] * m.m[5] * m.m[11] + m.m[0] * m.m[7] * m.m[9] + m.m[4] * m.m[1] * m.m[11] - m.m[4] * m.m[3] * m.m[9] - m.m[8] * m.m[1] * m.m[7] + m.m[8] * m.m[3] * m.m[5]);

		assert(m.m[12] == -m.m[4] * m.m[9] * m.m[14] + m.m[4] * m.m[10] * m.m[13] +	m.m[8] * m.m[5] * m.m[14] -	m.m[8] * m.m[6] * m.m[13] -	m.m[12] * m.m[5] * m.m[10] + m.m[12] * m.m[6] * m.m[9]);
		assert(m.m[13] == m.m[0] * m.m[9] * m.m[14] - m.m[0] * m.m[10] * m.m[13] - m.m[8] * m.m[1] * m.m[14] + m.m[8] * m.m[2] * m.m[13] + m.m[12] * m.m[1] * m.m[10] - m.m[12] * m.m[2] * m.m[9]);
		assert(m.m[14] == -m.m[0] * m.m[5] * m.m[14] + m.m[0] * m.m[6] * m.m[13] + m.m[4] * m.m[1] * m.m[14] - m.m[4] * m.m[2] * m.m[13] - m.m[12] * m.m[1] * m.m[6] + m.m[12] * m.m[2] * m.m[5]);
		assert(m.m[15] == m.m[0] * m.m[5] * m.m[10] - m.m[0] * m.m[6] * m.m[9] - m.m[4] * m.m[1] * m.m[10] + m.m[4] * m.m[2] * m.m[9] + m.m[8] * m.m[1] * m.m[6] - m.m[8] * m.m[2] * m.m[5]);
	}

	auto Mat4Test::TestOperatorProductMat4() -> void
	{
		Mat4 m1 = Mat4(12, 14, 1.25, 59,
						-8, -7.5, 4, 1,
						11, 0, -6, 12,
						2.85, 12, 14, 0);

		Mat4 m2 = Mat4(1.35, 1, 0.89, -77,
						-51.4, 13, 0, 1,
						1, -2.57, 5, 58,
						0,	0.1, 0, 15);

		Mat4 m3 = m1 * m2;

		assert(m3.m[0] == m1.m[0] * m2.m[0] + m1.m[1] * m2.m[4] + m1.m[2] * m2.m[8] + m1.m[3] * m2.m[12]);
		assert(m3.m[1] == m1.m[0] * m2.m[1] + m1.m[1] * m2.m[5] + m1.m[2] * m2.m[9] + m1.m[3] * m2.m[13]);
		assert(m3.m[2] == m1.m[0] * m2.m[2] + m1.m[1] * m2.m[6] + m1.m[2] * m2.m[10] + m1.m[3] * m2.m[14]);
		assert(m3.m[3] == m1.m[0] * m2.m[3] + m1.m[1] * m2.m[7] + m1.m[2] * m2.m[11] + m1.m[3] * m2.m[15]);

		assert(m3.m[4] == m1.m[4] * m2.m[0] + m1.m[5] * m2.m[4] + m1.m[6] * m2.m[8] + m1.m[7] * m2.m[12]);
		assert(m3.m[5] == m1.m[4] * m2.m[1] + m1.m[5] * m2.m[5] + m1.m[6] * m2.m[9] + m1.m[7] * m2.m[13]);
		assert(m3.m[6] == m1.m[4] * m2.m[2] + m1.m[5] * m2.m[6] + m1.m[6] * m2.m[10] + m1.m[7] * m2.m[14]);
		assert(m3.m[7] == m1.m[4] * m2.m[3] + m1.m[5] * m2.m[7] + m1.m[6] * m2.m[11] + m1.m[7] * m2.m[15]);

		assert(m3.m[8] == m1.m[8] * m2.m[0] + m1.m[9] * m2.m[4] + m1.m[10] * m2.m[8] + m1.m[11] * m2.m[12]);
		assert(m3.m[9] == m1.m[8] * m2.m[1] + m1.m[9] * m2.m[5] + m1.m[10] * m2.m[9] + m1.m[11] * m2.m[13]);
		assert(m3.m[10] == m1.m[8] * m2.m[2] + m1.m[9] * m2.m[6] + m1.m[10] * m2.m[10] + m1.m[11] * m2.m[14]);
		assert(m3.m[11] == m1.m[8] * m2.m[3] + m1.m[9] * m2.m[7] + m1.m[10] * m2.m[11] + m1.m[11] * m2.m[15]);

		assert(m3.m[12] == m1.m[12] * m2.m[0] + m1.m[13] * m2.m[4] + m1.m[14] * m2.m[8] + m1.m[15] * m2.m[12]);
		assert(m3.m[13] == m1.m[12] * m2.m[1] + m1.m[13] * m2.m[5] + m1.m[14] * m2.m[9] + m1.m[15] * m2.m[13]);
		assert(m3.m[14] == m1.m[12] * m2.m[2] + m1.m[13] * m2.m[6] + m1.m[14] * m2.m[10] + m1.m[15] * m2.m[14]);
		assert(m3.m[15] == m1.m[12] * m2.m[3] + m1.m[13] * m2.m[7] + m1.m[14] * m2.m[11] + m1.m[15] * m2.m[15]);
	}

	auto Mat4Test::TestOperatorProductVector3() -> void
	{
		Mat4 matrix = Mat4(12, 14, 1.25, 59, -8, -7.5, 4, 1, 11, 0, -6, 12, 2.85, 12, 14, 0);
		Vector3 vec = Vector3(124, 1.45, -84.156);
		Vector3 result;

		result = matrix * vec;

		assert(result.x = matrix.m[1] * vec.x + matrix.m[2] * vec.y + matrix.m[3] * vec.z);
		assert(result.y = matrix.m[5] * vec.x + matrix.m[6] * vec.y + matrix.m[7] * vec.z);
		assert(result.z = matrix.m[9] * vec.x + matrix.m[10] * vec.y + matrix.m[11] * vec.z);

	}

	auto Mat4Test::TestOperatorAddMat4() -> void
	{
		Mat4 m1 = Mat4(12, 14, 1.25, 59, -8, -7.5, 4, 1, 11, 0, -6, 12, 2.85, 12, 14, 0);
		Mat4 m2 = Mat4(1.35, 1, 0.89, -77, -51.4, 13, 0, 1,	1, -2.57, 5, 58, 0, 0.1, 0, 15);

		Mat4 m3;

		m3 = m1 + m2;

		assert(m3.m[0] = m1.m[0] + m2.m[0]);
		assert(m3.m[1] = m1.m[1] + m2.m[1]);
		assert(m3.m[2] = m1.m[2] + m2.m[2]);
		assert(m3.m[3] = m1.m[3] + m2.m[3]);
		assert(m3.m[4] = m1.m[4] + m2.m[4]);
		assert(m3.m[5] = m1.m[5] + m2.m[5]);
		assert(m3.m[6] = m1.m[6] + m2.m[6]);
		assert(m3.m[7] = m1.m[7] + m2.m[7]);
		assert(m3.m[8] = m1.m[8] + m2.m[8]);
		assert(m3.m[9] = m1.m[9] + m2.m[9]);
		assert(m3.m[10] = m1.m[10] + m2.m[10]);
		assert(m3.m[11] = m1.m[11] + m2.m[11]);
		assert(m3.m[12] = m1.m[12] + m2.m[12]);
		assert(m3.m[13] = m1.m[13] + m2.m[13]);
		assert(m3.m[14] = m1.m[14] + m2.m[14]);
		assert(m3.m[15] = m1.m[15] + m2.m[15]);
	}



}
