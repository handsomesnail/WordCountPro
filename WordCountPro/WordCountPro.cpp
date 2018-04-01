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
#include <vector>

using namespace std;

static set<char> splitSymbolsSet;//记录分隔符
map<string, int> wordMap;//记录单词-个数
static string tempWord = "";//临时存储单词 ,'…'
static char splitSymbolsArray[43] = { '-', ' ','~','`','!','#','%','^','&','*','(',')', '_','[',']','+','=',':',';','\"','\'','|','<','>',',','.','/','?','\r','\n','\0','\t','0','1', '2', '3', '4', '5', '6', '7', '8', '9', };
bool Compare(pair<string, int> p1, pair<string, int> p2);
void AddWord();
bool IsSplitSymbol(char c);
void ReadAndCount(string fileName);
void Output();
string OpenAFile();
string CmdInput(int argc, char *argv[], int* code);

int main(int argc, char *argv[])
{
	int code = 0;
	string path = CmdInput(argc, argv, &code);
	if (code != 0)
		return -1;
	ReadAndCount(path);
	Output();
	return 0;
}

//读取命令行参数
string CmdInput(int argc, char *argv[], int* code)
{
	string path = "";
	if (argc != 2) {
		cout << "Please input correct parameter." << endl;
		*code = -1;
		return path;
	}
	if (strcmp(argv[1], "-x") == 0) {
		path = OpenAFile();
		if (path == "")
			*code = -3;
		return path;
	}
	else {
		path = argv[1];
		int fileNamelength = strlen(argv[1]);
		if (strcmp(argv[1] + fileNamelength - 3, "txt") != 0) {
			cout << "Please input correct parameter." << endl;
			*code = -2;
		}
	}
	return path;
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

string OpenAFile() {
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = _T("Txt(*.txt)\0*.txt\0\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	// 显示打开选择文件对话框。
	if (GetOpenFileName(&ofn)) {
		//路径转化为string
		int iLen = WideCharToMultiByte(CP_ACP, 0, szFile, -1, NULL, 0, NULL, NULL);
		char* chRtn = new char[iLen * sizeof(char)];
		WideCharToMultiByte(CP_ACP, 0, szFile, -1, chRtn, iLen, NULL, NULL);
		string str(chRtn);
		delete[] chRtn;
		return str;
	}
	else {
		return "";
	}
}

//输出结果到result.txt
void Output() {
	vector<pair<string, int>> tempVector(wordMap.begin(), wordMap.end());//哈希表转存到动态数组
	sort(tempVector.begin(), tempVector.end(), Compare);//根据value和key排序

	ofstream outfs("result.txt");
	if (outfs.is_open()) {
		for (int i = 0; i < tempVector.size(); i++) {
			if (i >= 100)
				break;

			outfs << tempVector[i].first + " " << tempVector[i].second;
			//cout << tempVector[i].first + " " << tempVector[i].second << endl;
			if (i != 99 && i != tempVector.size() - 1)
				outfs << endl;
		}
	}
	outfs.close();

}

//传入排序的比较方法
bool Compare(pair<string, int> p1, pair<string, int> p2) {
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else return p1.first < p2.first;
}
