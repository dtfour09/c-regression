#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "useCTime.h"
#include "myStream.h"
#include "myException.h"
#include "myThread.h"
#include <stdlib.h>

using namespace std;

void function()
{
	myTime myT;
	cin >> myT;
	cout << myT << endl;
	Sleep(1000);
}

void function2()
{
	myStream mSt;
	int num;
	while (1)
	{
		cout << "������һ�����֣�1��д��һ�����ݡ�2����ѯ���ݡ�3����ѯȫ�����ݡ�0���˳���\n";
		cin >> num;
		if (num == 1)
		{
			cin >> mSt;
		}

		if (num == 2)
		{
			string str;
			cin >> str;
			cout << mSt.findString(str) << endl;
		}

		if (num == 3)
		{
			mSt.findAllString();
		}

		if (num == 0)
		{
			break;
		}
	}
}

void function3()
{
	myException::myExceptionMenu();
}

void funtion4()
{
	threadMenu();
}

void menu()
{
	system("cls");
	cerr << "                    ";
	cerr << "-------------------\n";
	cerr << "                    ";
	cerr << "|1 : i/o���ز��ԡ�|\n";
	cerr << "                    ";
	cerr << "|2 : ��װ��д��   |\n";
	cerr << "                    ";
	cerr << "|3 : �쳣�׳���   |\n";
	cerr << "                    ";
	cerr << "|4 : ���̡߳�     |\n";
	cerr << "                    ";
	cerr << "-------------------\n";
	cerr << "                       *     \n";
	cerr << "                      ***     \n";
	cerr << "                     *****     \n";
	cerr << "                      ***     \n";
	cerr << "                       *  \n";
#ifdef _WIN32
	cerr << "ϵͳ��window \n";
#endif // __WIN32__

}

int main()
{
	//vector<int> v{1,2,3,4,5,6,7,8,9,10};
	//for (auto &i : v)
	//{
	//	cout << i << endl;
	//}
	//cout << R"(\1\1\1\1\n)" << endl;


	Sleep(2000);
	while (true)
	{
		menu();
		cerr << "������һ�����֣�";
		int num;
		cin >> num;

		if (num == 1)
		{
			function();
		}

		if (num == 2)
		{
			function2();
		}

		if (num == 3)
		{
			function3();
		}

		if (num == 4)
		{
			funtion4();
		}
	}
	return 0;
}