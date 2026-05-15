#include <iostream>

class Shape {
  protected:
	std::string name;
	double perimeter, area;
	static int shapeCount;

  public:
	Shape() : name("unknown"), perimeter(0.0), area(0.0) { shapeCount++; }

	virtual ~Shape() { shapeCount--; }

	virtual void setName(const std::string &name) { this->name = name; }
	virtual std::string getName() const { return name; }

	virtual void setPerimeter(double perimeter) { this->perimeter = perimeter; }
	virtual double getPerimeter() const { return perimeter; }

	virtual void setArea(double area) { this->area = area; }
	virtual double getArea() const { return area; }

	static int getShapeCount() { return shapeCount; }

	virtual void print() const = 0;
};

class Rectangle : public Shape {
  protected:
	static int rectangleCount;

  public:
	Rectangle() : Shape() { rectangleCount++; }

	Rectangle(const std::string &name, double perimeter, double area) : Shape() {
		this->name = name;
		this->perimeter = perimeter;
		this->area = area;
		rectangleCount++;
	}

	~Rectangle() override { rectangleCount--; }

	static int getRectangleCount() { return rectangleCount; }

	void print() const override {
		std::cout << "--- Rectangle Info ---\n";
		std::cout << "Name: " << name << "\n";
		std::cout << "Perimeter: " << perimeter << "\n";
		std::cout << "Area: " << area << "\n";
		std::cout << "Total Shapes: " << getShapeCount() << "\n";
		std::cout << "Total Rectangles: " << getRectangleCount() << "\n";
		std::cout << "----------------------\n";
	}
};

int Shape::shapeCount = 0;
int Rectangle::rectangleCount = 0;
