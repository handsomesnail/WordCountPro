#include "stdafx.h"
#include "CppUnitTest.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern int main(int argc, char *argv[]);
namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod2_1)//测试缺少参数
		{
			int argc = 1;
			char *argv[] = {"wcPro.exe" };
			int res = main(argc, argv);
			Assert::AreEqual<int>(-1, res);
		}

		TEST_METHOD(TestMethod2_2)//测试参数错误
		{
			int argc = 2;
			char *argv[] = { "wcPro.exe", "-a" };
			int res = main(argc, argv);
			Assert::AreEqual<int>(-2, res);
		}

		TEST_METHOD(TestMethod2_3)//测试参数过多
		{
			int argc = 3;
			char *argv[] = { "wcPro.exe", "-a", "test.txt"};
			int res = main(argc, argv);
			Assert::AreEqual<int>(-1, res);
		}

		TEST_METHOD(TestMethod2_4)//测试正确参数
		{
			int argc = 2;
			char *argv[] = { "wcPro.exe", "test.txt" };
			int res = main(argc, argv);
			Assert::AreEqual<int>(0, res);
		}

		TEST_METHOD(TestMethod2_5)//测试文件名错误
		{
			int argc = 2;
			char *argv[] = { "wcPro.exe", "test.c" };
			int res = main(argc, argv);
			Assert::AreEqual<int>(-2, res);
		}

		TEST_METHOD(TestMethod2_6)//测试-x
		{
			int argc = 2;
			char *argv[] = { "wcPro.exe", "-x" };
			int res = main(argc, argv);
			Assert::AreEqual<int>(-3, res);
		}

		TEST_METHOD(TestMethod2_7)//测试-x与文件名同时输入
		{
			int argc = 3;
			char *argv[] = { "wcPro.exe", "-x", "test.txt"};
			int res = main(argc, argv);
			Assert::AreEqual<int>(-1, res);
		}
	};
}