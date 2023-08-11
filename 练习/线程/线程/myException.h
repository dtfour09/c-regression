#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace myException {

	void myExceptionFunction1()
	{
		throw "抛出异常";
	}

	void myFunctionCs(void (*fun)())
	{
		fun();
	}


	void myExceptionMenu()
	{
		while (true)
		{
			int num;
			cerr << "1,抛出异常 .  2,函数指针  . 0,退出.";
			cerr << "请输入一个数字:";
			cin >> num;

			if (num == 1)
			{
				try {
					myExceptionFunction1();
				}
				catch (const char* msg) {
					cout << msg << endl;
				}

			}

			if (num == 2)
			{
				try {
					myFunctionCs(myExceptionFunction1);
				}
				catch (const char* msg) {
					cout << msg << endl;
				}
				
			}

			if (num == 0)
			{
				break;
			}
		}
	}
}