#pragma once

#include "../Math//Maths.h"
#include "../Math/Mat4.h"
#include "../Math/Vector3.h"
#include <cassert>

namespace math
{
	class Mat4Test
	{
		public:
			Mat4Test()	= default;
			~Mat4Test()	= default;

			auto StartTest()	-> void;
		private:
			auto TestConstructor()	-> void;
			auto TestTranslate()	-> void;
			auto TestScale()	-> void;
			auto TestRotateX()	-> void;
			auto TestRotateY()	-> void;
			auto TestRotateZ()	-> void;
			auto TestProjectionMatrix()	-> void;
			auto TestInverse()	-> void;
			auto TestOperatorProductMat4()	-> void;
			auto TestOperatorProductVector3()	-> void;
			auto TestOperatorAddMat4()	-> void;
			
	};
}



