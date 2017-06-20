#pragma once

#include "../Math/Vector2.h"

namespace math
{
	class Vector2Test
	{
	public:
		Vector2Test() = default;
		~Vector2Test() = default;

		auto StartTest()->void;
	private:
		auto TestConstructeur()->void;
		auto TestOperatorEquals()->void;
		auto TestOperatorNotEquals()->void;
		auto TestOperatorAdd()->void;
		auto TestOperatorLess()->void;
		auto TestOperatorAffect()->void;
		auto TestOperatorPlusEquals()->void;
		auto TestOperatorMinusEquals()->void;
		auto TestSize()->void;
		auto TestNormalise()->void;
		auto TestDot()->void;
		auto TestScale()->void;
	};
}



