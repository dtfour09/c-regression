#define _CRT_SECURE_NO_WARNING_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

const char* fileName = "./signal.txt";
const char* myFileName = "./signal_temp.txt";


// copy 文件 文件1 copy到文件2
void copyFile(const char *fileName1,const char *fileName2)
{

	const char* sourceFilename = fileName1;
	const char* targetFilename = fileName2;

	fstream sourceFile(sourceFilename,ios::out | ios::in |ios::app);

	if (!sourceFile.is_open()) {
		cout << "Failed to open source file" << endl;
	}

	fstream targetFile(targetFilename, ios::out| ios::in | ios::trunc);
	if (!targetFile.is_open()) {
		cout << "Failed to open target file" << endl;
		sourceFile.close(); 
	}

	string line;
	while (getline(sourceFile, line)) {
		targetFile << line << endl;
	}

	if (sourceFile.is_open())
	{
		sourceFile.close();
		sourceFile.clear();
	}

	if (targetFile.is_open())
	{
		targetFile.close();
		targetFile.clear();
	}

}

//修改文件
void modifyLine(const char *fileName1,const char *fileName2,int line,string newText)
{
	// 只读copy文件
	fstream fileRead(fileName1, ios::out | ios::in);

	// 已追加的形式打开copy的文件
	fstream fileWrite(fileName2, ios::out | ios::trunc); 

	if (!fileRead || !fileWrite) {
		cerr << "modify line failed to open file" << endl;
	}

	// 缓冲区
	string buffer;

	int nums = 0;

	while (getline(fileRead, buffer))
	{
		nums++;
		if (nums == line)
		{
			fileWrite << newText << '\n';
			continue;
		}
		//按行读取，并且按行放入到新的文件中区
		fileWrite << buffer << '\n';
	}

	if (fileRead.is_open())
	{
		fileRead.close();
		fileRead.clear();
	}

	if (fileWrite.is_open())
	{
		fileWrite.close();
		fileWrite.clear();
	}

}

//删除文件
void deleteLine(const char* fileName1, const char* fileName2, int line)
{
	// 只读copy文件
	fstream fileRead(fileName1, ios::out | ios::in);

	// 已追加的形式打开copy的文件
	fstream fileWrite(fileName2, ios::out | ios::trunc); 

	if (!fileRead || !fileWrite) {
		cerr << "delete line failed to open file" << endl;
	}

	// 缓冲区
	string buffer;

	int nums = 0;

	while (getline(fileRead, buffer))
	{
		nums++;
		if (nums == line)
			continue;

		//按行读取，并且按行放入到新的文件中区
		fileWrite << buffer << '\n';
	}

	if (fileRead.is_open())
	{
		fileRead.close();
		fileRead.clear();
	}

	if (fileWrite.is_open())
	{
		fileWrite.close();
		fileWrite.clear();
	}

}

// 插入
void insertLine(const char* fileName1, const char* fileName2, int line, string newText)
{
	// 只读copy文件
	fstream fileRead(fileName1, ios::out | ios::in);

	// 已追加的形式打开copy的文件
	fstream fileWrite(fileName2, ios::out | ios::trunc); 

	if (!fileRead || !fileWrite) {
		cerr << "insert line failed to open file" << endl;
	}

	int nums = 0;
	// 缓冲区
	string buffer;

	while (getline(fileRead, buffer))
	{
		nums++;
		if (nums == line)
		{
			fileWrite << newText << '\n';
		}
		//按行读取，并且按行放入到新的文件中区
		fileWrite << buffer << '\n';
	}

	if (fileRead.is_open())
	{
		fileRead.close();
		fileRead.clear();
	}
	
	if (fileWrite.is_open())
	{
		fileWrite.close();
		fileWrite.clear();
	}

}

//查看
string chickOut(int line)
{
	int nums = 0;

	fstream fileRead(fileName, ios::out | ios::in);
	string buffer;
	while (getline(fileRead,buffer))
	{
		nums++;
		if (nums == line)
		{
			fileRead.close();
			return buffer;
		}
	}
	if (fileRead.is_open())
	{
		fileRead.close();
	}

	string errorString = "Error Out of range";
	return errorString;
}



int main()
{
	// copy文件;
	copyFile(fileName,myFileName);

	int nums;
	while (true)
	{
		cout << "请输入数字选择：1，插入，2，删除，3，修改，4，查看，5，退出。\n";
		cin >> nums;

		if (nums == 1)
		{
			string s;
			int line;
			cout << "请选择行：";
			cin >> line;
			cout << "输入插入数据:";
			cin >> s;
			insertLine(fileName, myFileName, line, s);
			copyFile(myFileName,fileName);
		}

		if (nums == 2)
		{
			string s;
			int line;
			cout << "请选择删除行：";
			cin >> line;
			deleteLine(fileName, myFileName, line);
		}

		if (nums == 3)
		{
			string s;
			int line;
			cout << "请选择行：";
			cin >> line;
			cout << "输入修改数据:";
			cin >> s;
			modifyLine(fileName, myFileName, line, s);
		}

		if (nums == 4)
		{
			string s;
			int line;
			cout << "请选择行：";
			cin >> line;
			cout << chickOut(line) << endl;
		}

		if (nums == 5)
		{
			break;
		}
	}
	return 0;
}
