#include<iostream>
using namespace std;

class mango
{
	public:
		void eatmango()
		{
			cout<<"eating mango"<<endl;
		}
};

class banana
{
	public:
		void eatbanana()
		{
			cout<<"eating banana"<<endl;
		}
};

int main()
{
	banana *b=new banana();
	mango *m=new mango();

	banana *nb=reinterpret_cast<banana*>(m);
	nb->eatbanana();

	return 0;
}




