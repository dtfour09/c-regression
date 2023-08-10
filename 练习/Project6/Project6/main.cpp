#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include "answer1.h"
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

const int length = 10;
const string fileName = "./data.txt";

bool nsEnd = false;
queue<int> qu;

mutex mtx;
long long sum = 0;

void squareSum(int start, int end) {
    long long partial_sum = 0;
    for (int i = start; i <= end; i++) {
        partial_sum += i * i;
    }
    unique_lock<mutex> lock(mtx);
    sum += partial_sum;
}

void myProducer(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        {
            unique_lock<mutex> lock(mtx);
            qu.push(i);
        }
    }
    unique_lock<mutex> lock(mtx);
    nsEnd = true;
}

void myConsumer(bool isPrimer)
{
    fstream myFileWrite;
    myFileWrite.open(fileName.c_str(), ios::app);
    while (true)
    {
            unique_lock<mutex> lock(mtx);

            if (!nsEnd)
                continue;
            if (nsEnd && qu.empty())
                break;

            int num = qu.front();
            int nums = sqrt(num);
            bool numIsPrimer = true;
            for (int i = 2; i <= nums; ++i)
            {
                if (num % i == 0)
                {
                    numIsPrimer = false;
                    break;
                }
            }
            if (numIsPrimer == isPrimer)
            {
                qu.pop();
                double numA = (double)num;

                if (isPrimer) {
                    numA *= 10;
                    string str = to_string(numA);
                    cout << str << endl;
                    myFileWrite << str << "\n";
                    myFileWrite.flush();
                }
                else {
                    numA /= 10;
                    string str = to_string(numA);
                    cout << str << endl;
                    myFileWrite << str << "\n";
                    myFileWrite.flush();
                }
            }
            else {
                continue;
            } 
    }
    myFileWrite.close();
}

int main()
{
    ////问题1-1
    //int A[length] = { 2, 5, 8, 2, 7, 6, 3, 1, 9, 4 };
    //
    //int* B = new int[length];
    //copy(A, A + length, B);
    //swapMinAndFirstMaxAndLast(B, length);

    //for (int i = 0; i < length; ++i)
    //    cout << *(B + i) << " ";
    //cout << endl;

    ////排序C
    //int* C = new int[length];
    //copy(A, A + length, C);
    //sort(C, C + length);
    //for (int i = 0; i < length; ++i)
    //    cout << *(C + i) << " ";
    //cout << endl;

    ////问题1-2
    //vector<int> numA = { 0,1,0,3,12 },numB;
    //for (int i = 0; i < numA.size(); ++i)
    //{
    //    if (numA[i] == 0) continue;
    //    numB.push_back(numA[i]);
    //}
    //while (numB.size() < numA.size())
    //{
    //    numB.push_back(0);
    //}
    //for (int i = 0; i < numB.size(); ++i)
    //    cout << numB[i] <<" ";
    //cout << endl;

 
    ////问题2-1
    //int N;
    //cout << "请输入 N : ";
    //cin >> N;

    //int numThreads = thread::hardware_concurrency();
    //vector<thread> threads(numThreads);
    //int chunkSize = N / numThreads;
    //for (int i = 0; i < numThreads; ++i)
    //{
    //    int start = i * chunkSize + 1;
    //    int end = (i == numThreads - 1) ? N : (i + 1) * chunkSize;
    //    threads[i] = thread(squareSum,start,end);
    //}
    //cout << "线程未结束时候的sum " << sum << endl;
    //for (auto& t : threads)
    //{
    //    t.join();
    //}
    //cout << "线程结束时候的sum " << sum << endl;


    //问题2-2 请输入
    cout << "请输入一个范围 L - R :";
    int L, R;
    cin >> L >> R;
    thread producer(myProducer,L,R);
    thread Consumer1(myConsumer, true);
    thread Consumer2(myConsumer, false);
    producer.join();
    Consumer1.join();
    Consumer2.join();

	return 0;
}
