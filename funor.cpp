#include<iostream>
using namespace std;

void print(int a)
{
	cout<<a<<endl;
}

void print(char a)
{
	cout<<a<<endl;
}

void print(double a)
{
	cout<<a<<endl;
}

int main()
{
	print(10);
	print('A');
	print(2.5);

	return 0;
}


