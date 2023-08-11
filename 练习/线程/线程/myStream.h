#pragma once
#define _CRT_SECURE_NO_WARNRINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string fileName = "./data.txt";

class myStream {
public:
	myStream();
	~myStream();
	friend istream& operator>>(istream& input, myStream &mySt);
	//friend ostream& operator<<(ostream& output,myStream &mySt);
	int findString(string s);
	void findAllString();
private:
	fstream myInput,myOutput;
};



myStream::myStream()
{
	myOutput.open(fileName.c_str(), ios::app | ios::out | ios::in);
	myInput.open(fileName.c_str(),ios::in);
	
	if (!myInput.is_open())
	{
		cerr << "input ��ʧ��" << endl;
	}

	if (!myOutput.is_open())
	{
		cerr << "output ��ʧ��" << endl;
	}
}

istream& operator>>(istream& input, myStream &mySt)
{
	cerr << "������һ����Ҫд���ļ�������:";
	string s;
	input >> s;
	mySt.myOutput << s << "\n";
	if (mySt.myOutput.good())
	{
		cerr << "д��ɹ�\n";
	}
	//mySt.myInput.flush();
	mySt.myOutput.sync();
	return input;
}

int myStream::findString(string s)
{
	int num = 0;
	string str;

	myInput.clear();
	myInput.seekg(0, ios::beg);
	while (getline(myInput, str))
	{
		num++;
		cout << (str == s) << " " << str << " " << s << endl;
		if (str == s)
		{
			return num;
		}		
	}
	return -1;
}

void myStream::findAllString()
{
	myInput.clear();
	myInput.seekg(0, ios::beg);
	string str;
	while (getline(myInput, str))
	{
		cerr << str << endl;
	}
}

myStream::~myStream()
{
	myInput.close();
	myOutput.close();
}