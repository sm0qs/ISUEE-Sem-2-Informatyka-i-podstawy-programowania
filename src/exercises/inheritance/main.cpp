#include <iostream>

class Shape {
  protected:
	std::string name;
	double perimeter, area;
	static int items;

  public:
	Shape() : name("unknown"), perimeter(0.0), area(0.0) { items++; }

	virtual ~Shape() { items--; }

	virtual void setName(const std::string &name) { this->name = name; }
	virtual std::string getName() const { return name; }

	virtual void setPerimeter(double perimeter) { this->perimeter = perimeter; }
	virtual double getPerimeter() const { return perimeter; }

	virtual void setArea(double area) { this->area = area; }
	virtual double getArea() const { return area; }

	static int getItems() { return items; }

	virtual void print() const = 0;
};

int Shape::items = 0;
