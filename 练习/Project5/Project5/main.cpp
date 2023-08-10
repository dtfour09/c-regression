#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "templateClass.h"
using namespace std;



int main()
{
	cout << MaxSize('a', 'b') << endl;

	Stack<string> st;
	for (int i = 0; i < 10; ++i)
	{
		string s = to_string(i * 100);
		st.push(s);
		cout << st.top() << endl;
		cout << "当前行数： " << __LINE__ << endl;
	}
	return 0;
}