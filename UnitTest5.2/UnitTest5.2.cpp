#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05.2/Lab_05.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:

		TEST_METHOD(TestS)
		{
			double x = 1.2;
			double eps = 0.0001;
			int n;
			double s;
			S(x, eps, n, s);
			Assert::AreEqual(atan(x), s, eps);
		}

		TEST_METHOD(TestA)
		{
			double x = 1.2;
			int n = 3;
			double a = x;
			A(x, n, a);
			Assert::AreEqual(-x * x * (2 * n - 1) / (2 * n + 1) * x, a);
		}
	};
}
