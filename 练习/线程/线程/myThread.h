#pragma once

#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

mutex mtx,mainMtx;
static int mtxNums = 0;

void myThreadMain(int x)
{
	while (true)
	{
		{
			unique_lock<mutex> lock(mtx);
			if (mtxNums != 0)
				continue;
		}


		cerr << "���----" << x << endl;
		Sleep(1000);
	}
	
}

void threadLock()
{
	mainMtx.lock();
	mtxNums++;
	if (mtxNums != 1)
	{
		mtxNums = 1;
		cerr << " �Ѿ��ӹ�����\n" << endl;
	}
	mainMtx.unlock();
}

void threadULock()
{
	mainMtx.lock();
	mtxNums = 0;
	mainMtx.unlock();
}

void threadMenu()
{
	thread ThreadTask1(myThreadMain,1);
	thread ThreadTask2(myThreadMain,2);
	ThreadTask1.detach();
	ThreadTask2.detach();
	while (true)
	{
		int num;
		cerr << "0,�˳�.  1,�̼߳��� . 2, �߳̽���\n"
			 << "������һ�����֣�";
		
		cin >> num;
		if (num == 0)
			break;

		if (num == 1)
		{
			threadLock();
		}

		if (num == 2)
		{
			threadULock();
		}
	}
}


