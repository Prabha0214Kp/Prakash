#include<iostream>
using namespace std;

class Vehicle
{
	public:
		void drive()
		{
			StartEngine();
			stop();
			move();
			checkFuel();
		}

		virtual ~Vehicle()
		{

		}
	protected:
		void StartEngine()
		{
			cout<<"Starting engoine...."<<endl;
		}

		virtual void checkFuel()=0;
		virtual void move()=0;

		void stop()
		{
			cout<<"stopping vehicle"<<endl;
		}
};

class Car : public Vehicle
{
	protected:
		void checkFuel()
		{
			cout<<"Checking petrol in a car"<<endl;
		}

		void move()
		{
			cout<<"Car is moving on 4 wheels"<<endl;
		}
};

class Bike : public Vehicle
{
	protected:
		void checkFuel()
		{
			cout<<"Checking petrol in a bike"<<endl;
		}

		void move()
		{
			cout<<"bike moving 2 wheels"<<endl;
		}
};

class Bus : public Vehicle
{
	protected:
		void checkFuel()
		{
			cout<<"checking petrol in a bus"<<endl;
		}

		void move()
		{
			cout<<"moving bus "<<endl;
		}
};

int main()
{
	Vehicle *c=new Car();
	c->drive();

	Vehicle *b=new Bus();
	b->drive();

	Vehicle *s=new Bus();
	s->drive();

	delete c;
	delete s;
	delete b;

	return 0;
}













