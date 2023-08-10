#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void chuliA(char *str)
{
	int len = strlen(str);
	int l = 0, r = len - 1;
	if (*(str + 0) == '-') l++;
	while (*(str + r) == '0')
	{
		r--;
	}
	while (l < r)
	{
		swap(*(str + l),*(str + r));
		r--;
		l++;
	}
}

int main()
{
	char str[101];
	cin >> str;
	chuliA(str);
	cout << str << endl;
}
