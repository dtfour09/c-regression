//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
#include "templateClass.h"
#include <vector>
using namespace std;

template <class T>
Stack<T>::Stack()
{
	size = 0;
}

template <class T>
T Stack<T>::top() const
{
	if (size == 0)
		return 0;
	return DATA[size - 1];
}

template <class T>
void Stack<T>::push(T const& data)
{
	DATA.push_back(data);
	size++;
}