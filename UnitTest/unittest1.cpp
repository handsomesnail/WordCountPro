#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern void ReadAndCount(string fileName);
extern map<string, int> wordMap;
void PrintMap();

extern string CmdInput(int argc, char *argv[], int* code);

extern string OpenAFile();
extern bool IsSplitSymbol(char c);

extern bool Compare(pair<string, int> p1, pair<string, int> p2);
extern void Output();

namespace UnitTest
{		

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1_1)
		{
			ReadAndCount("data1.txt");
			Output();
			//PrintMap();
		}
		TEST_METHOD(TestMethod1_2)
		{
			ReadAndCount("data2.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_3)
		{
			ReadAndCount("data3.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_4)
		{
			ReadAndCount("data4.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_5)
		{
			ReadAndCount("data5.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_6)
		{
			ReadAndCount("data6.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_7)
		{
			ReadAndCount("data7.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_8)
		{
			ReadAndCount("data8.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_9)
		{
			ReadAndCount("data9.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_10)
		{
			ReadAndCount("data10.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_11)
		{
			ReadAndCount("data11.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_12)
		{
			ReadAndCount("data12.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_13)
		{
			ReadAndCount("data13.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_14)
		{
			ReadAndCount("data14.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_15)
		{
			ReadAndCount("data15.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_16)
		{
			ReadAndCount("data16.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_17)
		{
			ReadAndCount("data17.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_18)
		{
			ReadAndCount("data18.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_19)
		{
			ReadAndCount("data19.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod1_20)
		{
			ReadAndCount("data20.txt");
			PrintMap();
		}
		TEST_METHOD(TestMethod2_1)//测试缺少参数
		{
			int argc = 1, code = 0;
			char *argv[] = {"wcPro.exe" };
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(-1, code);
		}

		TEST_METHOD(TestMethod2_2)//测试参数错误
		{
			int argc = 2, code = 0;
			char *argv[] = { "wcPro.exe", "-a" };
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(-2, code);
		}

		TEST_METHOD(TestMethod2_3)//测试参数过多
		{
			int argc = 3, code = 0;
			char *argv[] = { "wcPro.exe", "-a", "test.txt"};
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(-1, code);
		}

		TEST_METHOD(TestMethod2_4)//测试正确参数
		{
			int argc = 2, code = 0;
			char *argv[] = { "wcPro.exe", "test.txt" };
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(0, code);
			Assert::AreEqual<int>(0, strcmp("test.txt", res.c_str()));
		}

		TEST_METHOD(TestMethod2_5)//测试文件名错误
		{
			int argc = 2, code = 0;
			char *argv[] = { "wcPro.exe", "test.c" };
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(-2, code);
		}

		TEST_METHOD(TestMethod2_6)//测试-x
		{
			int argc = 2, code = 0;
			char *argv[] = { "wcPro.exe", "-x" };//选择D:\wordCount\test.txt
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(0, code);
			Assert::AreEqual<int>(0, strcmp("D:\wordCount\test.txt", res.c_str()));
		}

		TEST_METHOD(TestMethod2_7)//测试-x与文件名同时输入
		{
			int argc = 3, code = 0;
			char *argv[] = { "wcPro.exe", "-x", "test.txt"};
			string res = CmdInput(argc, argv, &code);
			Assert::AreEqual<int>(-1, code);
		}


		TEST_METHOD(TestMethod3_1)
		{
			string path = OpenAFile();
			Logger::WriteMessage(path.c_str());
		}

		TEST_METHOD(TestMethod3_2)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('-'), true);
		}
		TEST_METHOD(TestMethod3_3)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('!'), true);
		}
		TEST_METHOD(TestMethod3_4)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('@'), true);
		}
		TEST_METHOD(TestMethod3_5)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('$'), true);
		}
		TEST_METHOD(TestMethod3_6)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('%'), true);
		}
		TEST_METHOD(TestMethod3_7)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('^'), true);
		}
		TEST_METHOD(TestMethod3_8)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('&'), true);
		}
		TEST_METHOD(TestMethod3_9)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('*'), true);
		}
		TEST_METHOD(TestMethod3_10)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('('), true);
		}
		TEST_METHOD(TestMethod3_11)
		{
			Assert::AreEqual<bool>(IsSplitSymbol(')'), true);
		}

		TEST_METHOD(TestMethod3_12)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('-'), true);
		}
		TEST_METHOD(TestMethod3_13)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('+'), true);
		}
		TEST_METHOD(TestMethod3_14)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('='), true);
		}
		TEST_METHOD(TestMethod3_15)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('['), true);
		}
		TEST_METHOD(TestMethod3_16)
		{
			Assert::AreEqual<bool>(IsSplitSymbol(']'), true);
		}
		TEST_METHOD(TestMethod3_17)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('{'), true);
		}
		TEST_METHOD(TestMethod3_18)
		{
			Assert::AreEqual<bool>(IsSplitSymbol('}'), true);
		}
		TEST_METHOD(TestMethod3_19)
		{
			Assert::AreEqual<bool>(IsSplitSymbol(';'), true);
		}
		TEST_METHOD(TestMethod3_20)
		{
			Assert::AreEqual<bool>(IsSplitSymbol(':'), true);
		}

		TEST_METHOD(TestMethod4_1)
		{
			Output();//正常
		}
		TEST_METHOD(TestMethod4_2)
		{
			Output();//超过100个
		}
		TEST_METHOD(TestMethod4_3)
		{
			Assert::AreEqual<bool>(Compare(pair<string, int>("abc", 3), pair<string, int>("fhd", 4)), false);
		}
		TEST_METHOD(TestMethod4_4)
		{
			Assert::AreEqual<bool>(Compare(pair<string, int>("abc", 3), pair<string, int>("abc", 3)), false);
		}
		TEST_METHOD(TestMethod4_5)
		{
			Assert::AreEqual<bool>(Compare(pair<string, int>("abc", 3), pair<string, int>("ab", 3)), false);
		}
		TEST_METHOD(TestMethod4_6)
		{
			Assert::AreEqual<bool>(Compare(pair<string, int>("abc", 3), pair<string, int>("abcd", 3)), true);
		}
		TEST_METHOD(TestMethod4_7)
		{
			Assert::AreEqual<bool>(Compare(pair<string, int>("abc", 3), pair<string, int>("abd", 3)), true);
		}


	};

}

void PrintMap() {
	map<string, int>::iterator it;
	it = wordMap.begin();
	while (it != wordMap.end()) {
		Logger::WriteMessage((it->first + " "+to_string(it->second)+"\n").c_str());
		it++;
	}
}