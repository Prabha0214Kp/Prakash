#include <iostream>
#include <string>
using namespace std;

// Product Interface
class Shape 
{
	public:
		virtual void draw() = 0;
		virtual ~Shape() {}
};

// Concrete Products
class Circle : public Shape 
{
	public:
		void draw() override 
		{
			cout << "Drawing Circle" << endl;
		}
};

class Square : public Shape 
{
	public:
		void draw() override 
		{
			cout << "Drawing Square" << endl;
		}
};

// Factory Class
class ShapeFactory 
{
	public:
		static Shape* createShape(const string& type) 
		{
			if (type == "circle") 
				return new Circle();
			else if (type == "square") 
				return new Square();
			else 
				return nullptr;
		}
};

// Client Code
int main() 
{
	Shape* s1 = ShapeFactory::createShape("circle");
	Shape* s2 = ShapeFactory::createShape("square");

	if (s1) s1->draw();
	if (s2) s2->draw();

	delete s1;
	delete s2;

	return 0;
}



