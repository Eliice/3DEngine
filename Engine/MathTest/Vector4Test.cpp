#include "Vector4Test.h"

#include <assert.h>
#include <math.h>

bool cmf(float A, float B)
{
	return (fabs(A - B) < 0.0005f);
}

auto math::Vector4Test::StartTest() -> void
{
	TestConstructor();
	TestOperatorEquals();
	TestOperatorNotEquals();
	TestOperatorAdd();
	TestOperatorLess();
	TestOperatorAffect();
	TestOperatorPlusEquals();
	TestOperatorMinusEquals();
	TestSize();
	TestNormalise();
	TestDot();
	TestScale();
}

auto math::Vector4Test::TestConstructor() -> void
{
	Vector4 vec = Vector4(1, -1, 1.5, -1.0);
	assert(vec.x == 1);
	assert(vec.y == -1);
	assert(vec.z == 1.5);
	assert(vec.w == -1.0);

	Vector4 vec1 = Vector4();
	assert(vec1.x == 0);
	assert(vec1.y == 0);
	assert(vec1.z == 0);
	assert(vec1.w == 0);

	Vector4 vec2 = Vector4(-666, 95, 12.4, -3.014);
	assert(vec2.x == -666);
	assert(vec2.y == 95);
	assert(cmf(vec2.z, 12.4));
	assert(cmf(vec2.w, -3.014));
}

auto math::Vector4Test::TestOperatorEquals() -> void
{
	Vector4 vec1 = Vector4(1, 1, 1, 1);
	Vector4 vec2 = Vector4(-1, -1, -1, -1);
	Vector4 vec3 = Vector4(1, 1, 1, 1);

	assert(vec1 == vec3);
	assert(!(vec1 == vec2));
}

auto math::Vector4Test::TestOperatorNotEquals() -> void
{
	Vector4 vec1 = Vector4(1, 1, 1, 1);
	Vector4 vec2 = Vector4(45, 45, 45, 45);
	Vector4 vec3 = Vector4(1, 1, 1, 1);

	assert(vec1 != vec2);
	assert(!(vec1 != vec3));

}

auto math::Vector4Test::TestOperatorAdd() -> void
{
	Vector4 vec1 = Vector4(1, 1, 1, 1);
	Vector4 vec2 = Vector4(-1, -1, -1, -1);
	Vector4 vec3 = Vector4(0, 0, 0, 0);

	Vector4 vec4 = vec1 + vec2;
	assert(vec4.x == 0);
	assert(vec4.y == 0);
	assert(vec4.z == 0);
	assert(vec4.w == 0);

	vec4 = vec1 + vec3;
	assert(vec4.x == 1);
	assert(vec4.y == 1);
	assert(vec4.z == 1);
	assert(vec4.w == 1);

	vec4 = vec2 + vec3;
	assert(vec4.x == -1);
	assert(vec4.y == -1);
	assert(vec4.z == -1);
	assert(vec4.w == -1);
}

auto math::Vector4Test::TestOperatorLess() -> void
{
	Vector4 vec1 = Vector4(1, 1, 1, 1);
	Vector4 vec2 = Vector4(-1, -1, -1, -1);
	Vector4 vec3 = Vector4(0, 0, 0, 0);

	Vector4 vec4 = vec1 - vec2;
	assert(vec4.x == 2);
	assert(vec4.y == 2);
	assert(vec4.z == 2);
	assert(vec4.w == 2);

	vec4 = vec1 - vec3;
	assert(vec4.x == 1);
	assert(vec4.y == 1);
	assert(vec4.z == 1);
	assert(vec4.w == 1);

	vec4 = vec2 - vec3;
	assert(vec4.x == -1);
	assert(vec4.y == -1);
	assert(vec4.z == -1);
	assert(vec4.w == -1);
}

auto math::Vector4Test::TestOperatorAffect() -> void
{
	Vector4 vec = Vector4(1, -1, 1, -1);
	Vector4 result = vec;
	
	assert(result.x == 1);
	assert(result.y == -1);
	assert(result.z == 1);
	assert(result.w == -1);
}

auto math::Vector4Test::TestOperatorPlusEquals() -> void
{
	Vector4 vec1 = Vector4(1, 15, -84.15, 0.86);
	Vector4 vec2 = Vector4(-5, 0, 1, 145);
	vec2 += vec1;

	assert(vec2.x == -4);
	assert(vec2.y == 15);
	assert(cmf(vec2.z,-83.15));
	assert(cmf(vec2.w,145.86));
}

auto math::Vector4Test::TestOperatorMinusEquals() -> void
{
	Vector4 vec1 = Vector4(1, 15, -84.15, 0.86);
	Vector4 vec2 = Vector4(-5, 0, 1, 145);
	vec2 -= vec1;

	assert(vec2.x == -6);
	assert(vec2.y == -15);
	assert(cmf(vec2.z, 85.15));
	assert(cmf(vec2.w, 144.14));
}

auto math::Vector4Test::TestSize() -> void
{
	Vector4 vec = Vector4(2, 2, 2, 2);
	float size = vec.Size();
	assert(cmf(size, sqrt(16)));

	vec = Vector4(-2, -2, -2, -2);
	size = vec.Size();
	assert(cmf(size, sqrt(16)));
}

auto math::Vector4Test::TestNormalise() -> void
{
	Vector4 vec = Vector4(10, 25, 6.18, 4781.1048);
	Vector4 norm = vec.Normalise();

	float size = vec.Size();
	assert(norm.x == vec.x / size);
	assert(norm.y == vec.y / size);
	assert(norm.z == vec.z / size);
	assert(norm.w == vec.w / size);
}

auto math::Vector4Test::TestDot() -> void
{
	Vector4 vec1 = Vector4(10, 10, 10, 10);
	Vector4 vec2 = Vector4(-5, 42, -5, 42);
	float dot = vec1.Dot(vec2);

	assert(dot == 740);
}

auto math::Vector4Test::TestScale() -> void
{
	Vector4 vec = Vector4(10, -10, 10, -10);
	float scale = 18;
	vec.Scale(scale);

	assert(vec.x == 10 * scale);
	assert(vec.y == -10 * scale);
	assert(vec.z == 10 * scale);
	assert(vec.w == -10 * scale);
}
