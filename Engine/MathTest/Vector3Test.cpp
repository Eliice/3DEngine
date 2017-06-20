#include "Vector3Test.h"
#include <assert.h>


bool cmp(float A, float B)
{
	return (fabs(A - B) < 0.01f);
}

auto Vector3Test::TestAll() -> void
{
	TestConstructeur();
	TestCross();
	TestDot();
	TestLength();
	TestDistance();
	TestNormalize();
	//TestNormalizeNormals();
	TestSetAbsolute();
	TestOperatorProduct();
	TestOperatorAffectProduct();
	TestOperatorDivided();
	TestOperatorAffectDivided();
	TestOperatorAdd();
	TestOperatorAffectAdd();
	TestOperatorMinus();
	TestOperatorAffectMinus();
	TestOperatorEquals();
	TestOperatorNotEquals();
}

auto Vector3Test::TestConstructeur() -> void
{
	Vector3 vec = Vector3();
	assert(vec.x == 0);
	assert(vec.y == 0);
	assert(vec.z == 0);
	Vector3 vec1 = Vector3(-52.6);
	assert(cmp(vec1.x,-52.6));
	assert(cmp(vec1.y,-52.6));
	assert(cmp(vec1.z,-52.6));
	Vector3 vec2 = Vector3(10, -42, 0.666);
	assert(vec2.x == 10);
	assert(vec2.y == -42);
	assert(cmp(vec2.z,0.666));
}

auto Vector3Test::TestCross() -> void
{
	Vector3 vec = Vector3(10, -666, 0.356);
	Vector3 vec1 = Vector3(-69, 1.256, 42);
	Vector3 res = vec.cross(vec1);
	assert(cmp(res.x,-27972.447136));
	assert(cmp(res.y,-444.564));
	assert(cmp(res.z,-45941.44));
}

auto Vector3Test::TestDot() -> void
{
	Vector3 vec = Vector3(10, -42, 0.123);
	Vector3 vec1 = Vector3(-5, -0.69, 32);
	float dot = vec.dot(vec1);
	assert(cmp(dot,-17.084));
}

auto Vector3Test::TestLength() -> void
{
	Vector3 vec = Vector3(69, 0.666, -159);
	float length = vec.length();
	assert(cmp(length,sqrt(30042.443556)));
}

auto Vector3Test::TestDistance() -> void
{
	Vector3 vec = Vector3();
	Vector3 vec1 = Vector3(10, 0.569, -963);
	float distance = vec.distance(vec1);
	assert(cmp(distance,vec1.length()));
}

auto Vector3Test::TestNormalize() -> void
{
	Vector3 vec = Vector3(10, 32.96357, -42);
	float lengt = vec.length();
	Vector3 res = vec.normalize();
	assert(res.x == vec.x / lengt);
	assert(res.y == vec.y / lengt);
	assert(res.z == vec.z / lengt);
}

auto Vector3Test::TestSetAbsolute() -> void
{
	Vector3 vec = Vector3(42, -666, 9.87);
	vec.setAbsolute();
	assert(vec.x == 42);
	assert(cmp(vec.y,-666));
	assert(cmp(vec.z,9.87));
}

auto Vector3Test::TestVector3ToVector4() -> void
{
	Vector3 vec(564, -140, 4.1845);
	Vector4 vec1;
	vec1 = vec.vector3ToVector4();

	assert(vec1 == Vector4(564,-140,4.1845,0));

}

auto Vector3Test::TestOperatorProduct() -> void
{
	Vector3 vec = Vector3(10, 0.5, -8);
	float mult = 42;
	Vector3 res = vec*mult;
	assert(res.x == 420);
	assert(res.y == 21);
	assert(res.z == -336);
}

auto Vector3Test::TestOperatorAffectProduct() -> void
{
	Vector3 vec = Vector3(10, 0.5, -8);
	float mult = 42;
	vec *= mult;
	assert(vec.x == 420);
	assert(vec.y == 21);
	assert(vec.z == -336);
}

auto Vector3Test::TestOperatorDivided() -> void
{
	Vector3 vec = Vector3(20, -8, 4.2);
	float divided = -3;
	Vector3 res = vec / divided;
	assert(cmp(res.x, -6.666667));
	assert(cmp(res.y,2.6666667));
	assert(cmp(res.z,-1.4));
}

auto Vector3Test::TestOperatorAffectDivided() -> void
{
	Vector3 vec = Vector3(20, -8, 4.2);
	float divided = -3;
	vec /= divided;
	assert(cmp(vec.x, -6.666667));
	assert(cmp(vec.y, 2.6666667));
	assert(cmp(vec.z, -1.4));
}

auto Vector3Test::TestOperatorAdd() -> void
{
	Vector3 vec = Vector3(10, -8, 32.54);
	Vector3 vec1 = Vector3(-5, 1.5, -66);
	Vector3 res = vec + vec1;
	assert(res.x == 5);
	assert(res.y == -6.5);
	assert(cmp(res.z,-33.46));

}

auto Vector3Test::TestOperatorAffectAdd() -> void
{
	Vector3 vec = Vector3(10, -8, 32.54);
	Vector3 vec1 = Vector3(-5, 1.5, -66);
	vec += vec1;
	assert(vec.x == 5);
	assert(vec.y == -6.5);
	assert(cmp(vec.z,-33.46));
}

auto Vector3Test::TestOperatorMinus() -> void
{
	Vector3 vec = Vector3(10, -8, 32.54);
	Vector3 vec1 = Vector3(-5, 1.5, -66);
	Vector3 res = vec - vec1;
	assert(res.x == 15);
	assert(cmp(res.y,-9.5));
	assert(cmp(res.z,98.54));
}

auto Vector3Test::TestOperatorAffectMinus() -> void
{
	Vector3 vec = Vector3(10, -8, 32.54);
	Vector3 vec1 = Vector3(-5, 1.5, -66);
	vec -= vec1;
	assert(vec.x == 15);
	assert(vec.y == -9.5);
	assert(cmp(vec.z,98.54));
}

auto Vector3Test::TestOperatorEquals() -> void
{
	Vector3 vec1 = Vector3(10, 8, 56);
	Vector3 vec2 = Vector3(10, 8, 56);
	Vector3 vec3 = Vector3(98, 584, 69);
	assert(vec1 == vec2);
	assert(!(vec1 == vec3));
}

auto Vector3Test::TestOperatorNotEquals() -> void
{
	Vector3 vec1 = Vector3(10, 8, 56);
	Vector3 vec2 = Vector3(10, 8, 56);
	Vector3 vec3 = Vector3(98, 584, 69);
	assert(vec1 != vec3);
	assert(!(vec1 != vec2));
}
