#include<iostream>
using namespace std;

class test 
{
	int *ptr;

	public:

	// Constructor
	test(int i = 0) 
	{
		ptr = new int(i);
	}

	// Assignment operator
	test& operator=(const test& t) 
	{
		if (this != &t) 
		{   
			// check for self-assignment
			*ptr = *(t.ptr);
		}
		return *this;
	}

/*	// Destructor
	~test() {
		delete ptr;
	}
*/
	void setvalue(int i) 
	{
		*ptr = i;
	}

	void print() 
	{
		cout << *ptr << endl;
	}
};

int main() 
{
	test t1(5);
	test t2;

	t2 = t1;   // uses operator=

	t1.setvalue(10);

	t2.print();  // prints 5, because deep copy works

	return 0;
}

