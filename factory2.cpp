#include <iostream>
#include <memory>
using namespace std;

// Step 1: Create an abstract base class (interface)
class Shape {
	public:
		virtual void draw() = 0;
		virtual ~Shape() = default;
};

// Step 2: Concrete implementations
class Circle : public Shape {
	public:
		void draw() override {
			cout << "Drawing Circle" << endl;
		}
};

class Square : public Shape {
	public:
		void draw() override {
			cout << "Drawing Square" << endl;
		}
};

class Triangle : public Shape {
	public:
		void draw() override {
			cout << "Drawing Triangle" << endl;
		}
};

// Step 3: Factory class
class ShapeFactory {
	public:
		static unique_ptr<Shape> createShape(const string& shapeType) {
			if (shapeType == "circle") {
				return make_unique<Circle>();
			} else if (shapeType == "square") {
				return make_unique<Square>();
			} else if (shapeType == "triangle") {
				return make_unique<Triangle>();
			} else {
				return nullptr;
			}
		}
};

// Step 4: Client code
int main() {
	auto shape1 = ShapeFactory::createShape("circle");
	auto shape2 = ShapeFactory::createShape("square");
	auto shape3 = ShapeFactory::createShape("triangle");

	if (shape1) shape1->draw();
	if (shape2) shape2->draw();
	if (shape3) shape3->draw();

	return 0;
}

