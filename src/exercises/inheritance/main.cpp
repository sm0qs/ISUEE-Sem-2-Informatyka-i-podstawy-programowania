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

class Square : public Rectangle {
  protected:
	static int squareCount;

  public:
	Square() : Rectangle() { squareCount++; }

	Square(const std::string &name, double perimeter, double area)
		: Rectangle(name, perimeter, area) {
		squareCount++;
	}

	~Square() override { squareCount--; }

	static int getSquareCount() { return squareCount; }

	void print() const override {
		std::cout << "--- Square Info ---\n";
		std::cout << "Name: " << name << "\n";
		std::cout << "Perimeter: " << perimeter << "\n";
		std::cout << "Area: " << area << "\n";
		std::cout << "Total Shapes: " << getShapeCount() << "\n";
		std::cout << "Total Rectangles: " << getRectangleCount() << "\n";
		std::cout << "Total Squares: " << getSquareCount() << "\n";
		std::cout << "-------------------\n";
	}
};

int Shape::shapeCount = 0;
int Rectangle::rectangleCount = 0;
int Square::squareCount = 0;

void printTab(Shape **tab, int tabSize) {
	for (int i = 0; i < tabSize; ++i) {
		tab[i]->print();
	}
}

int main() {
	std::cout << "Creating shapes..." << std::endl;

	Rectangle rect("Rectangle", 20.0, 25.0);
	Square sq("Square", 16.0, 16.0);
	Rectangle rect2("Small Rectangle", 10.0, 6.0);

	Shape *tab[3];
	tab[0] = &rect;
	tab[1] = &sq;
	tab[2] = &rect2;
	printTab(tab, 3);

	return 0;
}
