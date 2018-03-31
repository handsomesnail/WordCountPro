﻿// WordCountPro.cpp: 定义控制台应用程序的入口点。
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
static map<string, int> wordMap;//记录单词-个数
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
