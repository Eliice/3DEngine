// MathTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector2Test.h"
#include "Vector3Test.h"
#include "Vector4Test.h"
#include "Mat4Test.h"


#if _WIN32
#pragma comment (lib,"Math.lib")
#endif


int main()
{
	Vector2Test* testVector2 = new Vector2Test();
	testVector2->StartTest();

	Vector3Test* testVector3 = new Vector3Test();
	testVector3->TestAll();

	Vector4Test* testVector4 = new Vector4Test();
	testVector4->StartTest();

	Mat4Test* testMat4 = new Mat4Test();
	testMat4->StartTest();

    return 0;
}

