#pragma once

#include "../Math/Maths.h"
#include "../Math/Vector3.h"

using namespace math;

class Vector3Test
{
public:
	Vector3Test()=default;
	~Vector3Test()=default;

	auto TestAll()->void;
private:
	auto TestConstructeur()->void;
	auto TestCross()->void;
	auto TestDot()->void;
	auto TestLength()->void;
	auto TestDistance()->void;
	auto TestNormalize()->void;
	auto TestSetAbsolute()->void;

	auto TestVector3ToVector4()-> void;

	auto TestOperatorProduct()->void;
	auto TestOperatorAffectProduct()->void;
	auto TestOperatorDivided()->void;
	auto TestOperatorAffectDivided()->void;
	auto TestOperatorAdd()->void;
	auto TestOperatorAffectAdd()->void;
	auto TestOperatorMinus()->void;
	auto TestOperatorAffectMinus()->void;
	auto TestOperatorEquals()->void;
	auto TestOperatorNotEquals()->void;
};

