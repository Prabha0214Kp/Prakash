#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cv;
bool turn=false;

void print1()
{
	unique_lock<mutex>lock(m);
	for(int i=0;i<=5;i++)
	{
		cout<<"thread1 : "<<i<<endl;
	}
	turn=true;
	cv.notify_one();
}

void print2()
{
	unique_lock<mutex>lock(m);
	cv.wait(lock,[]{return turn;});
	for(int i=6;i<=10;i++)
	{
		cout<<"Thread2 : "<<i<<endl;
	}
}

int main()
{
	thread th1(print1);
	thread th2(print2);
	th1.join();
	th2.join();

	return 0;
}



