#define _CRT_SECURE_NO_WARNING_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

const char* fileName = "./signal.txt";
const char* myFileName = "./signal_temp.txt";


// copy �ļ� �ļ�1 copy���ļ�2
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

//�޸��ļ�
void modifyLine(const char *fileName1,const char *fileName2,int line,string newText)
{
	// ֻ��copy�ļ�
	fstream fileRead(fileName1, ios::out | ios::in);

	// ��׷�ӵ���ʽ��copy���ļ�
	fstream fileWrite(fileName2, ios::out | ios::trunc); 

	if (!fileRead || !fileWrite) {
		cerr << "modify line failed to open file" << endl;
	}

	// ������
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
		//���ж�ȡ�����Ұ��з��뵽�µ��ļ�����
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

//ɾ���ļ�
void deleteLine(const char* fileName1, const char* fileName2, int line)
{
	// ֻ��copy�ļ�
	fstream fileRead(fileName1, ios::out | ios::in);

	// ��׷�ӵ���ʽ��copy���ļ�
	fstream fileWrite(fileName2, ios::out | ios::trunc); 

	if (!fileRead || !fileWrite) {
		cerr << "delete line failed to open file" << endl;
	}

	// ������
	string buffer;

	int nums = 0;

	while (getline(fileRead, buffer))
	{
		nums++;
		if (nums == line)
			continue;

		//���ж�ȡ�����Ұ��з��뵽�µ��ļ�����
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

// ����
void insertLine(const char* fileName1, const char* fileName2, int line, string newText)
{
	// ֻ��copy�ļ�
	fstream fileRead(fileName1, ios::out | ios::in);

	// ��׷�ӵ���ʽ��copy���ļ�
	fstream fileWrite(fileName2, ios::out | ios::trunc); 

	if (!fileRead || !fileWrite) {
		cerr << "insert line failed to open file" << endl;
	}

	int nums = 0;
	// ������
	string buffer;

	while (getline(fileRead, buffer))
	{
		nums++;
		if (nums == line)
		{
			fileWrite << newText << '\n';
		}
		//���ж�ȡ�����Ұ��з��뵽�µ��ļ�����
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

//�鿴
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
	// copy�ļ�;
	copyFile(fileName,myFileName);

	int nums;
	while (true)
	{
		cout << "����������ѡ��1�����룬2��ɾ����3���޸ģ�4���鿴��5���˳���\n";
		cin >> nums;

		if (nums == 1)
		{
			string s;
			int line;
			cout << "��ѡ���У�";
			cin >> line;
			cout << "�����������:";
			cin >> s;
			insertLine(fileName, myFileName, line, s);
			copyFile(myFileName,fileName);
		}

		if (nums == 2)
		{
			string s;
			int line;
			cout << "��ѡ��ɾ���У�";
			cin >> line;
			deleteLine(fileName, myFileName, line);
		}

		if (nums == 3)
		{
			string s;
			int line;
			cout << "��ѡ���У�";
			cin >> line;
			cout << "�����޸�����:";
			cin >> s;
			modifyLine(fileName, myFileName, line, s);
		}

		if (nums == 4)
		{
			string s;
			int line;
			cout << "��ѡ���У�";
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
