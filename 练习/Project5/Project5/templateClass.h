#pragma once
#include<vector>
#include<iostream>
using namespace std;

template< typename T>
inline T MaxSize(T num1, T num2)
{
	return num1 > num2 ? num1 : num2;
}


template<class T>
class Stack {
public:
	Stack();
	void push(T const &data);
	T top() const;
private:
	int size;
	vector<T> DATA;
};

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