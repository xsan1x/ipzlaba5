#include "pch.h"
#include "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\UnitTest\include\CppUnitTest.h"
#include "C:\Users\ilkin\source\repos\IPZ3\IPZ3\IPZ3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(check_Valid_Params_Get_Minus3_3_1_4_And_exceptionNotThrown)
		{
			double x = -3;
			double b = 3;
			double h = 1;
			double n = 4;
			try {
				check_Valid_Params(x, b, h, n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(check_Valid_Params_Get_3_minus3_1_4_And_exceptionNotThrown)
		{
			double x = 3;
			double b = -3;
			double h = 1;
			double n = 4;
			try {
				check_Valid_Params(x, b, h, n);
				Assert::IsTrue(false);
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(calculate_get_minus2_3_minus120_return)
		{
			double x = -2;
			double n = 4;
			double excepted_y = -120;
			double real = calculate(x, n);
			Assert::AreEqual(excepted_y, real);
		}
		TEST_METHOD(calculate_get_minus3_4_minus840_return)
		{
			double x = -3;
			double n = 4;
			double excepted_y = -840;
			double real = calculate(x, n);
			Assert::AreEqual(excepted_y, real);
		}
		TEST_METHOD(wrong)
		{
			double x = -3;
			double n = 4;
			double excepted_y = 218;
			double real = calculate(x, n);
			Assert::AreEqual(excepted_y, real);
		}
	};
}