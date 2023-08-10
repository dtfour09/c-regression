#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void zhichuan(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "function zhi chuan  a == " << a << " b== " << b << endl;
}

void zhizhen(int *a,int *b)
{
	int tmep = *a;
	*a = *b;
	*b = tmep;
}

void yinyong(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 100, b = 200;
	zhichuan(a,b);  //值传递并不会改变实参的值。只是在函数内部copy了一变量到里面过去了。
	cout << "main zhi chuan a == " << a << " b== " << b << endl;

	zhizhen(&a, &b); //指针传递传过去的是指向同一块内存的指针，对地址内的变量进行了修改。
	cout << "main zhi zhen a == " << a << " b == " << b << endl;
	
	yinyong(a,b); //引用则是相当于起了别名，实际上公用同一块内存地址。
	cout << "main yin yong a == " << a << " b == " << b << endl;

	return 0;
}
