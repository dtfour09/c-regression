#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mux;

void TheadFun(int x)
{
	int sum = 100;
	while (sum--)
	{

		unique_lock<mutex> lock(mux);
		cout << "��ǰ�̣߳�" << x << " ʣ���߳�ʱ�� �� " << sum << 
			"��ǰ�߳�id ��" << this_thread::get_id() << endl;
	}
}


int main()
{
	thread(TheadFun,1).detach();
	thread(TheadFun, 2).detach();
	cout << "���߳̽��� �� " << endl;
	while (1)
	{

	};
	return 0;
}