#include <iostream>
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
	s.x = 5;
	s.y = 20;
	s.c = 'a';
	s.b = true;

	int *ptr = reinterpret_cast<int*>(&s);
	cout << *ptr << endl;   // 5
	ptr++;
	cout << *ptr << endl;   // 20

	ptr++;
	// Correctly access 'c' and 'b'
	char *cp = reinterpret_cast<char*>(ptr);
	cout << *cp << endl;    // a

	bool *bp = reinterpret_cast<bool*>(++cp);
	cout << *bp << endl;    // 1

	return 0;
}


