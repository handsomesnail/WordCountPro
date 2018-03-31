// WordCountPro.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <windows.h>  
#include <commdlg.h> 

using namespace std;


static set<char> splitSymbolsSet;//记录分隔符
map<string, int> wordMap;//记录单词-个数
static string tempWord = "";//临时存储单词
static char splitSymbolsArray[43] = { '-', ' ','~','`','!','#','%','^','&','*','(',')', '_','…','[',']','+','=',':',';','\"','\'','|','<','>',',','.','/','?','\r','\n','\0','\t',
'0','1', '2', '3', '4', '5', '6', '7', '8', '9', };

bool Compare(pair<string, int> p1, pair<string, int> p2);
void AddWord();
bool IsSplitSymbol(char c);
void ReadAndCount(string fileName);
void Output();
string OpenAFile();

int main(int argc, char *argv[])
{
    return 0;
}

//读取文件并计数
void ReadAndCount(string fileName) {
	splitSymbolsSet.insert(splitSymbolsArray, splitSymbolsArray + 43);
	ifstream fin;
	string tempInput;//存储输入

	fin.open(fileName);
	while (fin >> tempInput) {
		for (int i = 0; i < tempInput.length(); i++) {
			if (tempInput[i] == '-') {
				if (i > 0 && i < tempInput.length() - 1 && !IsSplitSymbol(tempInput[i - 1]) && !IsSplitSymbol(tempInput[i + 1])) {
					tempWord += tolower(tempInput[i]);
				}
			}
			else if (!IsSplitSymbol(tempInput[i])) {
				tempWord += tolower(tempInput[i]);
			}
			else AddWord();
		}
		AddWord();
	}
	fin.close();
}

//将tempWord传入单词表
inline void AddWord() {
	if (tempWord == "")
		return;

	if (wordMap.find(tempWord) != wordMap.end()) {
		wordMap[tempWord]++;
	}
	else wordMap.insert(pair<string, int>(tempWord, 1));
	tempWord.clear();
}

//返回是否是分隔符
inline bool IsSplitSymbol(char c) {
	if (splitSymbolsSet.find(c) != splitSymbolsSet.end())
		return true;
	return false;
}

