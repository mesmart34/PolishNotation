#include "pch.h"
#include "CppUnitTest.h"
#include "../PolishFormula/PolishNotation.h"
#include "../PolishFormula/PolishNotation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolishNotationTests
{
	TEST_CLASS(PolishNotationTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("2 + 5");
			auto expected = "2 5 +";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod2)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("2 - 5");
			auto expected = "2 5 -";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod3)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("(2 + 5) / 2");
			auto expected = "2 5 + 2 /";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod4)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("5 * (2 + 5) / 2");
			auto expected = "5 2 5 + * 2 /";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod5)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("f = 5 * (2 + 5) / 2");
			auto expected = "f 5 2 5 + * 2 / =";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod6)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("f = D(5 * (2 + 5) / 2) / 2");
			auto expected = "f 5 2 5 + * 2 / D 2 / =";
			Assert::IsTrue(actual == expected);
		}
		TEST_METHOD(TestMethod7)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("f = F(5 / 10) * D(5 * (2 + 5) / 2) / 2");
			auto expected = "f 5 1 0 / F 5 2 5 + * 2 / D * 2 / =";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod8)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("x = (256 * 1024) / 8");
			auto expected = "x 2 5 6 1 0 2 4 * 8 / =";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod9)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("x + y = y + 10");
			auto expected = "x y + y 1 0 + =";
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod10)
		{
			PolishNotation pn = PolishNotation();
			auto actual = pn.Convert("x * x + y + 5 = 25");
			auto expected = "x x * y + 5 + 2 5 =";
			Assert::IsTrue(actual == expected);
		}
	};
}
