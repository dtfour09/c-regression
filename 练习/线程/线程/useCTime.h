#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

class myTime {
public:
	myTime();
	friend ostream& operator<<(ostream& output, const myTime& myT)
	{
		output << "年：" << myT.myTm.tm_year + 1970
			<< " 月：" << myT.myTm.tm_mon + 1
			<< " 日：" << myT.myTm.tm_mday  + 1<< endl;
		return output;
	}
	friend istream& operator>>(istream &input,myTime &myT)
	{
		cerr << "请输入 年 月 日\n";
		myTime li;
		input >> li.myTm.tm_year  >> li.myTm.tm_mon >> li.myTm.tm_mday;
		myT.myTm.tm_year = li.myTm.tm_year - 1970;
		myT.myTm.tm_mon = li.myTm.tm_mon - 1;
		myT.myTm.tm_mday = li.myTm.tm_mday - 1;
		return input;
	}
private:
	tm myTm;
};

myTime::myTime()
{
	//默认1970年
	myTm.tm_sec = 0;
	myTm.tm_hour = 0;
	myTm.tm_min = 0;
	myTm.tm_mday = 0;
	myTm.tm_year = 0;
	myTm.tm_mon = 0;
}