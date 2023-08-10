#include<iostream>
using namespace std;

#define num 365*24*60*60  
#define ping(a) a*a

#define isTrue false


int main()
{
	int num1 = 1, num2 = 2;

#if isTrue
	int num3 = num1;
	num1 = num2;
	num2 = num3;
	cout << num1 << " " << num2 << " " << ping(num1) << endl;

#else 
	cout << num1 << " " << num2 << endl;
#endif
	return 0;
}