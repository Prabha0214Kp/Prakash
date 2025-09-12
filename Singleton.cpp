#include<iostream>
using namespace std;

class Singleton
{
	static int flag;
	static Singleton *ptr;

	Singleton()
	{

	}

	public:

	static Singleton* getinstence();
	void method();

	~Singleton()
	{

	}
};

Singleton* Singleton :: ptr=NULL;
int Singleton :: flag=1;

Singleton* Singleton :: getinstence()
{
	if(!ptr)
	{
		ptr=new Singleton();
		cout<<"Singleton "<<flag<< "obj created"<<endl;
	}
	return ptr;
}

void Singleton :: method()
{
	cout<<"Method of singleton class"<<endl;
}

int main()
{
	Singleton *sc1,*sc2;

	sc1 = Singleton :: getinstence();
	sc1 -> method();

	sc2 = Singleton :: getinstence();
	sc2 -> method();

	return 0;
}


