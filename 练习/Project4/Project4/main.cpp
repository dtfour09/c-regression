#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
#include<string>
#include<queue>
#include<cstdio>
using namespace std;

string fileName = "./data.txt";

void myFileWrite(string data)
{
	fstream fileWrite;
	fileWrite.open(fileName.c_str(),ios::app);
	if (!fileWrite.is_open())
	{
		cout << "faile open file " << endl;
	}
	fileWrite << data << "\n";
	fileWrite.close();
}

queue<string> myFileRead()
{
	queue<string> ans;
	fstream fileRead;
	fileRead.open(fileName.c_str(),ios::in);
	if (!fileRead.is_open())
	{
		cout << "faile open file " << endl;
	}
	string str;
	while (getline(fileRead,str))
	{
		ans.push(str);
		if (ans.size() > 10)
		{
			ans.pop();
		}
	}
	return ans;
}


int main()
{
	cout << "������һ������ num:\n";

	double num;

	cin >> num;

	while (true)
	{
		cout << "��ѡ�� : 1 �� 2 �� 3 �� 4 �� 5 ȡ���� 6 ƽ�� 7 ���� 8 ���� 9 ��ѯ��¼ 0 �˳�\n";
		int sum;
		double nums;
		cin >> sum;
		if (sum == 1 || sum == 2 || sum == 3 || sum == 4)
		{
			cout << "������һ������:";
			cin >> nums;
		}
		if (sum == 1)
		{
			string s = to_string(num);
			s += " + ";
			s += to_string(nums);
			num += nums;
			s += " = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 2)
		{
			string s = to_string(num);
			s += " - ";
			s += to_string(nums);
			num -= nums;
			s += " = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 3)
		{
			string s = to_string(num);
			s += " * ";
			s += to_string(nums);
			num *= nums;
			s += " = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 4)
		{
			string s = to_string(num);
			s += " / ";
			s += to_string(nums);
			num /= nums;
			s += " = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 5)
		{
			string s = "1";
			s += " / ";
			s += to_string(num);
			num = 1 / num;
			s += " = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 6)
		{
			string s = to_string(num);
			s += " * ";
			s += to_string(num);
			num = num * num;
			s += " = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 7)
		{
			string s = "sqrt num =";
			num = sqrt(num);
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 8)
		{
			num = 0;
			cout << "������num : ";
			cin >> num;
			string s = "num = ";
			s += to_string(num);
			cout << s << endl;
			myFileWrite(s);
		}
		if (sum == 9)
		{
			queue<string> ans = myFileRead();
			while (!ans.empty())
			{
				cout << ans.front() << endl;
				ans.pop();
			}
		}
		if (sum == 0)
		{
			break;
		}

	
	}

}
