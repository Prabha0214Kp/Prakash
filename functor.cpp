#include<iostream>
using namespace std;

class mul
{
	int _val;

	public:
	mul()
	{
	}

	mul(int val):_val(val)
	{

	}

	int operator()(int val)
	{
		return _val*val;
	}
};

int main()
{
	mul mul2(12);
	cout<<mul2(2)<<endl;
	cout<<mul2(3)<<endl;

	return 0;
}


