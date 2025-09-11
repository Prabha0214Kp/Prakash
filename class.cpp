#include<iostream>
using namespace std;

class test
{
	int a,b;

	void show()
	{
		cout<<"enter the a,b values : ";
		cin>>a>>b;

		cout<<a<<b<<" "<<endl;
	}
};

int main()
{
	test t;
	t.show();

	return 0;
}


