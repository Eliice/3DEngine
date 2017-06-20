#include "Vector2Test.h"

#include <assert.h>
#include <math.h>

using namespace math;

bool cmpf(float A, float B)
{
	return (fabs(A - B) < 0.0005f);
}

auto Vector2Test::StartTest() -> void
{
	TestConstructeur();
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

auto Vector2Test::TestConstructeur() -> void
{
	Vector2 vec2 = Vector2();
	assert(vec2.x == 0);
	assert(vec2.y == 0);
	Vector2 vec = Vector2(1, -1);
	assert(vec.x == 1);
	assert(vec.y == -1);
	Vector2 vec1 = Vector2(-666, 95);
	assert(vec1.x == -666);
	assert(vec1.y == 95);
}

auto Vector2Test::TestOperatorEquals() -> void
{
	Vector2 vec1 = Vector2(1, 1);
	Vector2 vec2 = Vector2(-1,-1);
	Vector2 vec3 = Vector2(1, 1);

	assert(vec1 == vec3);
	assert(!(vec1 == vec2));
}

auto Vector2Test::TestOperatorNotEquals() -> void
{
	Vector2 vec1 = Vector2(1, 1);
	Vector2 vec2 = Vector2(-1, -1);
	Vector2 vec3 = Vector2(1, 1);

	assert(!(vec1 != vec3));
	assert(vec1 != vec2);
}

auto Vector2Test::TestOperatorAdd() -> void
{
	Vector2 vec1 = Vector2(1, 1);
	Vector2 vec2 = Vector2(-1, -1);
	Vector2 vec3 = Vector2(0, 0);

	Vector2 vec4 = vec1 + vec2;
	assert(vec4.x == 0);
	assert(vec4.y == 0);

	vec4 = vec1 + vec3;
	assert(vec4.x == 1);
	assert(vec4.y == 1);

	vec4 = vec2 + vec3;
	assert(vec4.x == -1);
	assert(vec4.y == -1);
}

auto Vector2Test::TestOperatorLess() -> void
{
	Vector2 vec1 = Vector2(1, 1);
	Vector2 vec2 = Vector2(-1, -1);
	Vector2 vec3 = Vector2(0, 0);

	Vector2 vec4 = vec1 - vec2;
	assert(vec4.x == 2);
	assert(vec4.y == 2);

	vec4 = vec3 - vec1;
	assert(vec4.x == -1);
	assert(vec4.y == -1);

	vec4 = vec3 - vec3;
	assert(vec4.x == 0);
	assert(vec4.y == 0);

}

auto Vector2Test::TestOperatorAffect() -> void
{
	Vector2 vec = Vector2(1, -1);
	Vector2 result = vec;

	assert(result.x == 1);
	assert(result.y == -1);
}

auto Vector2Test::TestOperatorPlusEquals() -> void
{
	Vector2 vec1 = Vector2(1, 15);
	Vector2 vec2 = Vector2(-5, 0);
	vec2 += vec1;

	assert(vec2.x == -4);
	assert(vec2.y == 15);
}

auto Vector2Test::TestOperatorMinusEquals() -> void
{
	Vector2 vec1 = Vector2(1, 15);
	Vector2 vec2 = Vector2(-5, 0);
	vec2 -= vec1;

	assert(vec2.x == -6);
	assert(vec2.y == -15);
}

auto Vector2Test::TestSize() -> void
{
	Vector2 vec = Vector2(2, 2);
	float size = vec.Size();
	assert(cmpf(size,sqrt(8)));


	vec = Vector2(-2, -2);
	size = vec.Size();
	assert(cmpf(size, sqrt(8)));
}

auto Vector2Test::TestNormalise() -> void
{
	Vector2 vec = Vector2(10, 25);
	Vector2 norm = vec.Normalise();

	float size = vec.Size();
	assert(norm.x == vec.x / size);
	assert(norm.y == vec.y / size);

}

auto Vector2Test::TestDot() -> void
{
	Vector2 vec1 = Vector2(10, 10);
	Vector2 vec2 = Vector2(-5, 42);
	float dot = vec1.Dot(vec2);

	assert(dot == 370);
}

auto Vector2Test::TestScale() -> void
{
	Vector2 vec = Vector2(10, -10);
	float scale = 18;
	vec.Scale(scale);

	assert(vec.x == 10 * scale);
	assert(vec.y == -10 * scale);
}