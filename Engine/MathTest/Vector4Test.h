#pragma once

#include "../Math/Maths.h"
#include "../Math/Vector4.h"

namespace math
{
	class Vector4Test
	{
		public:
			Vector4Test() = default;
			~Vector4Test() = default;

			auto StartTest()	-> void;

		private:
			auto TestConstructor()	->	void;
			auto TestOperatorEquals()	-> void;
			auto TestOperatorNotEquals()	->void;
			auto TestOperatorAdd()	->void;
			auto TestOperatorLess()	->void;
			auto TestOperatorAffect()	->void;
			auto TestOperatorPlusEquals()	->void;
			auto TestOperatorMinusEquals()	->void;
			auto TestSize()	->void;
			auto TestNormalise()	->void;
			auto TestDot()	->void;
			auto TestScale()	->void;
	};

}


