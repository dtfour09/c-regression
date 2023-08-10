#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	time_t now = time(0);
	tm * nowTime = gmtime(&now);

	tm oldTime;
	oldTime.tm_year = 100;
	oldTime.tm_mon = 0;
	oldTime.tm_mday = 0;
	oldTime.tm_hour = 0;
	oldTime.tm_min = 0;
	oldTime.tm_sec = 0;
	long long num = difftime(mktime(nowTime), mktime(&oldTime));
	cout << num << endl;
}