#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <map>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern void ReadAndCount(string fileName);
extern map<string, int> wordMap;
void PrintMap();

namespace UnitTest
{		

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1_1)
		{
			ReadAndCount("data1.txt");
			PrintMap();
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