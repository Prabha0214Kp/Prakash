#include<iostream>
using namespace std;

struct test
{
	int x;
	int y;
	char c;
	bool b;
};

int main()
{
	test s;
	s.x=5;
	s.y=20;
	s.c='a';
	s.b=true;

	int *ptr = reinterpret_cast<int*>(&s);
	cout<<*ptr<<endl;

	ptr++;
	cout<<*ptr<<endl;

	ptr++;
	char *c = reinterpret_cast<char*>(ptr);
	cout<<*c<<endl;

	cout<<*(reinterpret_cast<bool*>(++c))<<endl;

	return 0;
}




