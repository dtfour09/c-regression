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
		cout << "当前线程：" << x << " 剩余线程时间 ： " << sum << 
			"当前线程id ：" << this_thread::get_id() << endl;
	}
}


int main()
{
	thread(TheadFun,1).detach();
	thread(TheadFun, 2).detach();
	cout << "主线程结束 ： " << endl;
	while (1)
	{

	};
	return 0;
}