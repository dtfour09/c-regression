#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char* chuliA(char* str1, char* str2)
{
	int num1 = 0, num2 = 0;
	
	num1 = strlen(str1);
	num2 = strlen(str2);

	cout << num1 << " " << num2 << endl;

	int ans = 0;
	for (int i = 0; i < num1; ++i)
	{
		for (int j = 0; j < num2; ++j)
		{
			if (*(str1 + i + j) != *(str2 + j))
			{
				break;
			}
			if (j == num2 - 1)
			{
				ans = i;
				break;
			}
		}
	}
	return str1 + ans;
}

int main()
{
	char str1[] = "12345";
	char str2[] = "1234";
	chuliA(str1, str2);

}
