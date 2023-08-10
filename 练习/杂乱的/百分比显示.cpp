#include <iostream>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
	for (int i = 1; i < 101; ++i)
	{
		system("cls");
		std::cout << i << "%" << std::endl;
		Sleep(100);
	}
	return 0;
}