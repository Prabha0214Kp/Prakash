#include<iostream>
using namespace std;

class test
{
	public:
		void operator()()
		{
			cout<<"Hello World"<<endl;
		}
};

int main()
{
	test t;

	t();

	return 0;
}




