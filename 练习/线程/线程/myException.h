#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace myException {

	void myExceptionFunction1()
	{
		throw "�׳��쳣";
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
			cerr << "1,�׳��쳣 .  2,����ָ��  . 0,�˳�.";
			cerr << "������һ������:";
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