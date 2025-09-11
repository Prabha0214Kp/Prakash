#include<iostream>
using namespace std;

class test
{
	int *ptr;
	public:

	test(int i=0)
	{
		ptr=new int(i);
	}

	void setvalue(int i)
	{
		*ptr=i;
	}

	void print()
	{
		cout<<*ptr<<endl;
	}

	test& operator = (const test &t)
	{
		if(this != &t)
		{
			*ptr=*(t.ptr);
		}
		return *this;
	}
};

int main()
{
	test t1(5);
	test t2;

	t2=t1;

	t1.setvalue(10);
	t2.print();

	return 0;
}


