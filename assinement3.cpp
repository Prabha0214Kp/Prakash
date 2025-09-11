// wap to assignment operator inherited

#include<iostream>
using namespace std;

class test
{
	public:
		test& operator = (test &a)
		{
			cout<<"Base class assignment operator called"<<endl;
			return *this;
		}
};

class test2 : public test
{

};

int main()
{
	test2 a,b;
	a.test::operator = (b);

	return 0l;
}




