#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if (str2.find(str1))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	cout << str1 << "\n" << str2 << endl;

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < str1.length(); ++i)
	{
		if (str1[0] == str1[i]) ans1++;
	}
	
	for (int i = 0; i < str2.length(); ++i)
	{
		if (str2[0] == str2[i]) ans2++;
	}

	cout << "ans1 : " << ans1 << "   ans2 : " << ans2 << endl;

	return 0;
}
