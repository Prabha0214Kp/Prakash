#include<iostream>
#include<memory>
using namespace std;

class test
{
	public:

	test()
	{
		cout<<"constructor"<<endl;
	}
	~test()
	{
		cout<<"destructor"<<endl;
	}
	
	void fun()
	{
		cout<<"local test member function"<<endl;
	}
};

unique_ptr<test>createobj()
{
	return make_unique<test>();
}

int main()
{
	unique_ptr<test>ptr=createobj();
	ptr->fun();

	return 0;
}





